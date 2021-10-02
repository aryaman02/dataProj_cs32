/* helper routines to read out csv data */
#include "parse.h"
#include <algorithm>
#include <cmath>

/* helper to strip out quotes from a string */
string stripQuotes(std::string temp) {
    temp.erase(
        remove(temp.begin(), temp.end(), '\"' ),
        temp.end());
    return temp;
}

/* helper: get field from string stream */
/* assume field has quotes for CORGIS */
string getField(std::stringstream &ss) {
    string data, junk;
    //ignore the first quotes
    std::getline(ss, junk, '\"');
    //read the data (not to comma as some data includes comma (Hospital names))
    std::getline(ss, data, '\"');
    //read to comma final comma (to consume and prep for next)
    std::getline(ss, junk, ',');
    //data includes final quote (see note line 18)
    return stripQuotes(data);
}

string getFieldNQ(std::stringstream &ss)
{
    string temp;
    std::getline(ss, temp, ',');
    //std::cout << temp << std:: endl;
    return temp;
}

/* helper: read out column names for CSV file */
void consumeColumnNames(std::ifstream &myFile) {
    std::string line;
    std::string colname;

    // Extract the first line in the file
    std::getline(myFile, line);

    // Create a stringstream from line
    std::stringstream ss(line);

    // Read the column names (for debugging)
    // Extract each column name for debugging
    while(std::getline(ss, colname, ',')) {
    //    std::cout << colname << std::endl;
    }
}

/* Read one line from a CSV file for county demographic data specifically */
shared_ptr<demogData> readCSVLineDemog(std::string theLine) {
    std::stringstream ss(theLine);
    
    string name = getField(ss);
    string state = getField(ss);

    std::size_t index = name.find(" County");
    if (index != std::string::npos) {
        name = name.substr(0, index) + state;
    } else {
        name = name + state;
    }

    double popOver65 = stod(getField(ss));
    double popUnder18 = stod(getField(ss));
    double popUnder5 = stod(getField(ss));
    //TODO for lab01, when you grab more data modify below loop to make sure you grab 
    //the right field
    double popBADegreeUp = stod(getField(ss));
    double popHSDipUp = stod(getField(ss));

    //now skip over some data
    for (int i=0; i < 4; i++)
        getField(ss);

    //store initial data as percent (then convert to count)
    double FirstNation= stod(getField(ss));
    double Asian= stod(getField(ss));
    double Black= stod(getField(ss));
    double Latinx= stod(getField(ss));
    double HIPacificIsle= stod(getField(ss));
    double MultiRace= stod(getField(ss));
    double White= stod(getField(ss));
    double WhiteNH = stod(getField(ss));

    //now skip over some data 
    for (int i=0; i < 6; i++)
        getField(ss);

    int medHouseIncome = stoi(getField(ss)); //dont use
    //skip per capita
    getField(ss);
    double popBelowPoverty = stod(getField(ss));

    //now skip over some data 
    for (int i=0; i < 10; i++)
        getField(ss);

    int totalPop2014 = stoi(getField(ss));
    
    //update as needed this is lab3 version
    return make_shared<demogData>(name, state, popOver65, popUnder18,
            popUnder5, popBADegreeUp, popHSDipUp, popBelowPoverty, FirstNation, Asian, Black, Latinx, HIPacificIsle, MultiRace, White, 
            WhiteNH, totalPop2014);
}

//read one line of police data
shared_ptr<psData> readCSVLinePolice(std::string theLine) {
    std::stringstream ss(theLine);
    
    getFieldNQ(ss); //ignore id
    string name = getFieldNQ(ss);
    for(int i = 0; i < 3; i++){
        getFieldNQ(ss);
    }
    int age = 0;
    string tmp = getFieldNQ(ss);
    if(tmp != ""){
        age = stoi(tmp);
    }
    else{
        age = -1;
    }
    string gender = getFieldNQ(ss);
    string race = getFieldNQ(ss);
    string county = getFieldNQ(ss);
    string state = getFieldNQ(ss);

    std::string regionName;
    std::size_t index = county.find(" County");
    if (index != std::string::npos) {
        regionName = county.substr(0, index) + state;
    } else {
        regionName = county + state;
    }

    bool signs_of_mental_illness = false;
    string tmp2 = getFieldNQ(ss);

    if (tmp2 == "True") {
        signs_of_mental_illness = true;
    } else {
        signs_of_mental_illness = false;
    }
    getFieldNQ(ss); //ignore threat_level

    string flee = getFieldNQ(ss);


    //finish reading other data fields and initialize police data

    return make_shared<psData>(name, age, gender, race, regionName, state, signs_of_mental_illness, flee);
}

void read_csv(std::vector<shared_ptr<regionData>> &theData, std::string filename, typeFlag fileType) {
    // Create an input filestream
    std::ifstream myFile(filename);

    // Make sure the file is open
    if(!myFile.is_open()) {
        throw std::runtime_error("Could not open file");
    }

    if(myFile.good()) {
        consumeColumnNames(myFile);

        // Helper vars
        std::string line;

        // Now read data, line by line and create demographic dataobject
        while(std::getline(myFile, line)) {
            if (fileType == DEMOG) {
                theData.push_back(readCSVLineDemog(line));
            } else if (fileType == POLICE) {
                theData.push_back(readCSVLinePolice(line));
            } else {
                cout << "ERROR - unknown file type" << endl;
                exit(0);
            }
        }

        // Close file
        myFile.close();
    }
}


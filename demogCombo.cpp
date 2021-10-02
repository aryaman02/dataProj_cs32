#include "demogCombo.h"
#include "demogData.h"
#include <sstream>
#include <string>
#include <assert.h>
#include <iomanip>
#include <math.h> 
#include "visitor.h"

//add member functions here
void demogCombo::accept(class Visitor &v) {}

/* print state data - as aggregate of all the county data */
std::ostream& operator<<(std::ostream &out, const demogCombo& ComboD) {
    out.setf(ios::fixed);
    out.setf(ios::showpoint);
    out.precision(2);
    
    //out << "State Info: " << ComboD.getRegionName() << std::endl;
    //out << "Number of Counties: " << ComboD.numCounties << std::endl;

     /*out << "Combo Info: " << ComboD.printState() << "\n";
     out << "Number of Counties: " << ComboD.numCounties << " County Demographics Info: comboData, " << ComboD.getState() << "\n";

    out << "Population info: " << std::endl;

    double proportion1 = 100.0f*((double)(ComboD.comboPopOver65))/ComboD.getPop();
    out << "(over 65): " << proportion1 << "% and total: " << ComboD.comboPopOver65 << std::endl;

    double proportion2 = 100.0f*((double)(ComboD.comboPopUnder18))/ComboD.getPop();
    out << "(under 18): " << proportion2 << "% and total: " << ComboD.comboPopUnder18 << std::endl;

    double proportion3 = 100.0f*((double)(ComboD.comboPopUnder5))/ComboD.getPop();
    out << "(under 5): " << proportion3 << "% and total: " << ComboD.comboPopUnder5 << std::endl;*/

    /*out << "Education info:" << std::endl;

    double proportion4 = 100.0f*((double)(ComboD.comboPopBDegreeHigher))/ComboD.getPop();
    out << "(Bachelor or more): " << proportion4 << "% and total: " << ComboD.comboPopBDegreeHigher << std::endl;

    double proportion5 = 100.0f*((double)(ComboD.comboPopHSDipHigher))/ComboD.getPop();
    out << "(high school or more): " << proportion5 << "% and total: " << ComboD.comboPopHSDipHigher << std::endl;

    //double proportion6 = 100.0f*((double)(ComboD.comboPopBelowPoverty))/ComboD.getPop();
    //out << "persons below poverty: " << proportion6 << "% and total: " << ComboD.comboPopBelowPoverty << std::endl;

    out << "Total population: " << ComboD.getPop() << std::endl;

    // community racial demographics info
    //out << "community racial demographics: Racial Demographics Info:" << std::endl;

    out << "Racial Demographics Info: " << std::endl;

    double proportion7 = 100.0f*((double)(ComboD.comboPopFirstNation))/ComboD.getPop();
    out << "\% American Indian and Alaska Native percent: " << proportion7 << " count: " << ComboD.comboPopFirstNation << std::endl;

    double proportion8 = 100.0f*((double)(ComboD.comboPopAsian))/ComboD.getPop();
    out << "\% Asian American percent: " << proportion8 << " count: " << ComboD.comboPopAsian << std::endl;

    double proportion9 = 100.0f*((double)(ComboD.comboPopBlack))/ComboD.getPop();
    out << "\% Black/African American percent: " << proportion9 << " count: " << ComboD.comboPopBlack << std::endl;

    double proportion10 = 100.0f*((double)(ComboD.comboPopHispanic))/ComboD.getPop();
    out << "\% Hispanic or Latinx percent: " << proportion10 << " count: " << ComboD.comboPopHispanic << std::endl;

    double proportion11 = 100.0f*((double)(ComboD.comboPopPacificIslander))/ComboD.getPop();
    out << "\% Native Hawaiian and Other Pacific Islander percent: " << proportion11 << " count: " << ComboD.comboPopPacificIslander << std::endl;

    double proportion12 = 100.0f*((double)(ComboD.comboPopMultiRace))/ComboD.getPop();
    out << "\% Two or More Races percent: " << proportion12 << " count: " << ComboD.comboPopMultiRace << std::endl;

    double proportion13 = 100.0f*((double)(ComboD.comboPopWhiteInclusive))/ComboD.getPop();
    out << "\% White (inclusive) percent: " << proportion13 << " count: " << ComboD.comboPopWhiteInclusive << std::endl;

    double proportion14 = 100.0f*((double)(ComboD.comboPopWhiteNonHispanic))/ComboD.getPop();
    out << "\% White (nonHispanic) percent: " << proportion14 << " count: " << ComboD.comboPopWhiteNonHispanic << std::endl;

    out << "total Racial Demographic Count: " << ComboD.getPop() << std::endl;*/

    return out;
}

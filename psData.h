#ifndef POLICE_H
#define POLICE_H

#include <string>
#include <iostream>
#include <utility>
#include "regionData.h"
#include <memory>

using namespace std;

/*
  class to represent police shooting data
  from CORGIS
*/
class psData : public regionData, public std::enable_shared_from_this<psData> {
  public:
    //add appropriate function paramaters to constructor once you add data
    psData(string inName, int inAge, string inGender, string inRace, string inCounty, string inState, bool inIllness, string inFlee) : regionData{inCounty, inState, -1},
    name(inName), age(inAge), gender(inGender), race(inRace), signs_of_mental_illness(inIllness), flee(inFlee) {}

    // getters
    string getName() const { return name; }
    int getAge() const { return age; }
    string getGender() const { return gender; }
    string getRace() const { return race; }
    bool getMentalIllnessInfo() const { return signs_of_mental_illness; }
    string getFlee() const { return flee; }
    

   // virtual functions
   void toString(ostream& os) const {}
   void accept(class Visitor &v) override;

   friend std::ostream& operator<<(std::ostream &out, psData &PD);

private:
    string name;
    int age;
    string gender;
    string race;
    bool signs_of_mental_illness;
    string flee;
    //add others

};

#endif
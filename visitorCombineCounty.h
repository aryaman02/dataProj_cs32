#ifndef VCOMBOC_H
#define VCOMBOC_H

#include "demogCombo.h"
#include "psCombo.h"
#include "visitorCombine.h"
#include "parse.h"
#include <memory>
#include <fstream>
#include <cassert>

class visitorCombineCounty : public visitorCombine {
public:
    visitorCombineCounty() : visitorCombine{} {
    }

    //store demographic data by county name
	void visit(shared_ptr<demogData> d) override {
        std::string countyName = d->getRegionName();
        allComboDemogData[countyName] = make_shared<demogCombo>(countyName, 1, d->getPop());
        allComboDemogData[countyName]->addState(d->getState());

        allComboDemogData[countyName]->updateOver65Count(d->getOver65Count());
        allComboDemogData[countyName]->updateUnder18Count(d->getUnder18Count());
        allComboDemogData[countyName]->updateUnder5Count(d->getUnder5Count());
        allComboDemogData[countyName]->updateBAupCount(d->getpopBAupCount());
        allComboDemogData[countyName]->updateHSupCount(d->getpopHSupCount());
        allComboDemogData[countyName]->updateBelowPovertyCount(d->getpopBelowPovertyCount());

        allComboDemogData[countyName]->updateFirstNationCount(d->getpopFirstNationCount());
        allComboDemogData[countyName]->updateAsianCount(d->getpopAsianCount());
        allComboDemogData[countyName]->updateBlackCount(d->getpopBlackCount());
        allComboDemogData[countyName]->updateHispanicCount(d->getpopHispanicCount());
        allComboDemogData[countyName]->updatePacificIslanderCount(d->getpopPacificIslanderCount());
        allComboDemogData[countyName]->updateMultiRaceCount(d->getpopMultiRaceCount());
        allComboDemogData[countyName]->updateWhiteInclusiveCount(d->getpopWhiteInclusiveCount());
        allComboDemogData[countyName]->updateWhiteNonHispanicCount(d->getpopWhiteNonHispanicCount());
    }
    
    //aggregate police shooting data by county
    void visit(shared_ptr<psData> ps) override {
        std::string countyName = ps->getRegionName();

        if (allComboPoliceData.find(countyName) == allComboPoliceData.end()) {
            int ageOfVictim = ps->getAge();
            int ageOver65Count = 0, age19To64Count = 0, ageUnder18Count = 0;
            if (ageOfVictim > 65) {
                ageOver65Count = 1;
            } else if (ageOfVictim >= 19 && ageOfVictim <= 64) {
                age19To64Count = 1;
            } else if (ageOfVictim < 18) {
                ageUnder18Count = 1;
            }

            string fleeStatus = ps->getFlee();
            int fleeCount;
            if (fleeStatus != "" && fleeStatus != "Not fleeing") {
                fleeCount = 1;
            } else {
                fleeCount = 0;
            }

            bool isMentallyI = ps->getMentalIllnessInfo();
            int mentalICount;
            if (isMentallyI) {
                mentalICount = 1;
            } else {
                mentalICount = 0;
            }

            string gender = ps->getGender();
            int maleCount = 0, femaleCount = 0;
            if (gender == "M") {
                maleCount = 1;
            } else if (gender == "F") {
                femaleCount = 1;
            }

            string race = ps->getRace();
            int firstNationCount = 0, asianCount = 0, blackCount = 0, hispanicCount = 0, whiteCount = 0, otherCount = 0;
            if (race == "N") {
                firstNationCount = 1;
            } else if (race == "A") {
                asianCount = 1;
            } else if (race == "B") {
                blackCount = 1;
            } else if (race == "H") {
                hispanicCount = 1;
            } else if (race == "W") {
                whiteCount = 1;
            } else if (race == "O" || race == "") {
                otherCount = 1;
            } 

            allComboPoliceData[countyName] = make_shared<psCombo>(countyName, 1, ageOver65Count, age19To64Count, ageUnder18Count, fleeCount, mentalICount, 
            maleCount, femaleCount);
            allComboPoliceData[countyName]->addState(ps->getState());

            allComboPoliceData[countyName]->updateComboFirstNationCount(firstNationCount);
            allComboPoliceData[countyName]->updateComboAsianCount(asianCount);
            allComboPoliceData[countyName]->updateComboBlackCount(blackCount);
            allComboPoliceData[countyName]->updateComboHispanicCount(hispanicCount);
            allComboPoliceData[countyName]->updateComboWhiteCount(whiteCount);
            allComboPoliceData[countyName]->updateComboOtherCount(otherCount);

        } else {
            allComboPoliceData[countyName]->setPop(allComboPoliceData[countyName]->getPop() + 1);

            int ageOfVictim = ps->getAge();
            if (ageOfVictim > 65) {
                allComboPoliceData[countyName]->updateCasesOver65();
            } else if (ageOfVictim >= 19 && ageOfVictim <= 64) {
                allComboPoliceData[countyName]->updateCases19To64();
            } else if (ageOfVictim < 18) {
                allComboPoliceData[countyName]->updateCasesUnder18();
            }

            string fleeStatus = ps->getFlee();
            if (fleeStatus != "" && fleeStatus != "Not fleeing") {
                allComboPoliceData[countyName]->updateFleeingCount();
            }

            bool isMentallyI = ps->getMentalIllnessInfo();
            if (isMentallyI) {
                allComboPoliceData[countyName]->updateNumMentalI();
            }

            string gender = ps->getGender();
            if (gender == "M") {
                allComboPoliceData[countyName]->updatenumMales();
            } else if (gender == "F") {
                allComboPoliceData[countyName]->updatenumFemales();
            }

            string race = ps->getRace();
            if (race == "N") {
                allComboPoliceData[countyName]->updateComboFirstNationCount(1);
            } else if (race == "A") {
                allComboPoliceData[countyName]->updateComboAsianCount(1);
            } else if (race == "B") {
                allComboPoliceData[countyName]->updateComboBlackCount(1);
            } else if (race == "H") {
                allComboPoliceData[countyName]->updateComboHispanicCount(1);
            } else if (race == "W") {
                allComboPoliceData[countyName]->updateComboWhiteCount(1);
            } else if (race == "O" || race == "") {
                allComboPoliceData[countyName]->updateComboOtherCount(1);
            }
        } 
    }

    private:
        //only inherited data at this point
};

#endif

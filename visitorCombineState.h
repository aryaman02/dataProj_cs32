#ifndef VCOMBOS_H
#define VCOMBOS_H

#include "demogCombo.h"
#include "psCombo.h"
#include "visitorCombine.h"
#include <memory>

class visitorCombineState : public visitorCombine {
public:
    visitorCombineState() : visitorCombine{} {}

	void visit(shared_ptr<demogData> d) override {
        std::string stateAbbrev = d->getState();

        if (allComboDemogData.find(stateAbbrev) == allComboDemogData.end()) {
            allComboDemogData[stateAbbrev] = make_shared<demogCombo>(stateAbbrev, 1, d->getPop());
            allComboDemogData[stateAbbrev]->addState(d->getState());

        } else {
            allComboDemogData[stateAbbrev]->updateNumCounties();
            allComboDemogData[stateAbbrev]->setPop(allComboDemogData[stateAbbrev]->getPop() + d->getPop());
        }

        allComboDemogData[stateAbbrev]->updateOver65Count(d->getOver65Count());
        allComboDemogData[stateAbbrev]->updateUnder18Count(d->getUnder18Count());
        allComboDemogData[stateAbbrev]->updateUnder5Count(d->getUnder5Count());
        allComboDemogData[stateAbbrev]->updateBAupCount(d->getpopBAupCount());
        allComboDemogData[stateAbbrev]->updateHSupCount(d->getpopHSupCount());
        allComboDemogData[stateAbbrev]->updateBelowPovertyCount(d->getpopBelowPovertyCount());

        allComboDemogData[stateAbbrev]->updateFirstNationCount(d->getpopFirstNationCount());
        allComboDemogData[stateAbbrev]->updateAsianCount(d->getpopAsianCount());
        allComboDemogData[stateAbbrev]->updateBlackCount(d->getpopBlackCount());
        allComboDemogData[stateAbbrev]->updateHispanicCount(d->getpopHispanicCount());
        allComboDemogData[stateAbbrev]->updatePacificIslanderCount(d->getpopPacificIslanderCount());
        allComboDemogData[stateAbbrev]->updateMultiRaceCount(d->getpopMultiRaceCount());
        allComboDemogData[stateAbbrev]->updateWhiteInclusiveCount(d->getpopWhiteInclusiveCount());
        allComboDemogData[stateAbbrev]->updateWhiteNonHispanicCount(d->getpopWhiteNonHispanicCount());
    }
    
    void visit(shared_ptr<psData> ps) override {
        std::string stateAbbrev = ps->getState();

        if (allComboPoliceData.find(stateAbbrev) == allComboPoliceData.end()) {
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

            allComboPoliceData[stateAbbrev] = make_shared<psCombo>(stateAbbrev, 1, ageOver65Count, age19To64Count, ageUnder18Count, fleeCount, mentalICount, 
            maleCount, femaleCount);
            allComboPoliceData[stateAbbrev]->addState(ps->getState());

            allComboPoliceData[stateAbbrev]->updateComboFirstNationCount(firstNationCount);
            allComboPoliceData[stateAbbrev]->updateComboAsianCount(asianCount);
            allComboPoliceData[stateAbbrev]->updateComboBlackCount(blackCount);
            allComboPoliceData[stateAbbrev]->updateComboHispanicCount(hispanicCount);
            allComboPoliceData[stateAbbrev]->updateComboWhiteCount(whiteCount);
            allComboPoliceData[stateAbbrev]->updateComboOtherCount(otherCount);

        } else {
            allComboPoliceData[stateAbbrev]->setPop(allComboPoliceData[stateAbbrev]->getPop() + 1);

            int ageOfVictim = ps->getAge();
            if (ageOfVictim > 65) {
                allComboPoliceData[stateAbbrev]->updateCasesOver65();
            } else if (ageOfVictim >= 19 && ageOfVictim <= 64) {
                allComboPoliceData[stateAbbrev]->updateCases19To64();
            } else if (ageOfVictim < 18) {
                allComboPoliceData[stateAbbrev]->updateCasesUnder18();
            }

            string fleeStatus = ps->getFlee();
            if (fleeStatus != "" && fleeStatus != "Not fleeing") {
                allComboPoliceData[stateAbbrev]->updateFleeingCount();
            }

            bool isMentallyI = ps->getMentalIllnessInfo();
            if (isMentallyI) {
                allComboPoliceData[stateAbbrev]->updateNumMentalI();
            }

            string gender = ps->getGender();
            if (gender == "M") {
                allComboPoliceData[stateAbbrev]->updatenumMales();
            } else if (gender == "F") {
                allComboPoliceData[stateAbbrev]->updatenumFemales();
            }

            string race = ps->getRace();
            if (race == "N") {
                allComboPoliceData[stateAbbrev]->updateComboFirstNationCount(1);
            } else if (race == "A") {
                allComboPoliceData[stateAbbrev]->updateComboAsianCount(1);
            } else if (race == "B") {
                allComboPoliceData[stateAbbrev]->updateComboBlackCount(1);
            } else if (race == "H") {
                allComboPoliceData[stateAbbrev]->updateComboHispanicCount(1);
            } else if (race == "W") {
                allComboPoliceData[stateAbbrev]->updateComboWhiteCount(1);
            } else if (race == "O" || race == "") {
                allComboPoliceData[stateAbbrev]->updateComboOtherCount(1);
            }
        } 
    }

    private:
       //inherited
};

#endif

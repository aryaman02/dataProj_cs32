#ifndef POLICECOMBODATA_H
#define POLICECOMBODATA_H

#include "regionData.h"
#include "psData.h"
#include "raceDemogData.h"
#include <memory>
#include <cassert>

using namespace std;

class psCombo : public regionData  {
public:
    psCombo(std::string comboKey, int inCases, int inCases65, int inCases19to64, int inCases18, int inFlee, int inMentalI, int inMale, int inFemale) : 
    regionData{comboKey, "", inCases}, comboOver65(inCases65), combo19To64(inCases19to64), comboUnder18(inCases18), comboFleeingCount(inFlee), 
    comboMentalIllnessCount(inMentalI), comboNumMaleCases(inMale), comboNumFemaleCases(inFemale) {}
    
    // getters
    int getCasesOver65() const { return comboOver65; }
    int getCases19To64() const { return combo19To64; }
    int getCasesUnder18() const { return comboUnder18; }
    int getFleeingCount() const { return comboFleeingCount; }
    int getNumMentalI() const { return comboMentalIllnessCount; }
    int getnumMales() const { return comboNumMaleCases; }
    int getnumFemales() const { return comboNumFemaleCases; }

    int getComboFirstNationCount() const { return racialPSData.getFirstNationCount(); }
    int getComboAsianCount() const { return racialPSData.getAsianCount(); }
    int getComboBlackCount() const { return racialPSData.getBlackCount(); }
    int getComboHispanicCount() const { return racialPSData.getLatinxCount(); }
    int getComboPacificIslanderCount() const { return racialPSData.getHIPacificIsleCount(); }
    int getComboMultiRaceCount() const { return racialPSData.getMultiRaceCount(); }
    int getComboWhiteInclusiveCount() const { return racialPSData.getWhiteCount(); }
    int getComboWhiteNonHispanicCount() const { return racialPSData.getWhiteNHCount(); }
    int getComboOtherCount() const { return racialPSData.getOtherCount(); }

    //int getComboCasesRacialCount() { return comboCasesRacial; }

    // setters to update these aggregated count fields as necessary
    void updateCasesOver65() { comboOver65++; }
    void updateCases19To64() { combo19To64++; }
    void updateCasesUnder18() { comboUnder18++; }
    void updateFleeingCount() { comboFleeingCount++; }
    void updateNumMentalI() { comboMentalIllnessCount++; }
    void updatenumMales() { comboNumMaleCases++; }
    void updatenumFemales() { comboNumFemaleCases++; }

    void updateComboFirstNationCount(int inNum) { racialPSData.addFirstNationCount(inNum); }
    void updateComboAsianCount(int inNum) { racialPSData.addAsianCount(inNum); }
    void updateComboBlackCount(int inNum) { racialPSData.addBlackCount(inNum); }
    void updateComboHispanicCount(int inNum) { racialPSData.addLatinxCount(inNum); }
    void updateComboWhiteCount(int inNum) { racialPSData.addWhiteCount(inNum); racialPSData.addWhiteNHCount(inNum); }
    void updateComboOtherCount(int inNum) { racialPSData.addOtherCount(inNum); }

    //void updateComboCasesRacialCount(int racialCount) { comboCasesRacial += racialCount; }


    int getNumberOfCases() const { return this->getPop(); }

    raceDemogData getRacialData() const { return racialPSData; }

    void toString(ostream& os) const {}

    void accept(class Visitor &v) override;

    friend std::ostream& operator<<(std::ostream &out, const psCombo& PD);

private:
    int comboOver65;
    int combo19To64;
    int comboUnder18;
    int comboFleeingCount;
    int comboMentalIllnessCount;
    int comboNumMaleCases;
    int comboNumFemaleCases;

    raceDemogData racialPSData;
};

#endif
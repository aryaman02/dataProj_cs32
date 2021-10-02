#ifndef DEMOG_H
#define DEMOG_H

#include <string>
#include<iostream>
#include "regionData.h"
#include "raceDemogData.h"
#include <memory>
#include <math.h>

using namespace std;

/*
  class to represent county demographic data
  from CORGIS - LAB01 starter - replace with your FULL version!
*/

class demogData : public regionData, public std::enable_shared_from_this<demogData> {
  public:
      demogData(string inN, string inS, double in65, double in18,
        double in5, double popBDegreeUp, double popHSup, double popBelowPov, double inNative, double inAsian, double inBlack, double inHispanic, 
        double inPacific, double inTwoRace, double inWhiteInc, double inWhiteNonHis, int totPop14) : regionData{inN, inS, totPop14}, popOver65(in65), 
        popUnder18(in18), popUnder5(in5), popWithBDegree(popBDegreeUp), popWithHSDip(popHSup), popBelowPoverty(popBelowPov), 
        popFirstNation(inNative), popAsian(inAsian), popBlack(inBlack), popHispanic(inHispanic), popPacificIslander(inPacific), 
        popMultiRace(inTwoRace), popWhiteInclusive(inWhiteInc), popWhiteNonHispanic(inWhiteNonHis), comboOver65Count(0), comboUnder18Count(0), comboUnder5Count(0), 
        comboBAupCount(0), comboHSupCount(0), comboBelowPovertyCount(0) {}

    // below are getters returning the population numbers that meet a certain criteria (ex. # of people who are under 18)

    int getOver65Count() const { return std::round((popOver65/100.0 * population)); }
    int getUnder18Count() const { return std::round((popUnder18/100.0 * population));; }
    int getUnder5Count() const { return std::round((popUnder5/100.0 * population)); }
    int getpopBAupCount() const { return std::round((popWithBDegree/100.0 * population)); }
    int getpopHSupCount() const { return std::round((popWithHSDip/100.0 * population)); }
    int getpopBelowPovertyCount() const { return std::round((popBelowPoverty/100.0 * population)); }

    int getpopFirstNationCount() const { return std::round((popFirstNation/100.0 * population)); }
    int getpopAsianCount() const { return std::round((popAsian/100.0 * population)); }
    int getpopBlackCount() const { return std::round((popBlack/100.0 * population)); }
    int getpopHispanicCount() const { return std::round((popHispanic/100.0 * population)); }
    int getpopPacificIslanderCount() const { return std::round((popPacificIslander/100.0 * population)); }
    int getpopMultiRaceCount() const { return std::round((popMultiRace/100.0 * population)); }
    int getpopWhiteInclusiveCount() const { return std::round((popWhiteInclusive/100.0 * population)); }
    int getpopWhiteNonHispanicCount() const { return std::round((popWhiteNonHispanic/100.0 * population)); }

    
    // getters returning the aggregated counts of each demog data field for a particular regional criteria

    int getpopOver65Count() const { return comboOver65Count; }
	  int getpopUnder18Count() const { return comboUnder18Count; }
	  int getpopUnder5Count() const { return comboUnder5Count; }
	  int getBAupCount() const { return comboBAupCount; }
  	int getHSupCount() const { return comboHSupCount; }
    int getBelowPovertyCount() const { return comboBelowPovertyCount; }
	
    int getFirstNationCount() const { return racialDemogData.getFirstNationCount(); }
	  int getAsianCount() const { return racialDemogData.getAsianCount(); }
	  int getBlackCount() const { return racialDemogData.getBlackCount(); }
	  int getHispanicCount() const { return racialDemogData.getLatinxCount(); }
    int getPacificIslanderCount() const { return racialDemogData.getHIPacificIsleCount(); }
    int getMultiRaceCount() const { return racialDemogData.getMultiRaceCount(); }
    int getWhiteInclusiveCount() const { return racialDemogData.getWhiteCount(); }
    int getWhiteNonHispanicCount() const { return racialDemogData.getWhiteNHCount(); }

    // getters returning percentages of each aggregated demog data field

    double getBAup() const { return 100.0f*((double)(comboBAupCount))/this->getPop(); }
    double getHSup() const { return 100.0f*((double)(comboHSupCount))/this->getPop(); }
    double getpopOver65() const { return 100.0f*((double)(comboOver65Count))/this->getPop(); }
    double getpopUnder18() const { return 100.0f*((double)(comboUnder18Count))/this->getPop(); }
    double getpopUnder5() const { return 100.0f*((double)(comboUnder5Count))/this->getPop(); }
    double getBelowPoverty() const { return 100.0f*((double)(comboBelowPovertyCount))/this->getPop(); }

    double getFirstNation() const { return 100.0f*((double)(racialDemogData.getFirstNationCount()))/this->getPop(); }
    double getAsian() const { return 100.0f*((double)(racialDemogData.getAsianCount()))/this->getPop(); }
    double getBlack() const { return 100.0f*((double)(racialDemogData.getBlackCount()))/this->getPop(); }
    double getHispanic() const { return 100.0f*((double)(racialDemogData.getLatinxCount()))/this->getPop(); }
    double getPacificIslander() const { return 100.0f*((double)(racialDemogData.getHIPacificIsleCount()))/this->getPop(); }
    double getMultiRace() const { return 100.0f*((double)(racialDemogData.getMultiRaceCount()))/this->getPop(); }
    double getWhiteInclusive() const { return 100.0f*((double)(racialDemogData.getWhiteCount()))/this->getPop(); }
    double getWhiteNonHispanic() const { return 100.0f*((double)(racialDemogData.getWhiteNHCount()))/this->getPop(); }
    
    raceDemogData getCommunityRaceMix() const { return racialDemogData; }

    void toString(ostream& os) const {}
    void accept(class Visitor &v) override;

    friend std::ostream& operator<<(std::ostream &out, const demogData &DD);

// data fields representing csv demog data percentages
private:
    double popOver65;
    double popUnder18;
    double popUnder5;
    double popWithBDegree;
    double popWithHSDip;
    double popBelowPoverty;

    double popFirstNation;
    double popAsian;
    double popBlack;
    double popHispanic;
    double popPacificIslander;
    double popMultiRace;
    double popWhiteInclusive;
    double popWhiteNonHispanic;

// inheritable data fields representing aggregated counts of each demog data field
protected:
    int comboOver65Count;
    int comboUnder18Count;
    int comboUnder5Count;
    int comboBAupCount;
    int comboHSupCount;
    int comboBelowPovertyCount;

    raceDemogData racialDemogData;
};
#endif

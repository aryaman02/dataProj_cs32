#ifndef COMBODEMOG_H
#define COMBODEMOG_H

#include <memory>
#include <string>
#include <iostream>
#include "demogData.h"
#include "raceDemogData.h"
/*
  class to represent combined demographic data 
*/

class demogCombo : public demogData {
  public:
      // constructor
      demogCombo(std::string comboKey, int numOfCounties, int comboPop) : demogData{comboKey, "", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, comboPop},  
          numCounties(numOfCounties) {}

      // getters
      int getNumCounties() { return numCounties; }
      
      // setters to update these aggregated count fields as necessary
      void updateNumCounties() { numCounties++; }
      void updateOver65Count(int inOver65) { comboOver65Count += inOver65; }
      void updateUnder18Count(int inUnder18) { comboUnder18Count += inUnder18; }
      void updateUnder5Count(int inUnder5) { comboUnder5Count += inUnder5; }
      void updateBAupCount(int inBAup) { comboBAupCount += inBAup; }
      void updateHSupCount(int inHSup) { comboHSupCount += inHSup; }
      void updateBelowPovertyCount(int inBelowPoverty) { comboBelowPovertyCount += inBelowPoverty; }

      void updateFirstNationCount(int inFirstNation) { racialDemogData.addFirstNationCount(inFirstNation); }
	    void updateAsianCount(int inAsian) { racialDemogData.addAsianCount(inAsian); }
	    void updateBlackCount(int inBlack) { racialDemogData.addBlackCount(inBlack); }
	    void updateHispanicCount(int inHispanic) { racialDemogData.addLatinxCount(inHispanic); }
      void updatePacificIslanderCount(int inPacificIslander) { racialDemogData.addHIPacificIsleCount(inPacificIslander); }
      void updateMultiRaceCount(int inMultiRace) { racialDemogData.addMultiRaceCount(inMultiRace); }
      void updateWhiteInclusiveCount(int inWhiteInclusive) { racialDemogData.addWhiteCount(inWhiteInclusive); }
      void updateWhiteNonHispanicCount(int inWhiteNonHispanic) { racialDemogData.addWhiteNHCount(inWhiteNonHispanic); }

      void toString(ostream& os) const {}

      void accept(class Visitor &v) override;
          
      friend std::ostream& operator<<(std::ostream &out, const demogCombo &SD);

private:
    // data fields representing aggregated counts given a combo key
    int numCounties;
};
#endif

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include "demogData.h"
#include "parse.h"
#include "regionData.h"
#include "visitorCombineState.h"
#include "visitorCombineCounty.h"
#include "stats.h"
#include "statTool.h"
#include "tddFuncs.h"

using namespace std;

int main() {
    cout << "State data Pop under 18 and below poverty: " << endl;

    std::vector<shared_ptr<regionData>> pileOfData;

    //read police shooting data
    read_csv(pileOfData, "police_shootings_cleaned.csv", POLICE);
   
    //read in the demographic data
    read_csv(pileOfData, "county_demographics.csv", DEMOG); 
    
    //use visitor pattern to be able to aggregate
    visitorCombineState theStates;
    visitorCombineCounty theCounties;

    statTool::createStateData(pileOfData, theStates);
    statTool::createCountyData(pileOfData, theCounties);


    /*// Question 3 - worksheet
    statTool::computeStatsDemogRegionData(&theStates, &demogData::getpopUnder18, &demogData::getBelowPoverty, &demogData::getpopUnder18Count, 
    &demogData::getBelowPovertyCount);

    statTool::computeStatsDemogRegionData(&theCounties, &demogData::getpopUnder18, &demogData::getBelowPoverty, &demogData::getpopUnder18Count, 
    &demogData::getBelowPovertyCount);

    statTool::computeStatsDemogRegionData(&theStates, &demogData::getBelowPoverty, &demogData::getHSup, &demogData::getBelowPovertyCount, 
    &demogData::getHSupCount);

    statTool::computeStatsDemogRegionData(&theCounties, &demogData::getBelowPoverty, &demogData::getHSup, &demogData::getBelowPovertyCount, 
    &demogData::getHSupCount);*/

    // Question 4 - worksheet
    //statTool::computeStatsPSData(&theCounties, &psCombo::getNumMentalI, &psCombo::getComboWhiteNonHispanicCount);
    //statTool::computeStatsPSData(&theCounties, &psCombo::getNumMentalI, &psCombo::getComboBlackCount);

    //statTool::computeStatsMixRegionData(&theCounties, &demogCombo::getpopUnder18Count, &psCombo::getCasesUnder18);
    //statTool::computeStatsMixRegionData(&theCounties, &demogCombo::getPop, &psCombo::getNumberOfCases);

    // Question 5 - worksheet
    //statTool::computeStatsRaceProportion(&theCounties, &raceDemogData::getWhiteNHCount, &raceDemogData::getWhiteNHCount);
    //statTool::computeStatsRaceProportion(&theCounties, &raceDemogData::getBlackCount, &raceDemogData::getBlackCount);

    //statTool::computeStatsRaceProportion(&theStates, &raceDemogData::getWhiteNHCount, &raceDemogData::getWhiteNHCount);
    //statTool::computeStatsRaceProportion(&theStates, &raceDemogData::getBlackCount, &raceDemogData::getBlackCount);
    //statTool::computeStatsRaceProportion(&theStates, &raceDemogData::getLatinxCount, &raceDemogData::getLatinxCount);
    //statTool::computeStatsRaceProportion(&theStates, &raceDemogData::getFirstNationCount, &raceDemogData::getFirstNationCount);
    //statTool::computeStatsRaceProportion(&theStates, &raceDemogData::getAsianCount, &raceDemogData::getAsianCount);

    return 0;
}


#include <iomanip>
#include "psCombo.h"
#include "visitor.h"

void psCombo::accept(class Visitor &v) {}

/* print state data - as aggregate of all incidents in this state */
std::ostream& operator<<(std::ostream &out, const psCombo& PD) {
    /*out << "State Info: " << PD.printState();
    out << "\nNumber of incidents: " << PD.getPop();
    out << std::setprecision(2) << std::fixed;

   //out << "**Police shooting incidents:State Info: " << PD.getRegionName();
    //out << "\nNumber of incidents: " << PD.getPop();
    out << "\nIncidents with age \n(over 65): " << PD.comboOver65 << " \%: " << (100.0f*(double)(PD.comboOver65) / PD.getPop());
    out << "\n(19 to 64): " << PD.combo19To64 << " \%: " << (100.0f*(double)(PD.combo19To64) / PD.getPop());
    out << "\n(under 18): " << PD.comboUnder18 << " \%: " << (100.0f*(double)(PD.comboUnder18) / PD.getPop());
    out << "\nIncidents involving fleeing: " << PD.comboFleeingCount << " \%: " << (100.0f*(double)(PD.comboFleeingCount) / PD.getPop());
    out << "\nIncidents involving mental illness: " << PD.comboMentalIllnessCount << " \%: " << (100.0f*(double)(PD.comboMentalIllnessCount) / PD.getPop());
    out << "\nMale incidents: " << PD.comboNumMaleCases << " female incidents: " << PD.comboNumFemaleCases;
    out << "\nRacial demographics of state incidents: Racial Demographics Info:";

    //out.precision(2);

    out << "\n\% American Indian and Alaska Native";
    if (PD.comboFirstNationCount > 0)
        out << " percent: " << (100.0f*(double)(PD.comboFirstNationCount) / PD.comboCasesRacial);
    out << " count: " << PD.comboFirstNationCount;
    out << "\n\% Asian American";
    if (PD.comboAsianCount > 0)
        out << " percent: " << (100.0f*(double)(PD.comboAsianCount) / PD.comboCasesRacial);
    out << " count: " <<  PD.comboAsianCount;
    out << "\n\% Black/African American";
    if (PD.comboBlackCount > 0)
        out << " percent: " << (100.0f*(double)(PD.comboBlackCount) / PD.comboCasesRacial);
    out << " count: " << PD.comboBlackCount;
    out << "\n\% Hispanic or Latinx";
    if (PD.comboHispanicCount > 0)
        out << " percent: " << (100.0f*(double)(PD.comboHispanicCount) / PD.comboCasesRacial);
    out << " count: " << PD.comboHispanicCount;
    out << "\n\% Native Hawaiian and Other Pacific Islander";
    if (PD.comboPacificIslanderCount > 0)
        out << " percent: " << (100.0f*(double)(PD.comboPacificIslanderCount) / PD.comboCasesRacial);
    out << " count: " << PD.comboPacificIslanderCount;
    out << "\n\% Two or More Races";
    if (PD.comboMultiRaceCount > 0)
        out << " percent: " << (100.0f*(double)(PD.comboMultiRaceCount) / PD.comboCasesRacial);
    out << " count: " << PD.comboMultiRaceCount;
    out << "\n\% White (inclusive)";
    if (PD.comboWhiteInclusiveCount > 0)
        out << " percent: " << (100.0f*(double)(PD.comboWhiteInclusiveCount) / PD.comboCasesRacial);
    out << " count: " << PD.comboWhiteInclusiveCount;
    out << "\n\% White (nonHispanic)";
    if (PD.comboWhiteNonHispanicCount > 0)
        out << " percent: " << (100.0f*(double)(PD.comboWhiteNonHispanicCount) / PD.comboCasesRacial);
    out << " count: " << PD.comboWhiteNonHispanicCount;
    if (PD.comboOtherCount > 0) {
      out << "\n\% Other";
      out << " percent: " << (100.0f*(double)(PD.comboOtherCount) / PD.comboCasesRacial);
      out << " count: " << PD.comboOtherCount;
    }
    out << "\ntotal Racial Demographic Count: " << PD.comboCasesRacial << "\n";*/

    return out;
}
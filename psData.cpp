#include <sstream>
#include "psData.h"
#include "visitor.h"
/* print police data - fill in*/

void psData::accept(class Visitor &v) {
    v.visit(shared_from_this());
}

std::ostream& operator<<(std::ostream &out, const psData &PD) {
    /*out << "Police Shotting Info: " << PD.state;
    out << "\nPerson name: " ;
    out << "\nAge: " ;
    out << "\nGender: " ;
    out << "\nRace:" ;
    out << "\nMental Illness:" ;
    out << "\nFleeing:" ;*/
    return out;
}

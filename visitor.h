#ifndef VISITOR_H
#define VISITOR_H

#include "psCombo.h"
#include "demogCombo.h"
#include "demogData.h"
#include "psData.h"
#include <memory>
/* a visitor can visit any of my specific data types */

class Visitor {
  public:
    virtual void visit(shared_ptr<psData> ps) = 0;
    virtual void visit(shared_ptr<demogData> d) = 0;
};
#endif


#ifndef VISITREP_H
#define VISITREP_H

#include "psData.h"
#include "demogData.h"
#include "visitor.h"
#include <memory>

class visitorReport : public Visitor {
public:
    visitorReport() : numVisited(0) {}

	void visit(shared_ptr<demogData> d) override {
        //fill in
    }
    
    void visit(shared_ptr<psData> ps) override {
        //fill in
    }

    private:
    	int numVisited;
};

#endif
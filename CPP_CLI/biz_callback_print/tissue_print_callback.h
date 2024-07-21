/**
 * Produced by Bruce from Korea
 * Since 2024.07
*/

#include "callback/tissue_traverse_callback.h"
#include "callback/dna_traverse_callback.h"

#pragma once

class TissuePrintCallback : public TissueTraverseNucleusCallback
{
private:

public:
    TissuePrintCallback(DnaTraverseCallback& callback) : TissueTraverseNucleusCallback(callback) {}
    ~TissuePrintCallback() = default;

    void process(Cell* cell) override{
        cout<< "Name:" <<cell->getTag() << "\tID:" << cell->getID() <<endl;

        TissueTraverseNucleusCallback::process(cell);
        cout << endl;
    }    
};

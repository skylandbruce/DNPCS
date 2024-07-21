/**
 * Produced by Bruce from Korea
 * Since 2024.07
*/

#include "callback/tissue_traverse_callback.h"
#include "dna_ostream_callback.h"

#pragma once

class TissueOStreamCallback : public TissueTraverseNucleusCallback
{
private:
    ostringstream* oss = NULL;

public:
    TissueOStreamCallback(DnaOStreamCallback& callback) : TissueTraverseNucleusCallback(callback) {}
    ~TissueOStreamCallback() {}

    void setOSS(ostringstream* oss) { this->oss = oss; } 

    void process(Cell* cell) override{
        if (oss != NULL) {
            *oss << ";" << cell->getTag() << "_" << cell->getID();
        } 
        else {
#ifdef DEBUG_PRINT_
            cout << "error! : oss is NULL" << endl;
#endif
            return;
        }
        TissueTraverseNucleusCallback::process(cell);
    }    
};

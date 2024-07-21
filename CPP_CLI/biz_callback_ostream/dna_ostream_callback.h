/**
 * Produced by Bruce from Korea
 * Since 2024.07
*/

#include "callback/dna_traverse_callback.h"
#include "gene_ostream_callback.h"

#pragma once

class DnaOStreamCallback : public DnaTraverseCallback
{
private:
    ostringstream* oss;

public:
    DnaOStreamCallback(GeneOStreamCallback& callback) : DnaTraverseCallback(callback)  {}
    ~DnaOStreamCallback() {}

    void setOSS(ostringstream* oss) { this->oss = oss; }

    Gene process(const string& key, Gene& data) {
        if(data.getTag() == "PositionCurrent"){
            DnaTraverseCallback::process(key, data);
        }
        return data;
    }
};
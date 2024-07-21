/**
 * Produced by Bruce from Korea
 * Since 2024.07
*/

#include "callback/gene_traverse_callback.h"

#include <sstream>

#pragma once 

class GeneOStreamCallback : public GeneTraverseCallback<int>
{
private:
    ostringstream* oss;

public:
    GeneOStreamCallback() = default;
    ~GeneOStreamCallback() = default;

    void setOSS(ostringstream* oss) { this->oss = oss; }
    int process(const string& key, int& data) override { 
        *oss<< ":" << data;
        return 0;
    }
};

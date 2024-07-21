/**
 * Produced by Bruce from Korea
 * Since 2024.07
*/

#include "callback/gene_traverse_callback.h"

#pragma once 

class GenePrintCallback : public GeneTraverseCallback<int>
{
private:

public:
    GenePrintCallback() = default;
    ~GenePrintCallback() = default;

    int process(const string& key, int& data) override { 
        cout<< key <<":" << data << " ";
        return 0;
    }
};

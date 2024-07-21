/**
 * Produced by Bruce from Korea
 * Since 2024.07
*/

#include "callback/dna_traverse_callback.h"
#include "callback/gene_traverse_callback.h"
#pragma once

class DnaPrintCallback : public DnaTraverseCallback
{
private:

public:
    DnaPrintCallback(GeneTraverseCallback<int>& callback) : DnaTraverseCallback(callback)  {}
    ~DnaPrintCallback() = default;

    Gene process(const string& key, Gene& data) {
        cout<< data.getTag() << ": ";
        DnaTraverseCallback::process(key, data);
        cout<< "\t";
        return data;
    }
};
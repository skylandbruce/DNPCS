/**
 * Produced by Bruce from Korea
 * Since 2024.07
*/

#include "callback/organ_traverse_callback.h"
#include "tissue_ostream_callback.h"
#include "dna_ostream_callback.h"
#include "gene_ostream_callback.h"

#pragma once

class OrganOStreamCallback : public OrganTraverseCallback
{
private:
        ostringstream* oss;

        GeneOStreamCallback cascadeGene;
        DnaOStreamCallback cascadeDna;
        TissueOStreamCallback cascadeTissue;

public:
    OrganOStreamCallback() : OrganTraverseCallback(cascadeTissue), cascadeTissue(cascadeDna), cascadeDna(cascadeGene) {}
    ~OrganOStreamCallback() {}

    void setOSS(ostringstream* oss) { 
        this->oss = oss; 
        cascadeTissue.setOSS(oss);
        cascadeDna.setOSS(oss);
        cascadeGene.setOSS(oss);
    }

};

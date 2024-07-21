/**
 * Produced by Bruce from Korea
 * Since 2024.07
*/

#include "callback/tissues_traverse_callback.h"
#include "tissue_ostream_callback.h"
#include "dna_ostream_callback.h"
#include "gene_ostream_callback.h"

#pragma once

class TissuesOStreamCallback : public TissuesTraverseCallback
{
private:
        ostringstream* oss;

        GeneOStreamCallback cascadeGene;
        DnaOStreamCallback cascadeDna;
        TissueOStreamCallback cascadeTissue;

public:
    TissuesOStreamCallback() : TissuesTraverseCallback(cascadeTissue), cascadeTissue(cascadeDna), cascadeDna(cascadeGene) {}
    ~TissuesOStreamCallback() {}

    void setOSS(ostringstream* oss) { 
        this->oss = oss; 
        cascadeTissue.setOSS(oss);
        cascadeDna.setOSS(oss);
        cascadeGene.setOSS(oss);
    }

};

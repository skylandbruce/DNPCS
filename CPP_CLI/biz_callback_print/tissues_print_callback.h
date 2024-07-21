/**
 * Produced by Bruce from Korea
 * Since 2024.07
*/

#include "callback/tissues_traverse_callback.h"
#include "tissue_print_callback.h"
#include "dna_print_callback.h"
#include "gene_print_callback.h"

#pragma once

class TissuesPrintCallback : public TissuesTraverseCallback
{
private:
    GenePrintCallback cascadeGene;
    DnaPrintCallback cascadeDna;
    TissuePrintCallback cascadeTissue;

public:
    TissuesPrintCallback() : TissuesTraverseCallback(cascadeTissue), cascadeTissue(cascadeDna), cascadeDna(cascadeGene) {}
    ~TissuesPrintCallback() {}
};
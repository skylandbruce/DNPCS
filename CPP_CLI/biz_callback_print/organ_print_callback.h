/**
 * Produced by Bruce from Korea
 * Since 2024.07
*/

#include "callback/organ_traverse_callback.h"
#include "tissue_print_callback.h"
#include "dna_print_callback.h"
#include "gene_print_callback.h"

#pragma once

class OrganPrintCallback : public OrganTraverseCallback
{
private:
        GenePrintCallback cascadeGene;
        DnaPrintCallback cascadeDna;
        TissuePrintCallback cascadeTissue;

public:
    OrganPrintCallback() : OrganTraverseCallback(cascadeTissue), cascadeTissue(cascadeDna), cascadeDna(cascadeGene) {}
    ~OrganPrintCallback() {}

};

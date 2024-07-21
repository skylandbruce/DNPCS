/**
 * Produced by Bruce from Korea
 * Since 2024.07
*/

#include "pch.h"
#include "snow.h"

void Snow::design()
{
    dnaSteadyRandomVariant.setPosition(100, 50, 20);

    VectorHerizontal vectorH;
    VectorVertical vectorV;
    VectorDepth vectorD;
    Vector vector;
    vector += vectorH * 5;
    vector += vectorV * 5;

    Variant variant;
    variant += vectorH * 20;
    variant += vectorV * 10;
    variant += vectorD * 1;

    dnaSteadyRandomVariant.setGene(vector);
    dnaSteadyRandomVariant.setGene(variant);

}

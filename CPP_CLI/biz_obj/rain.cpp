/**
 * Produced by Bruce from Korea
 * Since 2024.07
*/

#include "pch.h"
#include "rain.h"

void Rain::design()
{
    dnaSteadyRandom.setPosition(500,50,1);

    VectorHerizontal vectorH;
    VectorVertical vectorV;
    VectorDepth vectorD;
    Vector vector;

    vector += vectorH * -5;
    vector += vectorV * 30;
    vector += vectorD * 3;

    dnaSteadyRandom.setGene(vector);

}

/**
 * Produced by Bruce from Korea
 * Since 2024.07
*/

#include "pch.h"
#include "star.h"

void Star::design()
{
    dnaSteady.setPosition(50, 350, 20);
    VectorHerizontal vectorH;
    Vector vector;
    vector += vectorH*2;
    dnaSteady.setGene(vector);
}

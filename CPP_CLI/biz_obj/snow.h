/**
 * Produced by Bruce from Korea
 * Since 2024.07
*/

#include "genom/cell.h"
#include "reserved_info/reserved_dna.h"

#pragma once

class Snow : public PresetCell
{
private:
    string tag = "Snow";
    DnaSteadyRandomVariant dnaSteadyRandomVariant;

protected:
    virtual void design();

public:
    Snow() { design(); }
    ~Snow() = default;

    string& getBizTag() override { return tag; }
    NucleusTrait& getPositonTrait() override { return dnaSteadyRandomVariant; }
    int getLimitOfDuplication() override { return 50; }
    int getPeriodOfTransplant() override { return 3; }
    int getCountOfTransplant() override { return 1; }
};

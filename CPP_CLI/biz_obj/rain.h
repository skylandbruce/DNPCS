/**
 * Produced by Bruce from Korea
 * Since 2024.07
*/

#include "genom/cell.h"
#include "reserved_info/reserved_dna.h"

#pragma once

class Rain : public PresetCell
{
private:
    string tag = "Rain";
    DnaSteadyRandom dnaSteadyRandom;

protected:
    virtual void design();

public:
    Rain(){ design(); }
    ~Rain() = default;
    
    string& getBizTag() override { return tag; }
    NucleusTrait& getPositonTrait() override { return dnaSteadyRandom; }
    int getLimitOfDuplication() override { return 50; }
    int getPeriodOfTransplant() override { return 1; }
    int getCountOfTransplant() override { return 1; }
};


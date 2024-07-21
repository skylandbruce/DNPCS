/**
 * Produced by Bruce from Korea
 * Since 2024.07
*/

#include "genom/cell.h"
#include "reserved_info/reserved_dna.h"
#pragma once

class Star : public PresetCell
{
private:
    string tag = "Star";
    DnaSteadyBlink dnaSteady;

protected:
    virtual void design();
                
public:
    Star() { design(); }
    ~Star() = default;

    string& getBizTag() override { return tag; }
    NucleusTrait& getPositonTrait() override { return dnaSteady; }
    int getLimitOfDuplication() override { return 3; }
    int getPeriodOfTransplant() override { return 60; }
    int getCountOfTransplant() override { return 1; }
};


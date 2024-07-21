/**
 * Produced by Bruce from Korea
 * Since 2024.07
*/

#include "manager/callback_thread_interface.h"
#include "callback/tissue_modification_callback.h"

#pragma once

class Transplantation : public InterfaceCallbackThread {
private:
    Tissue specimen;
    TissueModificationCallback callback;    

    int tickCount = 1;
public:
    void onAwake(Tissues& tissues, Organ& organ) override {

        tickCount ++;
        if (tickCount >= std::numeric_limits<int>::max()) {
            tickCount = 1;
        }
#ifdef DEBUG_PRINT_
        cout << "Thread Transplantation is awake!: " <<endl;
#endif
        tissues.extractParts(specimen, tickCount);

        // Generate VecorSteadyRandom's vector for new specimen
        specimen.traverseTissue(callback);

        if(specimen.getSize() > 0)    
            organ.culture(specimen);
    }
};

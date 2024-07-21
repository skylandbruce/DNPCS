/**
 * Produced by Bruce from Korea
 * Since 2024.07
*/

#include "manager/callback_thread_interface.h"
#include "utill/boundary.h"
#ifdef DEBUG_PRINT_
#include "../biz_callback_print/organ_print_callback.h"
#endif
#include "../biz_callback_ostream/organ_ostream_callback.h"

#pragma once
#include <functional>

    /// @brief autonomic nervous system
    class ANS : public InterfaceCallbackThread {
    private:
        Tissue specimen;
        Boundary boundary{ 10, 600, 10, 800, 0, 40 };
#ifdef DEBUG_PRINT_
        OrganPrintCallback callbackPrint;
#endif    
        OrganOStreamCallback callbackOStream;
        ostringstream* oss;

    public:
        ANS() {
            if(oss == NULL) oss = new ostringstream();
            callbackOStream.setOSS(oss); 
        }
        
        ANS(ostringstream* oss) {
            this->oss = oss;
            callbackOStream.setOSS(oss);
        }

        ~ANS() { 
            delete oss;
        }

        const string& getStream(){
            return oss->str();
        }

        void onAwake(Tissues& tissues, Organ& organ) override {
#ifdef DEBUG_PRINT_
            cout << "Thread ANS is awake!:" << endl;
#endif
            for (int depth = 0; depth < organ.getSize(); depth++) {

                Tissue* tissue = organ.get(depth);

                for (int i = 0; i < tissue->getSize(); i++) {
                    Cell& cell = *tissue->extraction();

                    cell.pulsation();

                    Gene& geneCurrent = cell.getPosition();
                    if (!boundary.isWithinBoundary(geneCurrent)) {
#ifdef DEBUG_PRINT_
                        cout << "Regen: " << cell.getTag() << "\tz: " << geneCurrent.get<int>("z") << endl;
#endif
                        tissues.regen(cell);
                    }
                    else {
                        specimen.injection(&cell);
                    }
                }
            }
            organ.culture(specimen);
#ifdef DEBUG_PRINT_
            organ.traverseOrgan(callbackPrint);
#endif        
            organ.traverseOrgan(callbackOStream);

#ifdef DEBUG_MSG_        
            cout << oss->str() << endl;
#endif      
        }
    };

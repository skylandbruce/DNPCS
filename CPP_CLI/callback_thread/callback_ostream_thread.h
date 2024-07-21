#include "manager/callback_thread_interface.h"
#include "../biz_callback_ostream/organ_ostream_callback.h"

class OStream : public InterfaceCallbackThread {
private:
    ostringstream* oss;
    OrganOStreamCallback callbackOStream;

public:
    OStream() { 
        oss = new ostringstream();
        callbackOStream.setOSS(oss); 
    }

    void onAwake(Tissues& tissues, Organ& organ) override {
        organ.traverseOrgan(callbackOStream);
#ifdef DEBUG_MSG_        
        cout<< oss.str() <<endl;
#endif
        oss->str("");
    }
};
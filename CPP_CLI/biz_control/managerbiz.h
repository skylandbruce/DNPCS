/**
 * Produced by Bruce from Korea
 * Since 2024.07
*/

#include "manager/manager.h"

#include "../biz_obj/snow.h"
#include "../biz_obj/rain.h"
#include "../biz_obj/star.h"

#include "../callback_thread/callback_ans_thread.h"
#include "../callback_thread/callback_transplantation_thread.h"

#include "../biz_callback_ostream/tissues_ostream_callback.h"

#ifdef DEBUG_PRINT_
#include "../biz_callback_print/tissues_print_callback.h"
#endif 

#pragma once

class ManagerBiz : public Manager
{
private:
// Define Biz Obects
    Star star;
    Rain rain;
    Snow snow;

// Define Threads
    Transplantation* transplantation;
    ANS* ans;

// Output stream buffer
    ostringstream* oss;


// Stream callback
    TissuesOStreamCallback callbackOStreamTissues;

public:
    ManagerBiz(ostringstream* oss) : oss(oss), Manager(40) {
        initBizObj();
        transplantation = new Transplantation();
        ans = new ANS(oss);

#ifdef DEBUG_PRINT_
            TissuesPrintCallback callbackPrintTissues;
            traverseTissues(callbackPrintTissues);
#endif
    }

    ~ManagerBiz() {
        delete transplantation;
        delete ans;
    }

    void initBizObj() {
        registProto(star);
        dupProto(star);

        registProto(rain);
        dupProto(rain);
        
        registProto(snow);
        dupProto(snow);
    }
#ifdef THREAD_MANAGER_SUPPORT
    void initThread() { 
        ManagerThread::createThread(transplantation, 300);
        ManagerThread::createThread(ans, 300);
    }
#else
    void heartBeat() {
        Manager::heartBeat(*transplantation);
        Manager::heartBeat(*ans);
    }
#endif

    void getOStreamTissues(ostringstream* oss){
        callbackOStreamTissues.setOSS(oss);
        Manager::traverseTissues(callbackOStreamTissues);
    }

};
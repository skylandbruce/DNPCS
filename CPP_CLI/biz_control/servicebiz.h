/**
 * Produced by Bruce from Korea
 * Since 2024.07
*/

#include "../predefine/predefine.h"
#include "service/service.h"
#include "managerbiz.h"

#pragma once

    class ServiceBiz : public Service
    {
    private:
        ostringstream* ossTissues = new ostringstream();
        ostringstream* ossOrgan = new ostringstream();
        ManagerBiz* managerBiz = new ManagerBiz(ossOrgan);

    protected:

    public:
        ServiceBiz() : Service(*managerBiz) {}
        ~ServiceBiz() {
            delete managerBiz;
            delete ossTissues;
            delete ossOrgan;
        }

        ostringstream* getTissuesStream() {
            managerBiz->getOStreamTissues(ossTissues);
            return ossTissues;
        }

        ostringstream* getOrganStream() {
            return ossOrgan;
        }
#ifdef THREAD_MANAGER_SUPPORT
        void startThread() {
            managerBiz->initThread();
            managerBiz->start();
            
        }
        void stopThread() {
            managerBiz->stopThread();

        }

        void resumeThread() {
            managerBiz->resume();
        }

        void pauseThread() {
            managerBiz->pause();
        }
#else
        void heartBeat() {
            managerBiz->heartBeat();
        }

#endif 
    };
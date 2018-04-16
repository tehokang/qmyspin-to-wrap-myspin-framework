#ifndef __QTHREAD_H__
#define __QTHREAD_H__

#include "Thread.h"
#include <queue>
using namespace std;

class QueueThread : public Thread {
public:
  QueueThread() { } ;
  virtual ~QueueThread() { };

protected:
  queue<void*> m_msg_queue;
};


#endif
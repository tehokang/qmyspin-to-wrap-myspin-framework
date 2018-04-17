#ifndef __QUEUE_THREAD_H__
#define __QUEUE_THREAD_H__

#include "Thread.h"
#include <queue>
#include <mutex>
using namespace std;

class QueueThread : public Thread {
public:
  QueueThread(unsigned int max_queue_count=20)
    : Thread()
    , m_max_queue_count(max_queue_count) {

  }
  virtual ~QueueThread() { };

  virtual bool pushMsg(void *msg) {
    m_locker.lock();

    if ( m_max_queue_count < m_msg_queue.size() ) {
      m_locker.unlock();
      return false;
    }
    m_msg_queue.push(msg);

    m_locker.unlock();
    return true;
  }

  virtual void* popMsg() {
    m_locker.lock();

    void *msg = nullptr;
    if ( m_msg_queue.empty() == false ) {
      msg = m_msg_queue.front();
      m_msg_queue.pop();
    }

    m_locker.unlock();
    return msg;
  }

protected:
  mutex m_locker;
  queue<void*> m_msg_queue;
  const unsigned int m_max_queue_count;
};


#endif
// Copyright 2014 Google Inc. All Rights Reserved.
#include "Thread.h"
#include <stdio.h>

void* Thread::callback(void* arg) {
    Thread* thread = static_cast<Thread*>(arg);
    thread->run();
    return nullptr;
}

Thread::~Thread() {
    if ( m_running ) {
        fprintf(stdout, "Thread %lx went out of scope while running!\n", (unsigned long) m_thread);
    }
}

bool Thread::start() {
    int ret = 0;
    ret = pthread_create(&m_thread, nullptr, callback, this);
    m_running = (ret == 0);
    fprintf(stdout, "Thread created [%d] \n", m_running);
    return m_running;
}

bool Thread::join() {
    m_running = false;

    int ret = pthread_join(m_thread, nullptr);
    if (ret == 0) {
        return true;
    }
    return false;
}

unsigned long Thread::id() {
    return (unsigned long) m_thread;
}

void Thread::yield() {
    sched_yield();
}

bool Thread::setPriority(int priority) {
    struct sched_param params;
    params.sched_priority = priority;
    int ret = pthread_setschedparam(m_thread, SCHED_FIFO, &params);
    return ret == 0;
}

bool Thread::setName(const char* name) {
#if defined(__APPLE__) && defined(__MACH__) || defined(__MINGW32__)
    // OSX doesn't support naming a particular thread and only supports naming
    // the current thread.
    return false;
#else
    return pthread_setname_np(m_thread, name) == 0;
#endif
}

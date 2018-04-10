#ifndef __PROJECTION_HANDLER_H__
#define __PROJECTION_HANDLER_H__

#include <list>
using namespace std;

class ProjectionListener
{
public:
    virtual void onReqSend(unsigned char *buffer, unsigned int size) = 0;
    virtual void onReqReceive(unsigned char *buffer, unsigned int size) = 0;
    virtual void onError(int error) = 0;
    virtual void onFrameUpdated(unsigned char *buffer, unsigned int size) = 0;
};

class ProjectionHandler
{
public:
    ProjectionHandler();
    virtual ~ProjectionHandler();

    virtual bool init() = 0;
    virtual bool start() = 0;
    virtual void stop() = 0;
    virtual bool sendKey(int key, int press) = 0;
    virtual bool sendTouch(unsigned int x, unsigned int y, int finger, int action) = 0;

    void addEventListener(ProjectionListener *listener);
    void removeEventListener(ProjectionListener *listener);

    list<ProjectionListener*> m_listeners;
};

#endif
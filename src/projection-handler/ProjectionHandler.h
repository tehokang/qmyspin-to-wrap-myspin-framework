#ifndef __PROJECTION_HANDLER_H__
#define __PROJECTION_HANDLER_H__

using namespace std;

class ProjectionListener
{
public:
    virtual bool onReqSend(unsigned char *buffer, unsigned int size) = 0;
    virtual bool onReqReceive(unsigned char *buffer, unsigned int size) = 0;
    virtual void onError(int error) = 0;
    virtual void onFrameUpdated(unsigned char *buffer, unsigned int size) = 0;
};

class ProjectionHandler
{
public:
    ProjectionHandler();
    virtual ~ProjectionHandler();

    virtual bool init();
    virtual bool start();
    virtual void stop();
    virtual bool sendKey(int key, int press);
    virtual bool sendTouch(unsigned int x, unsigned int y, int finger, int action);

    void setEventListener(ProjectionListener *listener);

protected:
    ProjectionListener* m_listener;
};

#endif
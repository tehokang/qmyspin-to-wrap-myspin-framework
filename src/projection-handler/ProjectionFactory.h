#ifndef __PROJECTION_FACTORY_H__
#define __PROJECTION_FACTORY_H__

#include <list>
using namespace std;

class ProjectionHandler;

class ProjectionFactory
{
public:
  typedef enum {
    MYSPIN,
    SDL,
    ABALTA,
    CINEMO,
  } ProjectionType;

  static ProjectionHandler& createProjection(ProjectionType type);
  static void destroyProjection(ProjectionType type);

protected:
  static ProjectionHandler *m_myspin_handler;
  static ProjectionHandler *m_abalta_handler;
  static ProjectionHandler *m_sdl_handler;
  static ProjectionHandler *m_cinemo_handler;
  static ProjectionHandler *m_unknown_handler;

private:
  ProjectionFactory();
  ~ProjectionFactory();
};

#endif
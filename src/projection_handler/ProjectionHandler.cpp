#include "ProjectionHandler.h"

ProjectionHandler::ProjectionHandler() {
  /**
   * @note NOTHING TO DO
   */
}

ProjectionHandler::~ProjectionHandler() {
  /**
   * @note NOTHING TO DO
   */
}

void ProjectionHandler::addEventListener(ProjectionListener *listener) {
  for (list<ProjectionListener*>::iterator it=m_listeners.begin(); it!=m_listeners.end(); ++it)  {
    if ( listener == (*it) )
    {
      return;
    }
  }
  m_listeners.push_back(listener);
}

void ProjectionHandler::removeEventListener(ProjectionListener *listener) {
  for (list<ProjectionListener*>::iterator it=m_listeners.begin(); it!=m_listeners.end(); ++it)  {
    if ( listener == (*it) )
    {
      m_listeners.remove(*it);
    }
  }

}
#include "ProjectionFactory.h"
#include "ProjectionHandler.h"
#include "myspin/mySPINHandler.h"
#include "cinemo/CinemoHandler.h"
#include "abalta/AbaltaHandler.h"
#include "sdl/SdlHandler.h"

ProjectionHandler *ProjectionFactory::m_myspin_handler = nullptr;
ProjectionHandler *ProjectionFactory::m_abalta_handler = nullptr;
ProjectionHandler *ProjectionFactory::m_sdl_handler = nullptr;
ProjectionHandler *ProjectionFactory::m_cinemo_handler = nullptr;
ProjectionHandler *ProjectionFactory::m_unknown_handler = nullptr;

ProjectionHandler& ProjectionFactory::createProjection(
    ProjectionFactory::ProjectionType type) {

  switch ( type ) {
    case ProjectionFactory::ProjectionType::eMYSPIN:
      if ( m_myspin_handler == nullptr ) {
        m_myspin_handler = new MySPINHandler();
      }
      return *m_myspin_handler;
    case ProjectionFactory::ProjectionType::eCINEMO:
      if ( m_cinemo_handler == nullptr ) {
        m_cinemo_handler = new CinemoHandler();
      }
      return *m_cinemo_handler;
    case ProjectionFactory::ProjectionType::eABALTA:
      if ( m_abalta_handler == nullptr ) {
        m_abalta_handler = new AbaltaHandler();
      }
      return *m_abalta_handler;
    case ProjectionFactory::ProjectionType::eSDL:
      if ( m_sdl_handler == nullptr ) {
        m_sdl_handler = new SdlHandler();
      }
      return *m_sdl_handler;
    default:
      if ( m_unknown_handler == nullptr ) {
        m_unknown_handler = new ProjectionHandler();
      }
      break;
  }
  return *m_unknown_handler;
}

void ProjectionFactory::destroyProjection(
    ProjectionFactory::ProjectionType type) {

  switch ( type ) {
    case ProjectionFactory::ProjectionType::eMYSPIN:
      if ( m_myspin_handler != nullptr ) {
        delete m_myspin_handler;
        m_myspin_handler = nullptr;
      }
      break;
    case ProjectionFactory::ProjectionType::eCINEMO:
      if ( m_cinemo_handler != nullptr ) {
        delete m_cinemo_handler;
        m_cinemo_handler = nullptr;
      }
      break;
    case ProjectionFactory::ProjectionType::eABALTA:
      if ( m_abalta_handler != nullptr ) {
        delete m_abalta_handler;
        m_abalta_handler = nullptr;
      }
      break;
    case ProjectionFactory::ProjectionType::eSDL:
      if ( m_sdl_handler != nullptr ) {
        delete m_sdl_handler;
        m_sdl_handler = nullptr;
      }
      break;
    default:
      if ( m_unknown_handler != nullptr ) {
        delete m_unknown_handler;
        m_unknown_handler = nullptr;
      }
      break;
  }
}


ProjectionFactory::ProjectionFactory() {
  /**
   * @note NOTHING TO DO
   */
}

ProjectionFactory::~ProjectionFactory() {
  /**
   * @note NOTHING TO DO
   */
}

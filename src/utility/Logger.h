#ifndef __LOGGER_H__
#define __LOGGER_H__

#include <stdio.h>
#include <string>
#include <string.h>
#include <pthread.h>

using namespace std;

#include "Logger.h"

#if defined(CONFIG_DEBUG)
#if defined(USE_HXLOG)
/* USE-CASE of HxLOG Humax octo LOGGER */
#define LOG_DEBUG PLATFORM_LOG_DEBUG
#define LOG_INFO PLATFORM_LOG_INFO
#define LOG_WARNING PLATFORM_LOG_WARNING
#define LOG_ERROR PLATFORM_LOG_ERROR
#define LOG_KEY PLATFORM_LOG_KEY
#define PASSED PLATFORM_LOG_PASSED
#define CONSUMED PLATFORM_LOG_CONSUMED

#define REMOTE_DEBUG PLATFORM_REMOTE_DEBUG
#define REMOTE_INFO PLATFORM_REMOTE_INFO
#define REMOTE_WARNING PLATFORM_REMOTE_WARNING
#define REMOTE_ERROR PLATFORM_REMOTE_ERROR
#else

/* USE-CASE of LOGGER */
#define LOG_DEBUG(fmt, ...) Logger::debug \
        (__SHORT_FILE__, __LINE__, __FUNCTION__, fmt, ##__VA_ARGS__);
#define LOG_INFO(fmt, ...)  Logger::info \
        (__SHORT_FILE__, __LINE__, __FUNCTION__, fmt, ##__VA_ARGS__);
#define LOG_WARNING(fmt, ...) Logger::warning \
        (__SHORT_FILE__, __LINE__, __FUNCTION__, fmt, ##__VA_ARGS__);
#define LOG_ERROR(fmt, ...) Logger::error \
        (__SHORT_FILE__, __LINE__, __FUNCTION__, fmt, ##__VA_ARGS__);
#define LOG_KEY(fmt, ...) Logger::debug \
        (__SHORT_FILE__, __LINE__, __FUNCTION__, fmt, ##__VA_ARGS__);
#define PASSED(fmt, ...) Logger::passed \
        (__SHORT_FILE__, __LINE__, __FUNCTION__, fmt, ##__VA_ARGS__);
#define CONSUMED(fmt, ...) Logger::consumed \
        (__SHORT_FILE__, __LINE__, __FUNCTION__, fmt, ##__VA_ARGS__);

#define REMOTE_DEBUG LOG_DEBUG
#define REMOTE_INFO LOG_INFO
#define REMOTE_WARNING LOG_WARNING
#define REMOTE_ERROR LOG_ERROR

#endif

#else
#define LOG_DEBUG(fmt, ...)
#define LOG_INFO(fmt, ...)
#define LOG_WARNING(fmt, ...)
#define LOG_ERROR(fmt, ...)
#define LOG_KEY(fmt, ...)
#define PASSED(fmt, ...)
#define CONSUMED(fmt, ...)

#define REMOTE_DEBUG(fmt, ...)
#define REMOTE_INFO(fmt, ...)
#define REMOTE_WARNING(fmt, ...)
#define REMOTE_ERROR(fmt, ...)
#endif

class Logger
{
public:
    enum LOG_TYPE
    {
        DEBUG,
        INFO,
        ERROR,
        WARNING,
        KEY_CONSUMED,
        KEY_PASSED,

    };

    static void setLogLevel(bool info, bool debug, bool warn, bool error, \
                        bool filewrite = false, unsigned int filesize = 5 * 1024 * 1024, \
                        string rootpath = "/mnt/hd2/", string log_filename_prefix="noname");

    static void info(const string filename, const unsigned int linenumber, \
                        const string funcname, const string format, ...);

    static void debug(const string filename, const unsigned int linenumber, \
                        const string funcname, const string format, ...);

    static void warning(const string filename, const unsigned int linenumber, \
                        const string funcname, const string format, ...);

    static void error(const string filename, const unsigned int linenumber, \
                        const string funcname, const string format, ...);

    static void consumed(const string filename, const unsigned int linenumber, \
                        const string funcname, const string format, ...);

    static void passed(const string filename, const unsigned int linenumber, \
                        const string funcname, const string format, ...);

protected:
    /**
     * @warning DO NOT CREATE Logger INSTANCE
     **/
    Logger();
    ~Logger();

    static string getDate();
    static string getLogTypeString(LOG_TYPE logtype);

    static void __log__(LOG_TYPE logtype, FILE *out,
            const string msg_prefix, const string msg);

    static void __save_logfile__(const string msg_prefix, const string msg);

    static pthread_mutex_t m_filelogging_mutex;
    static bool m_info;
    static bool m_debug;
    static bool m_warning;
    static bool m_error;
    static bool m_filewrite;
    static int m_filesize;

    enum
    {
        MAX_PREFIX_LEN = 256,
        MAX_MSG_LEN = 4*1024,
    };

    static FILE *m_log_fp;
    static string m_log_filename;
    static string m_log_filename_prefix;;
    static string m_log_rootpath;
    static bool m_use_date;
};

#endif

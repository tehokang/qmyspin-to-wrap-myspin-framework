#ifndef __LOGGER_H__
#define __LOGGER_H__

#include <stdio.h>
#include <string>
#include <string.h>
#include <pthread.h>

using namespace std;

#include "Logger.h"

#define __SHORT_FILE__ \
(strrchr(__FILE__,'/') \
? strrchr(__FILE__,'/')+1 \
: __FILE__ )

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

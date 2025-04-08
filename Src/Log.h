/**
 * @file Log.h
 * @author Ali Mirghasemi (ali.mirghasemi1376@gmail.com)
 * @brief This is Log header library for using for debugging and print log in applications
 * @version 0.1
 * @date 2025-04-08
 *
 * @copyright Copyright (c) 2025
 *
 */
#ifndef _LOG_H_
#define _LOG_H_

#define LOG_VER_MAJOR    0
#define LOG_VER_MINOR    1
#define LOG_VER_FIX      0

/************************************************************************/
/*                            Configuration                             */
/************************************************************************/
/**
 * @brief If you need to change log level in runtime you can enable this feature
 */
#define LOG_DYNAMIC_LEVEL                       0

#if !defined(LOG_LEVEL) && LOG_DYNAMIC_LEVEL == 0
    /**
     * @brief Select Log level for debugging
     */
    #define LOG_LEVEL                           LOG_LEVEL_TRACE
#endif

#ifndef LOG_PRINT
    /**
     * @brief Rename which function used to print, function must support printf input styles
     * void printf(const char* fmt, ...);
     */
    #define LOG_PRINT                           printf
#endif

#ifndef LOG_FMT
    /**
     * @brief Specify log header format
     */
    #define LOG_FMT(LVL, FILE, LINE)            "[" #LVL " - " #FILE ":" #LINE "] "
#endif
/************************************************************************/
#define __LOG_VER_STR(major, minor, fix)        #major "." #minor "." #fix
#define _LOG_VER_STR(major, minor, fix)         __LOG_VER_STR(major, minor, fix)
/**
 * @brief show version in string format
 */
#define LOG_VER_STR                             _LOG_VER_STR(LOG_VER_MAJOR, LOG_VER_MINOR, LOG_VER_FIX)
/**
 * @brief show version in integer format, ex: 0.2.0 -> 200
 */
#define LOG_VER                                 ((LOG_VER_MAJOR * 10000UL) + (LOG_VER_MINOR * 100UL) + (LOG_VER_FIX))

/* Check for include stdio */
#if LOG_PRINT == printf
    #include <stdio.h>
#endif
/* Log Levels */
#define LOG_LEVEL_NONE                          0
#define LOG_LEVEL_ERROR                         1
#define LOG_LEVEL_WARN                          2
#define LOG_LEVEL_INFO                          3
#define LOG_LEVEL_DEBUG                         4
#define LOG_LEVEL_TRACE                         5
/* Dynamic Log Level */
#if LOG_DYNAMIC_LEVEL
    static unsigned char LOG_LEVEL = LOG_LEVEL_TRACE;
#endif
/**
 * @brief Print log with specify level
 *
 * @param LVL Log Level: NONE, ERROR, WARN, INFO, DEBUG, TRACE
 * @param FMT Format of log
 * @param Arguments
 */
#define logPrint(LVL, FMT, ...) \
if (LOG_LEVEL_ ##LVL <= LOG_LEVEL) { \
    LOG_PRINT(__LOG_FMT(LVL, __FILE__, __LINE__) FMT, ##__VA_ARGS__); \
}
/**
 * @brief Print log with ERROR level
 *
 * @param FMT Format of log
 * @param Arguments
 */
#define logError(FMT, ...)                          logPrint(ERROR, FMT, ##__VA_ARGS__)
/**
 * @brief Print log with WARN level
 *
 * @param FMT Format of log
 * @param Arguments
 */
#define logWarn(FMT, ...)                           logPrint(WARN, FMT, __VA_ARGS__)
/**
 * @brief Print log with INFO level
 *
 * @param FMT Format of log
 * @param Arguments
 */
#define logInfo(FMT, ...)                           logPrint(INFO, FMT, __VA_ARGS__)
/**
 * @brief Print log with DEBUG level
 *
 * @param FMT Format of log
 * @param Arguments
 */
#define logDebug(FMT, ...)                          logPrint(DEBUG, FMT, __VA_ARGS__)
/**
 * @brief Print log with TRACE level
 *
 * @param FMT Format of log
 * @param Arguments
 */
#define logTrace(FMT, ...)                          logPrint(TRACE, FMT, __VA_ARGS__)


// ------------------------------ Private Macros -----------------------------
#define __LOG_FMT(LVL, F, L)                        LOG_FMT(LVL, F, L)


#endif

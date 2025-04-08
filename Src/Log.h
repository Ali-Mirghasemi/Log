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
/**
 * @brief Enable Log color
 */
#define LOG_COLOR                               1

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

#ifndef LOG_HEADER
    /**
     * @brief Specify log header format
     * @param LVL log level: NONE, ERROR, WARN, INFO, DEBUG, TRACE
     * @param F string: file path, ex: "./main.c"
     * @param L unsigned int: file line, 26
     */
    #define LOG_HEADER(LVL, F, L)               "[" #LVL " - " F ":" #L "] "
#endif

#ifndef LOG_END_LINE
    /**
     * @brief Specify log end line
     */
    #define LOG_END_LINE                        "\r\n"
#endif

#if LOG_COLOR
    /**
     * @brief Specify Log color mode
     * - HEADER: only change color of header field
     * - LINE: change color of full line
     */
    #define LOG_COLOR_MODE                      LINE
    /**
     * @brief Default color
     */
    #define LOG_COLOR_DEFAULT                   "\e[37m"
    /**
     * @brief Color for error logs
     */
    #define LOG_COLOR_ERROR                     "\e[31m"
    /**
     * @brief Color for warning logs
     */
    #define LOG_COLOR_WARN                      "\e[33m"
    /**
     * @brief Color for info logs
     */
    #define LOG_COLOR_INFO                      "\e[37m"
    /**
     * @brief Color for debug logs
     */
    #define LOG_COLOR_DEBUG                     "\e[97m"
    /**
     * @brief Color for trace logs
     */
    #define LOG_COLOR_TRACE                     "\e[97m"
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
 * @param COLOR_MODE HEADER, LINE
 * @param COLOR string escape character for color, ex: "\e[37m"
 * @param FMT Format of log
 * @param Arguments
 */
#define logPrintFmt(LVL, COLOR_MODE, COLOR, FMT, ...)               __logPrintFmt(LVL, COLOR_MODE, COLOR, FMT, __VA_ARGS__)
/**
 * @brief Print log with specify level
 *
 * @param LVL Log Level: NONE, ERROR, WARN, INFO, DEBUG, TRACE
 * @param FMT Format of log
 * @param Arguments
 */
#define logPrint(LVL, FMT, ...)                                     logPrintFmt(LVL, LOG_COLOR_MODE, LOG_COLOR_ ##LVL, FMT, __VA_ARGS__)
/**
 * @brief Print log with ERROR level
 *
 * @param FMT Format of log
 * @param Arguments
 */
#define logError(FMT, ...)                                          logPrint(ERROR, FMT, __VA_ARGS__)
/**
 * @brief Print log with WARN level
 *
 * @param FMT Format of log
 * @param Arguments
 */
#define logWarn(FMT, ...)                                           logPrint(WARN, FMT, __VA_ARGS__)
/**
 * @brief Print log with INFO level
 *
 * @param FMT Format of log
 * @param Arguments
 */
#define logInfo(FMT, ...)                                           logPrint(INFO, FMT, __VA_ARGS__)
/**
 * @brief Print log with DEBUG level
 *
 * @param FMT Format of log
 * @param Arguments
 */
#define logDebug(FMT, ...)                                          logPrint(DEBUG, FMT, __VA_ARGS__)
/**
 * @brief Print log with TRACE level
 *
 * @param FMT Format of log
 * @param Arguments
 */
#define logTrace(FMT, ...)                                          logPrint(TRACE, FMT, __VA_ARGS__)


// ------------------------------ Private Macros -----------------------------
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L
    #define __logPrintFmt_(LVL, COLOR_MODE, COLOR, FMT, ...) \
        if (LOG_LEVEL_ ##LVL <= LOG_LEVEL) { \
            LOG_PRINT(COLOR __LOG_HEADER(LVL, __FILE__, __LINE__) __LOG_COLOR_MODE_HEADER_ ##COLOR_MODE FMT LOG_END_LINE __LOG_COLOR_MODE_LINE_ ##COLOR_MODE LOG_COLOR_DEFAULT __VA_OPT__(,) __VA_ARGS__); \
        }
#else
    #define __logPrintFmt_(LVL, COLOR_MODE, COLOR, FMT, ...) \
        if (LOG_LEVEL_ ##LVL <= LOG_LEVEL) { \
            LOG_PRINT(COLOR __LOG_HEADER(LVL, __FILE__, __LINE__) __LOG_COLOR_MODE_HEADER_ ##COLOR_MODE FMT LOG_END_LINE __LOG_COLOR_MODE_LINE_ ##COLOR_MODE LOG_COLOR_DEFAULT, ##__VA_ARGS__); \
        }
#endif

#define __logPrintFmt(LVL, COLOR_MODE, COLOR, FMT, ...)             __logPrintFmt_(LVL, COLOR_MODE, COLOR, FMT, __VA_ARGS__)

#define __LOG_HEADER(LVL, F, L)                                     LOG_HEADER(LVL, F, L)

#if LOG_COLOR
    #define __LOG_COLOR_MODE_HEADER_HEADER                          LOG_COLOR_DEFAULT
    #define __LOG_COLOR_MODE_HEADER_LINE

    #define __LOG_COLOR_MODE_LINE_HEADER
    #define __LOG_COLOR_MODE_LINE_LINE                              LOG_COLOR_DEFAULT
#else
    #define LOG_COLOR_DEFAULT
    #define LOG_COLOR_ERROR
    #define LOG_COLOR_WARN
    #define LOG_COLOR_INFO
    #define LOG_COLOR_DEBUG
    #define LOG_COLOR_TRACE
#endif

#endif

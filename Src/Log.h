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
#define LOG_VER_FIX      1

#include "LogConfig.h"

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
#if LOG_INC_STDIO
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
/**
 * @brief Use for custom color mode
 */
#define LOG_COLOR_MODE_FMT(SIGN, MODE, COLOR)                       __LOG_COLOR_MODE_FMT(SIGN, MODE, COLOR)

// ------------------------------ Private Macros -----------------------------
#if defined(__cplusplus) || (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L)
    #define __logPrintFmt_(LVL, COLOR_MODE, COLOR, FMT, ...) \
        if (LOG_LEVEL_ ##LVL <= LOG_LEVEL) { \
            LOG_PRINT(LOG_COLOR_MODE_FMT(BASE, COLOR_MODE, COLOR) __LOG_HEADER(LVL, __FILE__, __LINE__, COLOR_MODE, COLOR) LOG_COLOR_MODE_FMT(HEADER, COLOR_MODE, COLOR) FMT LOG_END_LINE LOG_COLOR_MODE_FMT(LINE, COLOR_MODE, COLOR) LOG_COLOR_DEFAULT __VA_OPT__(,) __VA_ARGS__); \
        }
#else
    #define __logPrintFmt_(LVL, COLOR_MODE, COLOR, FMT, ...) \
        if (LOG_LEVEL_ ##LVL <= LOG_LEVEL) { \
            LOG_PRINT(LOG_COLOR_MODE_FMT(BASE, COLOR_MODE, COLOR) __LOG_HEADER(LVL, __FILE__, __LINE__, COLOR_MODE, COLOR) LOG_COLOR_MODE_FMT(HEADER, COLOR_MODE, COLOR) FMT LOG_END_LINE LOG_COLOR_MODE_FMT(LINE, COLOR_MODE, COLOR) LOG_COLOR_DEFAULT, ##__VA_ARGS__); \
        }
#endif

#define __logPrintFmt(LVL, COLOR_MODE, COLOR, FMT, ...)             __logPrintFmt_(LVL, COLOR_MODE, COLOR, FMT, __VA_ARGS__)

#define __LOG_HEADER(LVL, F, L, M, C)                               LOG_HEADER(LVL, F, L, M, C)

#define __LOG_COLOR_MODE_FMT(SIGN, MODE, COLOR)                     __LOG_COLOR_MODE_ ##SIGN ##_ ##MODE (COLOR)

#if LOG_COLOR
    #define __LOG_COLOR_MODE_BASE_HEADER(COLOR)                     COLOR
    #define __LOG_COLOR_MODE_BASE_LINE(COLOR)                       COLOR
    #define __LOG_COLOR_MODE_BASE_CUSTOM(COLOR)                

    #define __LOG_COLOR_MODE_HEADER_HEADER(COLOR)                   LOG_COLOR_DEFAULT
    #define __LOG_COLOR_MODE_HEADER_LINE(COLOR)
    #define __LOG_COLOR_MODE_HEADER_CUSTOM(COLOR)

    #define __LOG_COLOR_MODE_LINE_HEADER(COLOR)
    #define __LOG_COLOR_MODE_LINE_LINE(COLOR)                       LOG_COLOR_DEFAULT
    #define __LOG_COLOR_MODE_LINE_CUSTOM(COLOR)

    #define __LOG_COLOR_MODE_START_HEADER(COLOR)
    #define __LOG_COLOR_MODE_START_LINE(COLOR)
    #define __LOG_COLOR_MODE_START_CUSTOM(COLOR)                    COLOR

    #define __LOG_COLOR_MODE_END_HEADER(COLOR)                      
    #define __LOG_COLOR_MODE_END_LINE(COLOR)                      
    #define __LOG_COLOR_MODE_END_CUSTOM(COLOR)                      LOG_COLOR_DEFAULT
#else
    #define LOG_COLOR_DEFAULT
    #define LOG_COLOR_ERROR
    #define LOG_COLOR_WARN
    #define LOG_COLOR_INFO
    #define LOG_COLOR_DEBUG
    #define LOG_COLOR_TRACE
    #define LOG_COLOR_MODE                                          LINE

    #define __LOG_COLOR_MODE_BASE_HEADER(COLOR)
    #define __LOG_COLOR_MODE_BASE_LINE(COLOR)
    #define __LOG_COLOR_MODE_BASE_CUSTOM(COLOR)

    #define __LOG_COLOR_MODE_HEADER_HEADER(COLOR)
    #define __LOG_COLOR_MODE_HEADER_LINE(COLOR)
    #define __LOG_COLOR_MODE_HEADER_CUSTOM(COLOR)

    #define __LOG_COLOR_MODE_LINE_HEADER(COLOR)
    #define __LOG_COLOR_MODE_LINE_LINE(COLOR)
    #define __LOG_COLOR_MODE_LINE_CUSTOM(COLOR)

    #define __LOG_COLOR_MODE_START_HEADER(COLOR)
    #define __LOG_COLOR_MODE_START_LINE(COLOR)
    #define __LOG_COLOR_MODE_START_CUSTOM(COLOR)

    #define __LOG_COLOR_MODE_END_HEADER(COLOR)                      
    #define __LOG_COLOR_MODE_END_LINE(COLOR)                      
    #define __LOG_COLOR_MODE_END_CUSTOM(COLOR)
#endif

#endif

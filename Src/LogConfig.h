/**
 * @file LogConfig.h
 * @author Ali Mirghasemi (ali.mirghasemi1376@gmail.com)
 * @brief This file contains full configuration for Log Library
 * @version 0.1
 * @date 2025-12-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef _LOG_CONFIG_H_
#define _LOG_CONFIG_H_

#include <stdint.h>

/* Check User Config file exists to include it or not */
#ifndef __has_include
    #define __has_include(X)    0
#endif

#if defined(LOG_USER_CONFIG) || __has_include("LogUserConfig.h")
    #include "LogUserConfig.h"
#endif

/************************************************************************/
/*                            Configuration                             */
/************************************************************************/
/**
 * @brief If you need to change log level in runtime you can enable this feature
 */
#ifndef LOG_DYNAMIC_LEVEL
    #define LOG_DYNAMIC_LEVEL                       0
#endif
/**
 * @brief Enable Log color
 */
#ifndef LOG_COLOR
    #define LOG_COLOR                               1
#endif

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
    /**
     * @brief Auto include stdio.h
     */
    #define LOG_INC_STDIO                       1
#endif

#ifndef LOG_HEADER
    /**
     * @brief Specify log header format
     * @param LVL log level: NONE, ERROR, WARN, INFO, DEBUG, TRACE
     * @param F string: file path, ex: "./main.c"
     * @param L unsigned int: file line, 26
     * @param M color mode: HEADER, LINE, CUSTOM
     * @param C string: color code
     */
    #define LOG_HEADER(LVL, F, L, M, C)         "[" LOG_COLOR_MODE_FMT(START, M, C) #LVL LOG_COLOR_MODE_FMT(END, M, C) " - " F ":" #L "] "
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
     * - CUSTOM: change user custom area
     */
    #define LOG_COLOR_MODE                      CUSTOM
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

#endif // _LOG_CONFIG_H_

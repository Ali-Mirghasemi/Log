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



#endif

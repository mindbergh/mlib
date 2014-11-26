/* GLIB - Library of useful routines for C programming
 *
 * Author: Ming Fang <mingf@cs.cmu.edu>
 * Time:   11/26/2014
 */

#ifndef MTYPES_H
#define MTYPES_H


typedef int (*MCompareFunc) (const void* a, const void* b);
typedef int (*MCompareDataFunc) (const void* a, const void* b, void* user_data);
typedef boolean (*MEqualFunc) (const void* a, const void* b);


#endif
/* This is a singly linked list
 *
 * Author: Ming Fang <mingf@cs.cmu.edu>
 * Date: 11/26/2014
 */

#ifndef MLIST_H
#define MLIST_H

typedef struct _MList MList;

struct _MList
{
  void* data;
  MList* next;
}



#endif

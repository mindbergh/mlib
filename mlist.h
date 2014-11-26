/* This is a double linked list
 *
 * Author: Ming Fang <mingf@cs.cmu.edu>
 * Date: 11/26/2014
 */

#ifndef MLIST_H
#define MLIST_H

typedef struct _MList MList;

struct _MList {
  void* data;
  MList* prev;
  MList* next;
};


MSList* mslist_new(void);
MSList* mslist_append(MSList* list, void* data);
MSList* mslist_prepend(MSList* list, void* data);
MSList* mslist_insert (MSList* list, void* data, int position);
MSList* mslist_get(MSList *list, unsigned int n);
void* mslist_getdata(MSList* list, unsigned int n);
MSList* mslist_find(MSList* list, void* data);
int mslist_index(MSList* list, void* data);
MSList* mslist_last(MSList *list);
unsigned int mslist_length(MSList *list);
void mslist_foreach (MSList* list, MFunc func, void* func_data);



#endif

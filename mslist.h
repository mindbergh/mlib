/* This is a singly linked list
 *
 * Author: Ming Fang <mingf@cs.cmu.edu>
 * Date: 11/26/2014
 */

#ifndef MSLIST_H
#define MSLIST_H

typedef struct _MSList MSList;

struct _MSList {
  void* data;
  MSList* next;
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
void mslist_foreach(MSList* list, MFunc func, void* func_data);
MSList* mslist_remove(MSList *list, void* data);
MSList* mslist_remove_all(MSList *list, void* data);
MSList* mslist_remove_link(MSList *list, MSList *link);
MSList* mslist_delete_link(MSList *list, MSList *link);
void mslist_free(MSList *list);
void mslist_free_full(MSList *list);


#endif

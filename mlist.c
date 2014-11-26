/* This is a singly linked list for mlib
 *
 * Author: Ming Fang <mingf@cs.cmu.edu>
 * Date: 11/26/2014
 */

#include "mlist.h"
#include "mutil.h"

MList* mlist_alloc(void) {
    return mnew0(MList)
}

MList* mlist_append(MList* list, void* data) {
    MList* new_list;
    MList* last;

    new_list = mlist_alloc();
    new_list->data = data;
    new_list->next = NULL;

    if (list) {
        last = mlist_last(list);
        last->next = new_list;
        return list;
    } else {
        return new_list;
    }
}

MList* mlist_prepend(MList* list, void* data) {
    MList *new_list;

    new_list = mlist_alloc ();
    new_list->data = data;
    new_list->next = list;

    return new_list;
}

/* insert data into the given list at given position
 * @param list the list into which the data is inserted
 * @param data the given data to be instered
 * @param position if position <  0: append new data
 *                 if position == 0: prepend new data
 *                 otherwise       : insert new data
 * @return the pointer to the head
 */

MList* mlist_insert (MList* list, void* data, int position) {
    MList *prev_list;
    MList *tmp_list;
    MList *new_list;

    if (position < 0)
        return mlist_append (list, data);
    else if (position == 0)
        return mlist_prepend (list, data);

    new_list = mlist_alloc();
    new_list->data = data;

    if (!list)
    {
        new_list->next = NULL;
        return new_list;
    }

    prev_list = NULL;
    tmp_list = list;

    while ((position-- > 0) && tmp_list) {
        prev_list = tmp_list;
        tmp_list = tmp_list->next;
    }

    new_list->next = prev_list->next;
    prev_list->next = new_list;

    return list;
}



MList* mlist_get (MList *list, unsigned int n) {
  while (n-- > 0 && list)
    list = list->next;

  return list;
}




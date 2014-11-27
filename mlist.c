/* This is a doubly linked list for mlib
 *
 * Author: Ming Fang <mingf@cs.cmu.edu>
 * Date: 11/26/2014
 */

#include "mlist.h"
#include "mutil.h"

MList* mlist_new(void) {
    return mnew0(MList)
}

MList* mlist_append(MList* list, void* data) {
    MList* new_list;
    MList* last;

    new_list = mlist_new();
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

    new_list = mlist_new();
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

MList* mlist_insert(MList* list, void* data, int position) {
    MList *prev_list;
    MList *tmp_list;
    MList *new_list;

    if (position < 0)
        return mlist_append (list, data);
    else if (position == 0)
        return mlist_prepend (list, data);

    new_list = mlist_new();
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



MList* mlist_get(MList *list, unsigned int n) {
    while (n-- > 0 && list)
        list = list->next;

    return list;
}

void* mlist_getdata(MList* list, unsigned int n) {
    while (n-- > 0 && list)
        list = list->next;

    return list ? list->data : NULL;
}

MList* mlist_find(MList* list, void* data) {
    while (list) {
        if (list->data == data)
            break;
        list = list->next;
    }

    return list;
}

int mlist_index(MList* list, void* data) {
    int i = 0;
    while (list) {
        if (list->data == data)
            return i;
        i++;
        list = list->next;
    }

    return -1;
}

MList* mlist_last(MList *list) {
    if (list) {
        while (list->next)
            list = list->next;
    }

    return list;
}

unsigned int mlist_length(MList *list) {
    unsigned int length = 0;
    while (list) {
        length++;
        list = list->next;
    }

    return length;
}

void mlist_foreach (MList* list, MFunc func, void* func_data) {
    while (list) {
        MList *next = list->next;
        (*func) (list->data, func_data);
        list = next;
    }
}


/* remove given node from the list
 */

MList* mlist_remove(MList *list, MList *link) {
  MList *tmp;
  MList *prev;

  prev = NULL;
  tmp = list;

  while (tmp) {
      if (tmp == link) {
          if (prev)
            prev->next = tmp->next;
          if (list == tmp)
            list = list->next;

          tmp->next = NULL;
          break;
        }

      prev = tmp;
      tmp = tmp->next;
    }

  return list;
}


/* remove given node from the list and free it
 */
MList* mlist_delete(MList *list, MList *link) {
  list = mlist_remove(list, link);
  free(list);
  return list;
}

/* Free the entire list but does not free data
 */
void mlist_free(MList *list) {
    if (list == NULL) {
        return;
    }
    mlist_free(list->next);
    free(list);
    return;
}

/* Free the entire list and associated data
 */
void mlist_free_full(MList *list) {
    if (list == NULL) {
        return;
    }
    mlist_free(list->next);
    free(list->data);
    free(list);
    return;
}



/* This is a singly linked list for mlib
 *
 * Author: Ming Fang <mingf@cs.cmu.edu>
 * Date: 11/26/2014
 */

#include "mslist.h"
#include "mutil.h"

MSList* mslist_new(void) {
    return mnew0(MSList)
}

MSList* mslist_append(MSList* list, void* data) {
    MSList* new_list;
    MSList* last;

    new_list = mslist_new();
    new_list->data = data;
    new_list->next = NULL;

    if (list) {
        last = mslist_last(list);
        last->next = new_list;
        return list;
    } else {
        return new_list;
    }
}

MSList* mslist_prepend(MSList* list, void* data) {
    MSList *new_list;

    new_list = mslist_new();
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

MSList* mslist_insert(MSList* list, void* data, int position) {
    MSList *prev_list;
    MSList *tmp_list;
    MSList *new_list;

    if (position < 0)
        return mslist_append (list, data);
    else if (position == 0)
        return mslist_prepend (list, data);

    new_list = mslist_new();
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



MSList* mslist_get(MSList *list, unsigned int n) {
    while (n-- > 0 && list)
        list = list->next;

    return list;
}

void* mslist_getdata(MSList* list, unsigned int n) {
    while (n-- > 0 && list)
        list = list->next;

    return list ? list->data : NULL;
}

MSList* mslist_find(MSList* list, void* data) {
    while (list) {
        if (list->data == data)
            break;
        list = list->next;
    }

    return list;
}

int mslist_index(MSList* list, void* data) {
    int i = 0;
    while (list) {
        if (list->data == data)
            return i;
        i++;
        list = list->next;
    }

    return -1;
}

MSList* mslist_last(MSList *list) {
    if (list) {
        while (list->next)
            list = list->next;
    }

    return list;
}

unsigned int mslist_length(MSList *list) {
    unsigned int length = 0;
    while (list) {
        length++;
        list = list->next;
    }

    return length;
}

void mslist_foreach (MSList* list, MFunc func, void* func_data) {
    while (list) {
        MSList *next = list->next;
        (*func) (list->data, func_data);
        list = next;
    }
}


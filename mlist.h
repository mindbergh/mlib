#ifndef MLIST_H
#define MLIST_H

typedef struct _MList MList;

struct _MList
{
  void* data;
  MList* next;
}



#endif

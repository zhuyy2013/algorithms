#ifndef ALGORITHMS_INCLUDE_LINKED_LIST_H_
#define ALGORITHMS_INCLUDE_LINKED_LIST_H_

template <typename Type>
struct LinkedListNode {
  Type value;
  LinkedListNode<Type> *next;
}

template <typename Type> 
struct LinkedList {
  LinkedListNode<Type> * head;
}

#endif

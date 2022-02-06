//
// Created by 康晓宁 on 2022/2/6.
//

#ifndef PLAY_C_SRC_DATA_STRUCTURE_LINKED_LIST_H_
#define PLAY_C_SRC_DATA_STRUCTURE_LINKED_LIST_H_

typedef struct ListNode {
  int value;
  struct ListNode *next;
} ListNode;

ListNode *CreateNode(int value);

void DestroyNode(ListNode **node_ptr);

ListNode *CreateList(int array[], int length);

void PrintList(ListNode *head);

void LinkedListExample();

void DestroyList(ListNode **head);

void InsertNode(ListNode **head, int value, int index);

#endif //PLAY_C_SRC_DATA_STRUCTURE_LINKED_LIST_H_

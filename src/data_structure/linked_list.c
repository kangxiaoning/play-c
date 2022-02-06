//
// Created by 康晓宁 on 2022/2/6.
//
#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

ListNode *CreateNode(int value) {
  ListNode *node = malloc(sizeof(ListNode));
  // 内存分配失败
  if (!node) {
    exit(1);
  }
  // 正常创建流程
  node->value = value;
  node->next = NULL;
  return node;
}

void DestroyNode(ListNode **node_ptr) {
  (*node_ptr)->next = NULL;
  free(*node_ptr);
  *node_ptr = NULL;
}

ListNode *CreateList(int array[], int length) {
  // 空链表
  if (length <= 0) {
    return NULL;
  }
  // 非空链表
  ListNode *head = CreateNode(array[0]);
  ListNode *current = head;
  for (int i = 1; i < length; ++i) {
    current->next = CreateNode(array[i]);
    current = current->next;
  }
  return head;
}

void PrintList(ListNode *head) {
  while (head) {
    printf("%d -> ", head->value);
    head = head->next;
  }
  printf("NULL\n");
}

void DestroyList(ListNode **head) {
  if (!head || !(*head)) {
    return;
  }

  ListNode *current = *head;
  while (current) {
    ListNode *to_be_destroy = current;
    current = current->next;
    DestroyNode(&to_be_destroy);
  }

  *head = NULL;
}

void InsertNode(ListNode **head, int value, int index) {
  // 支持插入NULL链表，因此 !(*head) 不需要return
  if (!head || index < 0) {
    return;
  }

  // 创建新节点
  ListNode *new_node = CreateNode(value);

  // 插入到链表头
  if (index == 0) {
    new_node->next = *head;
    *head = new_node;

  } else {
    // 链表head可能为NULL
    if (!(*head)) {
      // 此时创建默认head
      *head = CreateNode(0);
    }

    // 循环遍历
    ListNode *current = *head;
    // index为1表示找到插入位置
    while (index > 1) {
      // 当前节点为NULL
      if (!current->next) {
        current->next = CreateNode(0);
      }
      current = current->next;
      index--;
    }
    new_node->next = current->next;
    current->next = new_node;
  }
}

void LinkedListExample() {
  // create list
  int array[] = {0, 1, 2, 3, 4};
  ListNode *head = CreateList(array, 5);
  PrintList(head);


  // insert node
  // 插入到链表头
  InsertNode(&head, 100, 0);
  PrintList(head);
  // 插入到链表中间
  InsertNode(&head, 200, 3);
  PrintList(head);
  // 插入到超出链表长度处
  InsertNode(&head, 300, 10);
  PrintList(head);

  // destroy list
  DestroyList(&head);

  // 插入到空链表
  InsertNode(&head, 400, 5);
  PrintList(head);
  DestroyList(&head);

  // 销毁后确认链表地址
  printf("%p\n", head);
}

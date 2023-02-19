//
// Created by 张先森 on 2023/1/3.
//

#ifndef INC_12_3_BTREE_LEVERORDER_FUNCTION_H
#define INC_12_3_BTREE_LEVERORDER_FUNCTION_H
#include <stdio.h>
#include <stdlib.h>

typedef char BiElemType;
typedef struct BiTNode{
    BiElemType c;
    struct BiTNode *lchild;//左孩子结点
    struct BiTNode *rchild;//右孩子结点
}BiTNode,*BiTree;

//tag结构体是辅助队列(链表实现)使用的
typedef struct tag{
    BiTree p;//树的某一个结点的地址值
    struct tag *next;//指向辅助队列的下一个结点
}tag_t,*ptag_t;

//队列的相关数据结构
typedef BiTree ElemType;
typedef struct LinkNode{
    ElemType data;
    struct LinkNode *next;
}LinkNode,*Linklist;
typedef struct {
    LinkNode *front,*rear;
}LinkQueue;

void InitQueue(LinkQueue &Q);
bool IsEmpty(LinkQueue Q);
void EnQueue(LinkQueue &Q,ElemType x);
bool DeQueue(LinkQueue &Q,ElemType &x);
#endif //INC_12_3_BTREE_LEVERORDER_FUNCTION_H

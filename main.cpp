#include "function.h"

/*
 * 二叉树的前序、中序、后序遍历
 * 前序遍历：也叫先序遍历，又叫深度优先遍历，先打印自身结点，再打印左子树，再打印右子树
 * 中序遍历：先打印左子树，再打印当前结点，再打印右子树
 * 后序遍历：先打印左子树，再打印右子树，最后打印当前结点
 * */
//前序遍历，也叫先序遍历，又叫深度优先遍历 - 根左右
void PreOrder(BiTree p){
    if(p!=NULL){
        printf("%c",p->c);//等价于putchar(p->c);打印根结点
        PreOrder(p->lchild);//打印左子树
        PreOrder(p->rchild);//打印右子树
    }
}
//中序遍历 - 左根右
void InOrder(BiTree p){
    if(p!=NULL){
        InOrder(p->lchild);//打印左子树
        printf("%c",p->c);//打印根结点
        InOrder(p->rchild);//打印右子树
    }
}
//后序遍历 - 左右根
void PostOrder(BiTree p){
    if(p!=NULL){
        PostOrder(p->lchild);//打印左子树
        PostOrder(p->rchild);//打印右子树
        printf("%c",p->c);//打印根结点
    }
}
//层序遍历，也叫层次遍历，又叫广度优先遍历
void LevelOrder(BiTree T){
    LinkQueue Q;//辅助队列
    InitQueue(Q);//初始化辅助队列
    BiTree p;//用于存储打印的树结点
    EnQueue(Q,T);//树根入队
    while(!IsEmpty(Q)){//判断队列是否为空
        DeQueue(Q,p);//如果队列不为空，出队当前结点并打印
        printf("%c",p->c);
        if(p->lchild!=NULL){//判断当前结点的左孩子是否为空,如果左孩子不为空,就入队左孩子
            EnQueue(Q,p->lchild);
        }
        if(p->rchild!=NULL){//判断当前结点的右孩子是否为空,如果右孩子不为空,就入队右孩子
            EnQueue(Q,p->rchild);
        }
    }
}
//二叉树的建树(层次建树)
int main(){
    BiTree pnew;//用来指向新申请的树结点
    BiTree tree=NULL;//tree是指向树根的，代表树
    //phead指向辅助队列的队头，ptail指向辅助队列的队尾。list_pnew用于存储新入队的结点
    ptag_t phead=NULL,ptail=NULL,list_pnew=NULL,pcur;//pcur始终指向队列待放入结点的位置
    char c;
    while(scanf("%c",&c)){//输入内容为abcdefghij
        if(c=='\n'){
            break;//读取到换行就结束
        }
        //calloc申请空间并对空间进行初始化，赋值为0，calloc申请的空间大小是两个参数直接相乘
        pnew=(BiTree) calloc(1,sizeof(BiTNode));
        pnew->c=c;//存入数据
        list_pnew=(ptag_t) calloc(1,sizeof(tag_t));//给队列结点申请空间
        list_pnew->p=pnew;//将树节点的地址存入辅助队列
        if(NULL==tree){
            tree=pnew;//tree指向树的根节点
            phead=list_pnew;//第一个结点即是队列头，又是队列尾
            ptail=list_pnew;//队列尾
            pcur=list_pnew;//pcur要指向要进入树的父节点
        }else{
            //让元素先入队列
            ptail->next=list_pnew;
            ptail=list_pnew;
            //把结点放入树中
            if(pcur->p->lchild==NULL){
                pcur->p->lchild=pnew;//把新结点放入要插入结点的左边
            }else if(pcur->p->rchild==NULL){
                pcur->p->rchild=pnew;//把新结点放入要插入结点的右边
                pcur=pcur->next;//如果当前结点已满(左右孩子都有),pcur指向下一个
            }
        }
    }
    //前序遍历，也叫先序遍历，先打印当前结点，打印左孩子，打印右孩子(根左右)
    printf("------------------PreOrder------------------\n");
    PreOrder(tree);
    //中序遍历，先打印左孩子，打印父亲，打印右孩子(左根右)
    printf("\n------------------InOrder-------------------\n");
    InOrder(tree);
    //后序遍历，先打印左孩子，打印右孩子，最后打印父亲
    printf("\n----------------PostOrder-------------------\n");
    PostOrder(tree);
    printf("\n----------------LevelOrder-------------------\n");
    LevelOrder(tree);
    printf("\n");
    return 0;
}
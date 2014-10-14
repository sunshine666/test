
#include <stdio.h>
#include <stdlib.h>
#ifndef _TREE_H_
#define OK 1
#define ERROR -1

struct TNode
{
	int data;
	struct TNode *lchild;
	struct TNode *rchild;
};

void visit(char data);

struct TNode* Preorder_Create_BTree(void);

void PreorderTraverseRecursive(struct TNode  *T);
void InorderTraverse(struct TNode *T);
void InorderTraverseRecursive(struct TNode *T);
struct TNode* InsertSeqTreeRecursive(int k,struct TNode *T);
struct TNode* CreateSqTree(void);
struct TNode *bansrch(int k,struct TNode *T);

#endif

#define MAX_NODE  50
#define NULLKEY -1

//访问结点
void visit(char data)
{
    printf("%d ",data);
}

//建立链式二叉树，返回指向根结点的指针变量
struct TNode* Preorder_Create_BTree(void)
{
    struct TNode *T;
    int data;
    scanf("%d",&data);
    if(data == NULLKEY)
    {
        T = NULL;
        return(T);
    }
    else
    {
        //创建根节点
        T = (struct TNode*)malloc(sizeof(struct TNode));
        T->data = data;
        //创建左子树
        T->lchild = Preorder_Create_BTree();
        //创建右子树
        T->rchild = Preorder_Create_BTree();
        return(T) ;
    }
}

//先序遍历二叉树(递归)
void  PreorderTraverseRecursive(struct TNode  *T)
{
    if  (T!=NULL)
    {
        visit(T->data);
        PreorderTraverseRecursive(T->lchild);
        PreorderTraverseRecursive(T->rchild);
    }
}


//中序遍历(递归)
void InorderTraverseRecursive(struct TNode *T)
{
    if(T != NULL)
    {
        InorderTraverseRecursive(T->lchild);
        visit(T->data);
        InorderTraverseRecursive(T->rchild);
    }
}

//后续遍历（递归）
void PostOrder(struct TNode *T)
{
	    if(T != NULL)
    {
        PostOrder(T->lchild);
        PostOrder(T->rchild);       
		visit(T->data);
    }
}

//二叉排序树查找
struct TNode *bansrch(int k,struct TNode *T)
{
    struct TNode *p = T;
    while((p!=NULL)&&(p->data!=k))
    {
        if( p->data > k )
            p = p->lchild;
        else
            p = p->rchild;
    }
    return(p);
}

//插入二叉排序树(递归)
struct TNode* InsertSeqTreeRecursive(int k,struct TNode *T)
{
    struct TNode* nT = T;
    if(T == NULL)
    {
        nT =(struct TNode *) malloc(sizeof(struct TNode ));
        nT->data = k;
        nT->lchild = NULL;
        nT->rchild = NULL;
    }
    else if(T->data > k)
        T->lchild = InsertSeqTreeRecursive(k,T->lchild);
    else
        T->rchild = InsertSeqTreeRecursive(k,T->rchild);
    return nT;
 }




struct TNode* CreateSqTree(void)
{
    struct TNode* T = NULL;
    int data;
    while(1)
    {
        scanf("%d",&data);
        if(data == -1)
    	{
            break;
    	}
        else
    	{
            T = InsertSeqTreeRecursive(data,T);
    	}
    }

    return T;
}

//删除根节点
struct TNode* delete_BST(struct TNode* p)
{
    struct TNode *q,*s;
    if(!p->rchild)
    {//只需重接左子树
        q = p;
        p = p->lchild;
        free(q);
    }
    else if(!p->lchild)
    {//只需重接右子树
        q = p;
        p = p->rchild;
        free(q);
    }
    else
    {//左右子树不空，用左子树中值最大的结点(p的前驱)代替
        q = p;
        s = p->lchild; //s记录值最大结点，q记录其前驱
        while(s->rchild)
    	{
            q = s;
            s = s->rchild;
        }//左子树向右走到头，s指                	     //向p的前驱
        p->data = s->data;
        if(q!=p)
            q->rchild = s->lchild;
        else
            q->lchild = s->lchild; //p的左子树根无右子树
        free(s);
    }
    return(p);
}

//删除二叉排序树上一个结点p
struct TNode* Delete(struct TNode* T, struct TNode *f, struct TNode *p)
{
    struct TNode *q, *nT = T;
    if(p==T)
        nT = delete_BST(p);
    else{
        q = delete_BST(p);
        if(f->lchild==p)
            f->lchild = q;
        else
            f->rchild = q;
    }
    return(nT);
}

struct TNode* FindFather(int k,struct TNode* T)
{
    struct TNode* f;
    struct TNode *p = T;
    while((p!=NULL)&&(p->data!=k))
    {
        if( p->data > k )
        {
            f=p;
            p = p->lchild;
        }
        else
        {
            f=p;
            p = p->rchild;
        }
    }
    return(f);
}



int main()
{
    struct TNode *T = NULL;
    struct TNode *fT = NULL;
    int Task = 0;
    int data;

    while(1)
    {
        //输入任务
        printf("\n选择任务：0-创建二叉树 1-先序遍历；2-中序遍历；3-后续遍历 ；10-创建二叉排序树；11-查找二叉排序树；12-插入二叉排序树；13-删除二叉排序树；0-退出\n");
        scanf("%d",&Task);

        switch(Task)
    	{
        case 0://创建二叉树
            T = Preorder_Create_BTree();
            break;
        case 1://先序遍历
            PreorderTraverseRecursive(T);
            break;
        case 2://中序遍历
            InorderTraverseRecursive(T);
            break;
		case 3://后续遍历
			PostOrder(T);
			break;
        case 10://创建二叉排序树
            T = CreateSqTree();
            break;
        case 11://查找二叉排序树
            printf("输入要查找的值\n");
            scanf("%d",&data);
            fT = bansrch(data,T);
            if(fT)
    		{
                visit(fT->data);
    		}
            break;
        case 12:
            printf("输入要插入的值\n");
            scanf("%d",&data);
            T=InsertSeqTreeRecursive(data,T);
            break;
        case 13:
            printf("输入要删除的值\n");
            scanf("%d",&data);
            struct TNode *p=bansrch(data,T);
            struct TNode *f=FindFather(data,T);
            T=Delete(T,f,p);
            break;
    	}
    }
    return 0;
}


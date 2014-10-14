
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

//���ʽ��
void visit(char data)
{
    printf("%d ",data);
}

//������ʽ������������ָ�������ָ�����
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
        //�������ڵ�
        T = (struct TNode*)malloc(sizeof(struct TNode));
        T->data = data;
        //����������
        T->lchild = Preorder_Create_BTree();
        //����������
        T->rchild = Preorder_Create_BTree();
        return(T) ;
    }
}

//�������������(�ݹ�)
void  PreorderTraverseRecursive(struct TNode  *T)
{
    if  (T!=NULL)
    {
        visit(T->data);
        PreorderTraverseRecursive(T->lchild);
        PreorderTraverseRecursive(T->rchild);
    }
}


//�������(�ݹ�)
void InorderTraverseRecursive(struct TNode *T)
{
    if(T != NULL)
    {
        InorderTraverseRecursive(T->lchild);
        visit(T->data);
        InorderTraverseRecursive(T->rchild);
    }
}

//�����������ݹ飩
void PostOrder(struct TNode *T)
{
	    if(T != NULL)
    {
        PostOrder(T->lchild);
        PostOrder(T->rchild);       
		visit(T->data);
    }
}

//��������������
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

//�������������(�ݹ�)
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

//ɾ�����ڵ�
struct TNode* delete_BST(struct TNode* p)
{
    struct TNode *q,*s;
    if(!p->rchild)
    {//ֻ���ؽ�������
        q = p;
        p = p->lchild;
        free(q);
    }
    else if(!p->lchild)
    {//ֻ���ؽ�������
        q = p;
        p = p->rchild;
        free(q);
    }
    else
    {//�����������գ�����������ֵ���Ľ��(p��ǰ��)����
        q = p;
        s = p->lchild; //s��¼ֵ����㣬q��¼��ǰ��
        while(s->rchild)
    	{
            q = s;
            s = s->rchild;
        }//�����������ߵ�ͷ��sָ                	     //��p��ǰ��
        p->data = s->data;
        if(q!=p)
            q->rchild = s->lchild;
        else
            q->lchild = s->lchild; //p������������������
        free(s);
    }
    return(p);
}

//ɾ��������������һ�����p
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
        //��������
        printf("\nѡ������0-���������� 1-���������2-���������3-�������� ��10-����������������11-���Ҷ�����������12-���������������13-ɾ��������������0-�˳�\n");
        scanf("%d",&Task);

        switch(Task)
    	{
        case 0://����������
            T = Preorder_Create_BTree();
            break;
        case 1://�������
            PreorderTraverseRecursive(T);
            break;
        case 2://�������
            InorderTraverseRecursive(T);
            break;
		case 3://��������
			PostOrder(T);
			break;
        case 10://��������������
            T = CreateSqTree();
            break;
        case 11://���Ҷ���������
            printf("����Ҫ���ҵ�ֵ\n");
            scanf("%d",&data);
            fT = bansrch(data,T);
            if(fT)
    		{
                visit(fT->data);
    		}
            break;
        case 12:
            printf("����Ҫ�����ֵ\n");
            scanf("%d",&data);
            T=InsertSeqTreeRecursive(data,T);
            break;
        case 13:
            printf("����Ҫɾ����ֵ\n");
            scanf("%d",&data);
            struct TNode *p=bansrch(data,T);
            struct TNode *f=FindFather(data,T);
            T=Delete(T,f,p);
            break;
    	}
    }
    return 0;
}


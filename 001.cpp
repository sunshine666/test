#include<stdio.h>
#include<stdlib.h>
struct link
{
	int data;
	struct link *next;
};
struct link *UpsideList(struct link *head)
{
	struct link *pr=head,*p=head,*q=NULL;
	while(pr->next!=NULL)
	{
		p=pr->next;
		q=p->next;
		pr->next=q;
		p->next=head;
		head=p;
	}
	return head;
}
struct link *Deletenode(struct link *head)
{
	struct link *p=head,*pr=head;
	if(head==NULL)
		return head;
	while(p->next!=NULL)
	{
		p=pr;
		p=p->next;
		if(pr->data==p->data)
		{
			if(p->next==NULL)
				pr->next=NULL;
			else
			    pr->next=p->next;
		}
		else
			pr=p;    
	}
	return head;
}	
struct link *Sesort(struct link *head,int n)
{
	int i,j,h;
	int a;
    struct link *p,*pr,*tem;
	for(i=0;i<n;i++)
	{
		printf("%d\n",i);
		p=head;
		for(h=0;h<i;h++)
		{
			p=p->next;
		}
		tem=p;
		pr=p;
		for(j=i;j<n;j++)
		{
			printf("%d-%d ",tem->data,pr->data);
		    if(tem->data>pr->data)
			{
			   tem=pr;
			   printf("%d! ",pr->data);
			}
		    pr=pr->next;
		}
		a=p->data;
		p->data=tem->data;
		tem->data=a;
	}
	return head;
}
/*
==========================
 ���ܣ�ֱ�Ӳ�������(��С����)
 ���أ�ָ������� ͷ��ָ��
==========================
*/
/*
 ֱ�Ӳ�������Ļ���˼����Ǽ��������ǰ��n-1���ڵ����Ѿ�����ֵ
 ����������������ֶΣ�����ȡѧ��numΪ��ֵ���ź���ģ����ڽڵ�n��
 ����������Ҳ���λ�ã�ʹ��n�������������Ȼ���򡣰�������˼�룬����
 �������ͷ��βִ��һ�飬�Ϳ���ʹ���������Ϊ��������
 
���������ֱ�Ӳ�������ͼʾ��
---->[1]---->[3]----> [2]...---->[n]---->[NULL]��ԭ����
head   1->next  3->next  2->next   n->next

---->[1]---->[NULL]����ԭ������ȡ��1���ڵ���Ϊֻ��һ���ڵ����������
head
ͼ11

---->[3]---->[2]...---->[n]---->[NULL]��ԭ����ʣ������ֱ�Ӳ�������Ľڵ㣩
first   3->next  2->next   n->next
ͼ12

---->[1]---->[2]---->[3]...---->[n]---->[NULL]�����������
head   1->next  2->next  3->next   n->next

ͼ13����N���ڵ������ֱ�Ӳ�������

1������ԭ�������Ե�һ���ڵ�Ϊһ��������������ڵ�Ϊ�����ڵ㡣
2����ͼ12������ȡ�ڵ㣬��ͼ11�����ж�λ���롣
3������ͼʾ��˵��������������ʵֻ��һ�������������У�ʵ��ֻ������һ������ָ��ʣ����Ҫ����ڵ��ͷָ��first���ˡ�
   ��һ���������ظ������Ҫ��Ȼ�Ϳ�����Ϊ���������ѡ������һ���ˡ�
*/
struct link *InsertSort(struct link *head)
{
    struct link *first; /*Ϊԭ����ʣ������ֱ�Ӳ�������Ľڵ�ͷָ��*/
    struct link *t; /*��ʱָ�����������ڵ�*/
    struct link *p; /*��ʱָ�����*/
    struct link *q; /*��ʱָ�����*/

    first = head->next; /*ԭ����ʣ������ֱ�Ӳ�������Ľڵ������ɸ���ͼ12����⡣*/
    head->next = NULL; /*ֻ����һ���ڵ����������������ɸ���ͼ11����⡣*/

    while (first != NULL) /*����ʣ�����������*/
    {
        /*ע�⣺����for����������ֱ�Ӳ�������˼��ĵط�*/
        for (t = first, q = head; ((q != NULL) && (q->data < t->data)); p = q, q = q->next); /*����ڵ��������������Ҳ����λ��*/
    
    /*�˳�forѭ���������ҵ��˲����λ��*/
    /*ע�⣺��������˵����仰���Էŵ�����ע���˵��Ǹ�λ��ҲӦ�öԵģ����Ǿ��ǲ��ܡ�ԭ���������������ĵ�3������֪���ˡ�*/
        first = first->next; /*���������еĽڵ��뿪���Ա������뵽���������С�*/ 
  
        if (q == head) /*���ڵ�һ���ڵ�֮ǰ*/
        {
            head = t;
        }
        else /*p��q��ǰ��*/
        {
            p->next = t;
        }
        t->next = q; /*��ɲ��붯��*/
        /*first = first->next;*/
    }
    return head;
}
int main()
{
	int n,i;
	struct link *head=NULL;
	struct link *p=NULL;
    struct link *pr=NULL;
	printf("��������:");
	scanf("%d",&n);
	head=NULL;
	pr=head;
    for(i=0;i<n;i++)
	{
		p=new(link);
		if(head==NULL)
			head=p;
        else 
			pr->next=p;
        p->next=NULL;
		scanf("%d",&(p->data));
		pr=p;		
	}
	//head=Sesort(head,n);
	head=InsertSort(head);
    //head=UpsideList(head);
	//head=Deletenode(head);
	p=head;
	printf("\n");	printf("������\n");
    while(p!=NULL)
	{	
		printf("%d ",p->data);
		p=p->next;
	}
	return 0;
}
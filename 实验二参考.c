#include <stdio.h>
#include <stdlib.h>

typedef struct btnode					//���������Ľṹ�嶨��
{
	char element;
	struct btnode *lchild,*rchild;
}BTnode;

typedef struct btree					//�������Ľṹ�嶨�壬����һ��ָ�������������ָ��root
{
	struct btnode *root;
}BTree;

BTnode *PreCreat(BTnode *t)				//������������˽�еݹ麯��
{
	char ch;

	ch=getchar();						
	if(ch=='#')								//��ȡ�ַ���Ϊ'#'����ʾ���ｫ����һ���ն�����
		t=NULL;
	else
	{
		t=(BTnode *)malloc(sizeof(BTnode));		//���ɽ��
		t->element=ch;							//������Ϊ��'#'�� �ַ�
		t->lchild=PreCreat(t->lchild);			//����������
		t->rchild=PreCreat(t->rchild);			//����������
	}
	return t;
}

void Creat(BTree *Bt)				//���к�����Ϊ�����������ĺ����ṩ�ӿ�
{
	Bt->root=PreCreat(Bt->root);
}

void PreOrd(BTnode *t)				//���������˽�еݹ麯��
{
	if(t)
	{
		printf("%c ",t->element);
		PreOrd(t->lchild);
		PreOrd(t->rchild);
	}
}

void PreOrder(BTree *Bt)			//���к�����Ϊ��������������ṩ�ӿ�
{
	PreOrd(Bt->root);
}

void InOrd(BTnode *t)				//���������˽�еݹ麯��
{
	if(t)
	{
		InOrd(t->lchild);
		printf("%c ",t->element);		
		InOrd(t->rchild);
	}
}

void InOrder(BTree *Bt)				//���к�����Ϊ��������������ṩ�ӿ�
{
	InOrd(Bt->root);
}

void PostOrd(BTnode *t)				//���������˽�еݹ麯��
{
	if(t)
	{
		PostOrd(t->lchild);				
		PostOrd(t->rchild);
		printf("%c ",t->element);
	}
}

void PostOrder(BTree *Bt)			//���к�����Ϊ��������������ṩ�ӿ�
{
	PostOrd(Bt->root);
}


int nodes(BTnode *t)				//˽�еݹ麯������������еĽ����
{
	int tn,ln,rn;
	if(!t)							//������Ϊ�գ������Ϊ0
		tn=0;
	else
	{
		ln=nodes(t->lchild);
		rn=nodes(t->rchild);
		tn=ln+rn+1;					//�ǿ�����£��������Ľ����Ϊ�������������+1
	}
	return tn;
}

int Treenodes(BTree *Bt)			//���к�����Ϊ�������������ṩ�ӿ�
{
	return nodes(Bt->root);
}

int depth(BTnode *t)				//˽�еݹ麯������������ĸ߶�
{
	int td,ld,rd;

	if(!t)							//������Ϊ�գ��߶�Ϊ0
		td=0;
	else
	{
		ld=depth(t->lchild);
		rd=depth(t->rchild);
		if(ld>rd)					//�������ǿգ��߶�Ϊ���������߶ȴ����+1
			td=ld+1;
		else
			td=rd+1;
	}
	return td;
}

int Treedepth(BTree *Bt)			//���к�����Ϊ��������߶��ṩ�ӿ�			
{
	return depth(Bt->root);
}

int leaves(BTnode *t)				//˽�еݹ麯�������������Ҷ�ӽ�����				
{	
	int tl,ll,rl;

	if(!t)											//������Ϊ�գ�Ҷ�ӽ��Ϊ0
		tl=0;
	else  if((t->lchild==NULL)&&(t->rchild==NULL))	//����Ҷ�ӽ���Ҫ��
	        	tl=1;
	     else										//��ǰ���ȷǿգ��з�Ҷ��
		 {
			 ll=leaves(t->lchild);
		     rl=leaves(t->rchild);
			 tl=ll+rl;								//Ҷ�Ӹ���Ϊ��������Ҷ�Ӹ���֮��
		 }
	return tl;
}


int Treeleaves(BTree *Bt)					//���к�����Ϊ��������Ҷ�ӽ������ṩ�ӿ�
{
	return leaves(Bt->root);
}

void main()
{
	BTree *Bt;
	int tn,th,tl;

	Bt=(BTree *)malloc(sizeof(BTree));
	printf("\nInput Creat order:\n");
    Creat(Bt);							//���ô����������ĺ���

	printf("\nThe preorder is:\n");
	PreOrder(Bt);						//�������
	printf("\nThe inorder is:\n");
	InOrder(Bt);						//�������
	printf("\nThe postorder is:\n");
	PostOrder(Bt);						//�������

    //tn=Treenodes(Bt);									//�������������
	tn = nodes(Root);
	printf("\nThe nodes of the tree is:%d\n",tn);

	th=depth(Root);									//��������ĸ߶�
	printf("\nThe depth of the tree is:%d\n",th);

	tl=leaves(Root);									//�������Ҷ�Ӹ���
	printf("\nThe leaves of the tree is:%d\n",tl);
	
	
}

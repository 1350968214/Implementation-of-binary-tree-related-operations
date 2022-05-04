#include <stdio.h>
#include <stdlib.h>

//��һ����ɶ����� �������� �ṹ�Ķ���
//������ʵ�ֶ�������Ĵ�������������ͺ�������㷨��ʵ��
//������ʵ�ֶ����������������߶ȣ���Ҷ�ӽ���������������������������㷨��

typedef struct BiTNode					//���������Ľṹ�嶨��
{
	char data;
	struct BiTNode* lchild, * rchild;
}BiTNode;

//typedef struct btree					//�������Ľṹ�嶨�壬����һ��ָ�������������ָ��root
//{
//	struct BiTNode* root;
//}BTree;

BiTNode* PreCreate(BiTNode* t)				//������������˽�еݹ麯��
{
	char ch;
	ch = getchar();
	if (ch == '#')								//��ȡ�ַ���Ϊ'#'����ʾ���ｫ����һ���ն�����
		t = NULL;
	else
	{
		t = (BiTNode*)malloc(sizeof(BiTNode));		//���ɽ��
		t->data = ch;							//������Ϊ��'#'�� �ַ�
		t->lchild = PreCreate(t->lchild);			//����������
		t->rchild = PreCreate(t->rchild);			//����������
	}
	return t;
}

//void Creat(BiTNode* Bt)				//���к�����Ϊ�����������ĺ����ṩ�ӿ�
//{
//	Bt->root = PreCreate(Bt->root);
//}

void PreOrd(BiTNode* t)				//���������˽�еݹ麯��
{
	if (t)
	{
		printf("%c ", t->data);
		PreOrd(t->lchild);
		PreOrd(t->rchild);
	}
}

//void PreOrder(BiTNode* Bt)			//���к�����Ϊ��������������ṩ�ӿ�
//{
//	PreOrd(Bt->root);
//}

void InOrd(BiTNode* t)				//���������˽�еݹ麯��
{
	if (t)
	{
		InOrd(t->lchild);
		printf("%c ", t->data);
		InOrd(t->rchild);
	}
}

//void InOrder(BiTNode* Bt)				//���к�����Ϊ��������������ṩ�ӿ�
//{
//	InOrd(Bt->root);
//}

void PostOrd(BiTNode* t)				//���������˽�еݹ麯��
{
	if (t)
	{
		PostOrd(t->lchild);
		PostOrd(t->rchild);
		printf("%c ", t->data);
	}
}

//void PostOrder(BiTNode* Bt)			//���к�����Ϊ��������������ṩ�ӿ�
//{
//	PostOrd(Bt->root);
//}


int nodes(BiTNode* t)				//˽�еݹ麯������������еĽ����
{
	int tn, ln, rn;
	if (!t)							//������Ϊ�գ������Ϊ0
		tn = 0;
	else
	{
		ln = nodes(t->lchild);
		rn = nodes(t->rchild);
		tn = ln + rn + 1;					//�ǿ�����£��������Ľ����Ϊ�������������+1
	}
	return tn;
}

//int Treenodes(BiTNode* Bt)			//���к�����Ϊ�������������ṩ�ӿ�
//{
//	return nodes(Bt->root);
//}

int depth(BiTNode* t)				//˽�еݹ麯������������ĸ߶�
{
	int td, ld, rd;

	if (!t)							//������Ϊ�գ��߶�Ϊ0
		td = 0;
	else
	{
		ld = depth(t->lchild);
		rd = depth(t->rchild);
		if (ld > rd)					//�������ǿգ��߶�Ϊ���������߶ȴ����+1
			td = ld + 1;
		else
			td = rd + 1;
	}
	return td;
}

//int Treedepth(BiTNode* Bt)			//���к�����Ϊ��������߶��ṩ�ӿ�			
//{
//	return depth(Bt->root);
//}

int leaves(BiTNode* t)				//˽�еݹ麯�������������Ҷ�ӽ�����				
{
	int tl, ll, rl;

	if (!t)											//������Ϊ�գ�Ҷ�ӽ��Ϊ0
		tl = 0;
	else  if ((t->lchild == NULL) && (t->rchild == NULL))	//����Ҷ�ӽ���Ҫ��
		tl = 1;
	else										//��ǰ���ȷǿգ��з�Ҷ��
	{
		ll = leaves(t->lchild);
		rl = leaves(t->rchild);
		tl = ll + rl;								//Ҷ�Ӹ���Ϊ��������Ҷ�Ӹ���֮��
	}
	return tl;
}


//int Treeleaves(BiTNode* Bt)					//���к�����Ϊ��������Ҷ�ӽ������ṩ�ӿ�
//{
//	return leaves(Bt->root);
//}

int main()
{
	//BTree* Bt;
	BiTNode* Root=(BiTNode*)malloc(sizeof(BiTNode));
	int tn, th, tl;

	//Bt = (BTree*)malloc(sizeof(BTree));

	printf("\nInput Creat order:\n");
	Root = PreCreate(Root);							//���ô����������ĺ���

	printf("\nThe preorder is:\n");
	//PreOrder(Bt);						//�������
	PreOrd(Root);
	printf("\nThe inorder is:\n");
	//InOrder(Bt);						//�������
	InOrd(Root);
	printf("\nThe postorder is:\n");
	//PostOrder(Bt);						//�������
	PostOrd(Root);
	//tn=Treenodes(Bt);									//�������������
	tn = nodes(Root);
	printf("\nThe nodes of the tree is:%d\n", tn);

	th = depth(Root);									//��������ĸ߶�
	printf("\nThe depth of the tree is:%d\n", th);

	tl = leaves(Root);									//�������Ҷ�Ӹ���
	printf("\nThe leaves of the tree is:%d\n", tl);
	return 0;

}

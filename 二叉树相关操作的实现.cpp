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


BiTNode* PreCreate(BiTNode* t)				//����������
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


void PreOrd(BiTNode* t)				//�������
{
	if (t != NULL)
	{
		printf("%c ", t->data);
		PreOrd(t->lchild);
		PreOrd(t->rchild);
	}
}


void InOrd(BiTNode* t)				//�������
{
	if (t != NULL)
	{
		InOrd(t->lchild);
		printf("%c ", t->data);
		InOrd(t->rchild);
	}
}


void PostOrd(BiTNode* t)			//�������
{
	if (t != NULL)
	{
		PostOrd(t->lchild);
		PostOrd(t->rchild);
		printf("%c ", t->data);
	}
}



int nodes(BiTNode* t)				//��������еĽ����
{
	int tn, ln, rn;
	if (t == NULL)							//������Ϊ�գ������Ϊ0
		tn = 0;
	else
	{
		ln = nodes(t->lchild);
		rn = nodes(t->rchild);
		tn = ln + rn + 1;			//�ǿ�����£��������Ľ����Ϊ�������������+1
	}
	return tn;
}


int depth(BiTNode* t)				//��������ĸ߶�
{
	int td, ld, rd;

	if (t == NULL)					//������Ϊ�գ��߶�Ϊ0
		td = 0;
	else
	{
		ld = depth(t->lchild);
		rd = depth(t->rchild);
		if (ld > rd)			    //�������ǿգ��߶�Ϊ���������߶ȴ����+1
			td = ld + 1;
		else
			td = rd + 1;
	}
	return td;
}


int leaves(BiTNode* t)				//���������Ҷ�ӽ�����				
{
	int tl, ll, rl;

	if (t == NULL)							//������Ϊ�գ�Ҷ�ӽ��Ϊ0
		tl = 0;
	else  if ((t->lchild == NULL) && (t->rchild == NULL))	//����Ҷ�ӽ���Ҫ��
		tl = 1;
	else							//��ǰ���ȷǿգ��з�Ҷ��
	{
		ll = leaves(t->lchild);
		rl = leaves(t->rchild);
		tl = ll + rl;				//Ҷ�Ӹ���Ϊ��������Ҷ�Ӹ���֮��
	}
	return tl;
}


int main()
{
	BiTNode* Root = (BiTNode*)malloc(sizeof(BiTNode));
	int tn, th, tl;

	printf("\nInput Creat order:\n");
	Root = PreCreate(Root);							//���ô����������ĺ���

	printf("\nThe preorder is:\n");
	//�������
	PreOrd(Root);
	printf("\nThe inorder is:\n");
    //�������
	InOrd(Root);
	printf("\nThe postorder is:\n");
 	//�������
	PostOrd(Root);
	//�������������
	tn = nodes(Root);
	printf("\nThe nodes of the tree is:%d\n", tn);
	//��������ĸ߶�
	th = depth(Root);									
	printf("\nThe depth of the tree is:%d\n", th);
	//�������Ҷ�Ӹ���
	tl = leaves(Root);									
	printf("\nThe leaves of the tree is:%d\n", tl);
	return 0;

}

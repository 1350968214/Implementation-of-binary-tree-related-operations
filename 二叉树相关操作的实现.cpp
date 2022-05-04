#include <stdio.h>
#include <stdlib.h>

//（一）完成二叉树 二叉链表 结构的定义
//（二）实现二叉链表的创建，先序、中序和后序遍历算法的实现
//（三）实现二叉树求结点个数，求高度，求叶子结点数、交换二叉树左右子树的算法。

typedef struct BiTNode					//二叉树结点的结构体定义
{
	char data;
	struct BiTNode* lchild, * rchild;
}BiTNode;


BiTNode* PreCreate(BiTNode* t)				//创建二叉树
{
	char ch;
	ch = getchar();
	if (ch == '#')								//读取字符若为'#'，表示这里将建立一个空二叉树
		t = NULL;
	else
	{
		t = (BiTNode*)malloc(sizeof(BiTNode));		//生成结点
		t->data = ch;							//数据域为非'#'的 字符
		t->lchild = PreCreate(t->lchild);			//创建左子树
		t->rchild = PreCreate(t->rchild);			//创建右子树
	}
	return t;
}


void PreOrd(BiTNode* t)				//先序遍历
{
	if (t != NULL)
	{
		printf("%c ", t->data);
		PreOrd(t->lchild);
		PreOrd(t->rchild);
	}
}


void InOrd(BiTNode* t)				//中序遍历
{
	if (t != NULL)
	{
		InOrd(t->lchild);
		printf("%c ", t->data);
		InOrd(t->rchild);
	}
}


void PostOrd(BiTNode* t)			//后序遍历
{
	if (t != NULL)
	{
		PostOrd(t->lchild);
		PostOrd(t->rchild);
		printf("%c ", t->data);
	}
}



int nodes(BiTNode* t)				//求二叉树中的结点数
{
	int tn, ln, rn;
	if (t == NULL)							//二叉树为空，结点数为0
		tn = 0;
	else
	{
		ln = nodes(t->lchild);
		rn = nodes(t->rchild);
		tn = ln + rn + 1;			//非空情况下，二叉树的结点数为左右子树结点数+1
	}
	return tn;
}


int depth(BiTNode* t)				//求二叉树的高度
{
	int td, ld, rd;

	if (t == NULL)					//二叉树为空，高度为0
		td = 0;
	else
	{
		ld = depth(t->lchild);
		rd = depth(t->rchild);
		if (ld > rd)			    //二叉树非空，高度为左右子树高度大的再+1
			td = ld + 1;
		else
			td = rd + 1;
	}
	return td;
}


int leaves(BiTNode* t)				//求二叉树中叶子结点个数				
{
	int tl, ll, rl;

	if (t == NULL)							//二叉树为空，叶子结点为0
		tl = 0;
	else  if ((t->lchild == NULL) && (t->rchild == NULL))	//满足叶子结点的要求
		tl = 1;
	else							//当前结点既非空，有非叶子
	{
		ll = leaves(t->lchild);
		rl = leaves(t->rchild);
		tl = ll + rl;				//叶子个数为左右子树叶子个数之和
	}
	return tl;
}


int main()
{
	BiTNode* Root = (BiTNode*)malloc(sizeof(BiTNode));
	int tn, th, tl;

	printf("\nInput Creat order:\n");
	Root = PreCreate(Root);							//调用创建二叉树的函数

	printf("\nThe preorder is:\n");
	//先序遍历
	PreOrd(Root);
	printf("\nThe inorder is:\n");
    //中序遍历
	InOrd(Root);
	printf("\nThe postorder is:\n");
 	//后序遍历
	PostOrd(Root);
	//求二叉树结点个数
	tn = nodes(Root);
	printf("\nThe nodes of the tree is:%d\n", tn);
	//求二叉树的高度
	th = depth(Root);									
	printf("\nThe depth of the tree is:%d\n", th);
	//求二叉树叶子个数
	tl = leaves(Root);									
	printf("\nThe leaves of the tree is:%d\n", tl);
	return 0;

}

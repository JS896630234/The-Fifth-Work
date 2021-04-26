#pragma once
#include <stdio.h>
#include <stdlib.h>
typedef int Status;
#define MAXSIZE 100
#define OK 1
#define ERROR 0
typedef struct BSTNode
{
	int data;
	BSTNode* lchild;  //左孩子
	BSTNode* rchild;  //右孩子
}BSTNode, * BSTree;
typedef  BSTree SElemType;
typedef struct
{
	SElemType* base;  //起始地址
	SElemType* top;
	int stacksize;  //空间大小  eg,a[100]
}SqStack;
typedef struct QueueNode
{
	BSTree data;
	struct QueueNode* next;
}Node, QueueNode;
typedef struct Queue
{
	QueueNode* front;
	QueueNode* rear;
}Queue, * LinkQueue;


void InOderTraverse_re(BSTree bst);								//中序递归遍历
void PreOderTraverse_re(BSTree bst);							//先序递归遍历
void PostOderTraverse_re(BSTree bst);							//后序递归遍历
void InOderTraverse_Nore(BSTree bst);							//中序非递归遍历
void PreOderTraverse_Nore(BSTree bst);							//先序非递归遍历
void PostOderTraverse_Nore(BSTree bst);							//后序非递归遍历
void LevelOderTraverse(BSTree& T);								//层次排序
void Traverse(BSTree root);										//遍历功能
BSTNode* CreateTree(BSTree);									//初始化树
bool Search(BSTree bst, int key, BSTree f, BSTree* p);			//查找
BSTNode* CreatNode(int data);									//创造节点
bool Insert(BSTree* bst, int key);								//插入
BSTNode* FindParent(BSTree bst, BSTNode* child);				//查找父节点
void Delete(BSTree* bst, int key);								//删除元素
			


void welcome(BSTree);
Status Pop(SqStack& S, BSTree e);			
Status Push(SqStack& S, BSTree e);
Status StackEmpty(SqStack S);
Status InitStack(SqStack& S);
SElemType GetTop(SqStack S);
BSTree getHead(LinkQueue Q);
bool EmptyQueue(LinkQueue Q);
void DeQueue(LinkQueue& Q);
void EnQueue(LinkQueue& Q, BSTree T);
void InitQueue(LinkQueue& Q);
SElemType GetTop(SqStack S);
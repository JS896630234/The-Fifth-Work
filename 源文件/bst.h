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
	BSTNode* lchild;  //����
	BSTNode* rchild;  //�Һ���
}BSTNode, * BSTree;
typedef  BSTree SElemType;
typedef struct
{
	SElemType* base;  //��ʼ��ַ
	SElemType* top;
	int stacksize;  //�ռ��С  eg,a[100]
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


void InOderTraverse_re(BSTree bst);								//����ݹ����
void PreOderTraverse_re(BSTree bst);							//����ݹ����
void PostOderTraverse_re(BSTree bst);							//����ݹ����
void InOderTraverse_Nore(BSTree bst);							//����ǵݹ����
void PreOderTraverse_Nore(BSTree bst);							//����ǵݹ����
void PostOderTraverse_Nore(BSTree bst);							//����ǵݹ����
void LevelOderTraverse(BSTree& T);								//�������
void Traverse(BSTree root);										//��������
BSTNode* CreateTree(BSTree);									//��ʼ����
bool Search(BSTree bst, int key, BSTree f, BSTree* p);			//����
BSTNode* CreatNode(int data);									//����ڵ�
bool Insert(BSTree* bst, int key);								//����
BSTNode* FindParent(BSTree bst, BSTNode* child);				//���Ҹ��ڵ�
void Delete(BSTree* bst, int key);								//ɾ��Ԫ��
			


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
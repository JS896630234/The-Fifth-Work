#include "bst.h";
//����������




void InOderTraverse_re(BSTree bst)   //����ݹ����������
{
	if (NULL != bst)
	{
		InOderTraverse_re(bst->lchild);
		printf("%d ", bst->data);
		InOderTraverse_re(bst->rchild);
	}
}

void PreOderTraverse_re(BSTree bst)   //����ݹ����������
{
	if (NULL != bst)
	{
		printf("%d ", bst->data);
		PreOderTraverse_re(bst->lchild);
		PreOderTraverse_re(bst->rchild);
	}
}

void PostOderTraverse_re(BSTree bst)   //����ݹ����������
{
	if (NULL != bst)
	{

		PostOderTraverse_re(bst->lchild);
		PostOderTraverse_re(bst->rchild);
		printf("%d ", bst->data);
	}
}
void InOderTraverse_Nore(BSTree bst) {
	if (bst == NULL) {
		printf("����\n");
		return;
	}
	printf("�ǵݹ���������Ϊ��\n");
	if (bst != NULL)
	{
		BSTree p;
		BSTree q = NULL;
		SqStack S;
		InitStack(S);
		p = bst;

		while (p || !StackEmpty(S)) { //��һֱ����ڵ㷽����
			if (p) {
				Push(S, p);
				p = p->lchild;
			}
			else {
				p = GetTop(S);
				Pop(S, p);
				printf("%d ", p->data);
				p = p->rchild;
			}
		}
	}
	printf("\n\n");
}
void PreOderTraverse_Nore(BSTree bst) {
	if (bst == NULL) {
		printf("����\n");
		return;
	}
	printf("�ǵݹ�ǰ������Ϊ��\n");
	if (bst != NULL)
	{
		BSTree p, q = NULL;

		SqStack S;
		InitStack(S);
		p = bst;

		while (p || !StackEmpty(S)) {
			while (p) {
				//�����ң���һֱ�����ߣ����Ҵ�ӡ���ڵ�
				printf("%d ", p->data);
				Push(S, p);
				p = p->lchild;
			}
			if (!StackEmpty(S)) {
				q = GetTop(S);
				Pop(S, q);
				p = q->rchild;
			}
		}
	}
	printf("\n\n");
}

void PostOderTraverse_Nore(BSTree bst) {
	if (bst == NULL) {
		printf("����\n");
		return;
	}
	printf("�ǵݹ��������Ϊ��\n");
	if (bst != NULL)
	{
		BSTree pCur, pLast = NULL; //pLast �����ϴνڵ�

		SqStack S;
		InitStack(S);
		pCur = bst;


		while (pCur) {

			Push(S, pCur);
			pCur = pCur->lchild;
		}

		while (!StackEmpty(S))
		{
			pCur = GetTop(S);
			Pop(S, pCur);
			if (pCur->rchild == NULL || pCur->rchild == pLast) //����Һ���Ϊ�ջ����Һ��ӱ����ʹ���ֱ�Ӵ�ӡ����
			{
				printf("%d ", pCur->data);
				pLast = pCur;   //��¼��ǰ�ڵ�
			}
			else  {			 //��������ҽڵ�
				Push(S, pCur);
				pCur = pCur->rchild;
				while (pCur)
				{
					Push(S, pCur);
					pCur = pCur->lchild;
				}
			}
		}
	}
	printf("\n\n");
}


//��α�������
void LevelOderTraverse(BSTree& T)
{
	LinkQueue Q = (LinkQueue)malloc(sizeof(Queue));
	InitQueue(Q);
	BSTree p = NULL;
	if (!T)
	{
		printf("����\n");
		return;
	}
	else
	{
		printf("�������Ϊ��\n");
		EnQueue(Q, T);
		while (!EmptyQueue(Q))
		{
			p = getHead(Q);
			DeQueue(Q);
			printf("%d ", p->data);
			if (p->lchild)
				EnQueue(Q, p->lchild);
			if (p->rchild)
				EnQueue(Q, p->rchild);
		}
	}
	printf("\n\n");
}


BSTree CreateTree(BSTree bst) {
	
	int data, i, n;;
	printf("�������ʼ�����Ľڵ����:\n");
	scanf_s("%d", &n);
	if (n == 0) { return 0; }
	printf("�������1��ֵ��");
	scanf_s("%d", &data);
	bst = CreatNode(data);

	for (i = 0; i < n - 1; i++) {
		printf("�������%d��ֵ��", i + 2);
		scanf_s("%d", &data);
		Insert(&bst, data);
	}
	return bst;
}
BSTNode* CreatNode(int data)   //����һ���ڵ㲢���г�ʼ��
{
	BSTNode* pTmp = (BSTNode*)malloc(sizeof(BSTNode));
	if (NULL == pTmp)
	{
		return 0;
	}
	pTmp->data = data;
	pTmp->lchild = NULL;
	pTmp->rchild = NULL;
	
	
	return pTmp;
}


//����
bool Insert(BSTree* bst, int key)
{
	if (NULL == *bst)  //����
	{
		*bst = CreatNode(key);   //������ڵ�
		return true;
	}
	BSTNode* p;
	//���ڶ����������в���Ҫ�����ֵ�Ƿ��Ѿ�����
	if (!Search(*bst, key, NULL, &p))  //�������ʧ�ܣ�����룻��ʱpָ����������һ���ڵ�
	{
		BSTNode* pNew = CreatNode(key);
		if (key < p->data)  //���keyС��p�����ݣ���s��Ϊp������
		{
			p->lchild = pNew;
		}
		else if (key > p->data)  //���key����p�����ݣ���s��Ϊp���Һ���
		{
			p->rchild = pNew;
		}
		return true;  //����ɹ�
	}
	else
	{
		printf("\nֵΪ%d�Ľڵ��Ѿ�����.\n", key);
	}
	return false;
}


BSTNode* FindParent(BSTree bst, BSTNode* child)
{
	if (NULL == bst)
	{
		return NULL;
	}
	//����·�Ҹ��ڵ�
	if (bst->lchild == child || bst->rchild == child)
	{
		return bst;
	}
	else if (NULL != bst->lchild)
	{
		FindParent(bst->lchild, child);
	}
	else
	{
		FindParent(bst->rchild, child);
	}
}


/*
ɾ�������������
(1)��ɾ���Ľڵ��޺��ӣ�˵���ýڵ���Ҷ�ӽڵ㣬ֱ��ɾ
(2)��ɾ���Ľڵ�ֻ�����ӻ����Һ��ӣ�ֱ��ɾ�����������ӻ����Һ��ӷ��ڱ�ɾ�ڵ��λ��
(3)��ɾ���Ľڵ�����Һ��������Һ���
*/
void Delete(BSTree* bst, int key)
{
	if (NULL == *bst)
	{
		printf("����������������\n");
		return;  
	}
	BSTNode* p;
	BSTNode* f = NULL;
	BSTNode* q, * s;
	if (Search(*bst, key, NULL, &p)) //����ֵΪkey�Ľڵ�,��pָ��ýڵ�
	{

		if (NULL == p->lchild && NULL != p->rchild)  //������,���Һ���
		{
			q = p->rchild;
			p->data = q->data;    //��Ϊ�����ڵ�֮�䱾�ʵĲ�ͬ����������Ĳ�ͬ����������ĸ���ַû�й�ϵ
			p->rchild = q->rchild;
			p->lchild = q->lchild;
			free(q);
		}
		else if (NULL == p->rchild && NULL != p->lchild)  //���Һ���,������
		{
			q = p->lchild;
			p->data = q->data;
			p->rchild = q->rchild;
			p->lchild = q->lchild;
			free(q);
		}
		else if (NULL != p->rchild && NULL != p->lchild) //�������ӣ������Һ���
		{
			q = p;
			s = p->lchild;   //�����ӵ����Һ���
			while (s->rchild)
			{
				q = s;
				s = s->rchild;
			}
			p->data = s->data;

			if (q != p)
			{
				q->rchild = p->lchild;
			}
			else
			{
				q->lchild = s->lchild;
			}
			free(s);
		}
		else
		{
			if (*bst == p)   //ֻ��һ�����ڵ�
			{
				free(*bst);
				*bst = NULL;
				return;
			}

			BSTNode* parent = NULL;
			parent=FindParent(*bst, p);
			if (parent->lchild == p)
			{
				parent->lchild = NULL;
			}
			else
			{
				parent->rchild = NULL;
			}
			free(p);
		}
		printf("�����ɾ����\n");
	}
	
	else {
		printf("������ֵΪ%d�Ľڵ㣡\n", key);
	}
}

//���ҳɹ�ʱ��pָ��ֵΪkey�Ľڵ㡣�������ʧ�ܣ���pָ����������һ���ڵ�
bool Search(BSTree bst, int key, BSTree f, BSTree* p)
{
	if (!bst)
	{
		*p = f;
		return false;
	}
	if (bst->data == key)  //���ҳɹ���ֱ�ӷ���
	{
		*p = bst;
		return true;
	}
	else if (bst->data < key)//�ݹ�ķ�����������ҵ�ֵ���ڽڵ�ֵ�����ұߵݹ����
	{
		return Search(bst->rchild, key, bst, p);
	}
	return Search(bst->lchild, key, bst, p);//�ݹ�ķ�����������ҵ�ֵС�ڽڵ�ֵ�����ұߵݹ����
}


void welcome(BSTree root) {

	int choice;
A:	printf("                              ���˵�\n");
	printf("  -----------------------------------------------------------------------\n");
	printf("*****************************************************************************\n");
	printf("                      ��������Ҫ���еĲ�����0-4����\n");
	printf("\n");
	printf("                          1---��ʼ����");
	printf("\n\n");
	printf("                          2---��������");
	printf("\n\n");
	printf("                          3---ɾ������");
	printf("\n\n");
	printf("                          4---������");
	printf("\n\n");
	printf("                          0---�˳��˵�\n");
	printf("\n");
	printf("*****************************************************************************\n");
	printf("  -----------------------------------------------------------------------\n");
	printf("\n");
	printf("��������ţ�0-7����\n");
	while (!(scanf_s("%d", &choice) && getchar() == '\n'))
	{
		while (getchar() != '\n');					//��ջ�����
		printf("���������������������һ�飡\n");	//��ܰ����һ��
	}
	if (choice)
		system("cls");
	fflush(stdin);
	switch (choice)
	{
	case 0:exit(-1);
	case 1:root = CreateTree(root);
		goto A;
	case 2:int data; printf("������Ҫ�����ֵ��"); scanf_s("%d", &data);
		Insert(&root, data); printf("����ɲ������\n"); goto A;
	case 3:int del; printf("������Ҫɾ����ֵ��"); scanf_s("%d", &data);
		Delete(&root, data); goto A;
	case 4:Traverse(root); goto A;
	default:printf("ERROR\n"); goto A;
	};
	return;
}

void Traverse(BSTree root) {

	int choice;
	if (root == NULL) {
		printf("����!���������룡\n");
		return;
	}
B:	printf("                              ��������\n");
	printf("*****************************************************************************\n");
	printf("                      ��������Ҫ���еĲ�����0-7����\n\n");
	printf("             (1)�ݹ�ǰ�����                   (4)����ǰ�����\n\n");
	printf("             (2)�ݹ��������                   (5)�����������\n\n");
	printf("             (3)�ݹ�������                   (6)�����������\n\n");
	printf("             (7)��α�������                   (0)���ز˵�\n\n");
	printf("*****************************************************************************\n");
	printf("���������(0-7)��\n");

	while (!(scanf_s("%d", &choice) && getchar() == '\n'))
	{
		while (getchar() != '\n');					//��ջ�����
		printf("���������������������һ�飡\n");	//��ܰ����
	}
	system("cls");
	switch (choice)
	{
	case 0:welcome(root); break;
	case 1:printf("�ݹ�ǰ������Ϊ��\n");
		PreOderTraverse_re(root); printf("\n"); goto B;
	case 2:		printf("�ݹ���������Ϊ��\n");
		InOderTraverse_re(root);
		printf("\n"); goto B;
	case 3:	printf("�ݹ��������Ϊ��\n");
		PostOderTraverse_re(root);
		printf("\n"); goto B;
	case 4:PreOderTraverse_Nore(root); goto B;
	case 5:InOderTraverse_Nore(root); goto B;
	case 6:PostOderTraverse_Nore(root); goto B;
	case 7:LevelOderTraverse(root); goto B;
	default:printf("ERROR!\n");
	}
}


//*********����Ϊջ����е�����**************************
//*********����Ϊջ����е�����**************************
//*********����Ϊջ����е�����**************************
Status Push(SqStack& S, BSTree e)
{


	if (S.top - S.base == S.stacksize)  //��-��=����
		return ERROR;
	*S.top = e;     //*S.top++=e;  Ԫ��eѹ��ջ��
	S.top++;  //ջ��ָ���1
	return OK;
}

//˳��ջ��ջ
Status Pop(SqStack& S, BSTree e)
{

	if (S.top == S.base) //ջ��
		return ERROR;
	S.top--;
	e = *S.top;  //e=*--S.top;

	return OK;
}

Status InitStack(SqStack& S)
{
	S.base = new SElemType[MAXSIZE];  //����ռ�

	if (!S.base)  //����ʧ��
	{
		printf("�ռ�����ʧ��\n"); return ERROR;
	}
	S.top = S.base;
	S.stacksize = MAXSIZE;

	return OK;
}


//�ж�˳��ջ�Ƿ�Ϊ��
Status StackEmpty(SqStack S)
{
	if (S.top == S.base)
		return OK;
	else
		return ERROR;
}

SElemType GetTop(SqStack S)
{
	SElemType e;
	if (S.top == S.base)
		return ERROR;  //ջ��
	e = *(S.top - 1);   //e=*--S.top;

	return e;
}

void InitQueue(LinkQueue& Q)
{
	Q->front = (QueueNode*)malloc(sizeof(Node));
	Q->rear = Q->front;
	if (!Q->front)
		exit(0);
	Q->rear->next = NULL;
}
void EnQueue(LinkQueue& Q, BSTree T)
{
	QueueNode* s = (QueueNode*)malloc(sizeof(Node));
	s->data = T;
	s->next = NULL;
	Q->rear->next = s;
	Q->rear = s;
	Q->rear->next = NULL;
}
void DeQueue(LinkQueue& Q)
{
	if (Q->front == Q->rear)
	{
		printf("�ն���\n");
	}
	else if (Q->rear == Q->front->next)
	{
		Q->rear = Q->front;
	}
	else
	{
		Q->front = Q->front->next;
	}
}
bool EmptyQueue(LinkQueue Q)
{
	if (Q->front == Q->rear)
		return true;
	else
		return false;
}
BSTree getHead(LinkQueue Q)
{
	if (!EmptyQueue(Q))
	{
		BSTree p = Q->front->next->data;
		return p;
	}
	else return NULL;
}

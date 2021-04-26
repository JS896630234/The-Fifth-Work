#include "bst.h";
//二叉排序树




void InOderTraverse_re(BSTree bst)   //中序递归遍历二叉树
{
	if (NULL != bst)
	{
		InOderTraverse_re(bst->lchild);
		printf("%d ", bst->data);
		InOderTraverse_re(bst->rchild);
	}
}

void PreOderTraverse_re(BSTree bst)   //中序递归遍历二叉树
{
	if (NULL != bst)
	{
		printf("%d ", bst->data);
		PreOderTraverse_re(bst->lchild);
		PreOderTraverse_re(bst->rchild);
	}
}

void PostOderTraverse_re(BSTree bst)   //中序递归遍历二叉树
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
		printf("树空\n");
		return;
	}
	printf("非递归中序排序为：\n");
	if (bst != NULL)
	{
		BSTree p;
		BSTree q = NULL;
		SqStack S;
		InitStack(S);
		p = bst;

		while (p || !StackEmpty(S)) { //先一直向左节点方向走
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
		printf("树空\n");
		return;
	}
	printf("非递归前序排序为：\n");
	if (bst != NULL)
	{
		BSTree p, q = NULL;

		SqStack S;
		InitStack(S);
		p = bst;

		while (p || !StackEmpty(S)) {
			while (p) {
				//父左右，先一直往左走，并且打印父节点
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
		printf("树空\n");
		return;
	}
	printf("非递归后序排序为：\n");
	if (bst != NULL)
	{
		BSTree pCur, pLast = NULL; //pLast 保存上次节点

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
			if (pCur->rchild == NULL || pCur->rchild == pLast) //如果右孩子为空或者右孩子被访问过，直接打印左孩子
			{
				printf("%d ", pCur->data);
				pLast = pCur;   //记录当前节点
			}
			else  {			 //如果存在右节点
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


//层次遍历函数
void LevelOderTraverse(BSTree& T)
{
	LinkQueue Q = (LinkQueue)malloc(sizeof(Queue));
	InitQueue(Q);
	BSTree p = NULL;
	if (!T)
	{
		printf("空树\n");
		return;
	}
	else
	{
		printf("层次排序为：\n");
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
	printf("请输入初始化树的节点个数:\n");
	scanf_s("%d", &n);
	if (n == 0) { return 0; }
	printf("请输入第1个值：");
	scanf_s("%d", &data);
	bst = CreatNode(data);

	for (i = 0; i < n - 1; i++) {
		printf("请输入第%d个值：", i + 2);
		scanf_s("%d", &data);
		Insert(&bst, data);
	}
	return bst;
}
BSTNode* CreatNode(int data)   //生成一个节点并进行初始化
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


//插入
bool Insert(BSTree* bst, int key)
{
	if (NULL == *bst)  //空树
	{
		*bst = CreatNode(key);   //插入根节点
		return true;
	}
	BSTNode* p;
	//先在二叉排序树中查找要插入的值是否已经存在
	if (!Search(*bst, key, NULL, &p))  //如果查找失败，则插入；此时p指向遍历的最后一个节点
	{
		BSTNode* pNew = CreatNode(key);
		if (key < p->data)  //如果key小于p的数据，则将s作为p的左孩子
		{
			p->lchild = pNew;
		}
		else if (key > p->data)  //如果key大于p的数据，将s作为p的右孩子
		{
			p->rchild = pNew;
		}
		return true;  //插入成功
	}
	else
	{
		printf("\n值为%d的节点已经存在.\n", key);
	}
	return false;
}


BSTNode* FindParent(BSTree bst, BSTNode* child)
{
	if (NULL == bst)
	{
		return NULL;
	}
	//两条路找父节点
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
删除分三种情况：
(1)被删除的节点无孩子，说明该节点是叶子节点，直接删
(2)被删除的节点只有左孩子或者右孩子，直接删，并将其左孩子或者右孩子放在被删节点的位置
(3)被删除的节点既有右孩子又有右孩子
*/
void Delete(BSTree* bst, int key)
{
	if (NULL == *bst)
	{
		printf("空树，请重新输入\n");
		return;  
	}
	BSTNode* p;
	BSTNode* f = NULL;
	BSTNode* q, * s;
	if (Search(*bst, key, NULL, &p)) //存在值为key的节点,则p指向该节点
	{

		if (NULL == p->lchild && NULL != p->rchild)  //无左孩子,有右孩子
		{
			q = p->rchild;
			p->data = q->data;    //因为两个节点之间本质的不同在于数据域的不同，而与放在哪个地址没有关系
			p->rchild = q->rchild;
			p->lchild = q->lchild;
			free(q);
		}
		else if (NULL == p->rchild && NULL != p->lchild)  //无右孩子,有左孩子
		{
			q = p->lchild;
			p->data = q->data;
			p->rchild = q->rchild;
			p->lchild = q->lchild;
			free(q);
		}
		else if (NULL != p->rchild && NULL != p->lchild) //既有左孩子，又有右孩子
		{
			q = p;
			s = p->lchild;   //找左孩子的最右孩子
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
			if (*bst == p)   //只有一个根节点
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
		printf("已完成删除！\n");
	}
	
	else {
		printf("不存在值为%d的节点！\n", key);
	}
}

//查找成功时，p指向值为key的节点。如果查找失败，则p指向遍历的最后一个节点
bool Search(BSTree bst, int key, BSTree f, BSTree* p)
{
	if (!bst)
	{
		*p = f;
		return false;
	}
	if (bst->data == key)  //查找成功，直接返回
	{
		*p = bst;
		return true;
	}
	else if (bst->data < key)//递归的方法，如果所找的值大于节点值，则右边递归查找
	{
		return Search(bst->rchild, key, bst, p);
	}
	return Search(bst->lchild, key, bst, p);//递归的方法，如果所找的值小于节点值，则右边递归查找
}


void welcome(BSTree root) {

	int choice;
A:	printf("                              主菜单\n");
	printf("  -----------------------------------------------------------------------\n");
	printf("*****************************************************************************\n");
	printf("                      请输入你要进行的操作（0-4）：\n");
	printf("\n");
	printf("                          1---初始化树");
	printf("\n\n");
	printf("                          2---插入数据");
	printf("\n\n");
	printf("                          3---删除数据");
	printf("\n\n");
	printf("                          4---遍历树");
	printf("\n\n");
	printf("                          0---退出菜单\n");
	printf("\n");
	printf("*****************************************************************************\n");
	printf("  -----------------------------------------------------------------------\n");
	printf("\n");
	printf("请输入序号（0-7）：\n");
	while (!(scanf_s("%d", &choice) && getchar() == '\n'))
	{
		while (getchar() != '\n');					//清空缓存区
		printf("你输入的数据有误，请再输一遍！\n");	//温馨提醒一下
	}
	if (choice)
		system("cls");
	fflush(stdin);
	switch (choice)
	{
	case 0:exit(-1);
	case 1:root = CreateTree(root);
		goto A;
	case 2:int data; printf("请输入要插入的值："); scanf_s("%d", &data);
		Insert(&root, data); printf("已完成插入操作\n"); goto A;
	case 3:int del; printf("请输入要删除的值："); scanf_s("%d", &data);
		Delete(&root, data); goto A;
	case 4:Traverse(root); goto A;
	default:printf("ERROR\n"); goto A;
	};
	return;
}

void Traverse(BSTree root) {

	int choice;
	if (root == NULL) {
		printf("树空!请重新输入！\n");
		return;
	}
B:	printf("                              其他操作\n");
	printf("*****************************************************************************\n");
	printf("                      请输入你要进行的操作（0-7）：\n\n");
	printf("             (1)递归前序遍历                   (4)迭代前序遍历\n\n");
	printf("             (2)递归中序遍历                   (5)迭代中序遍历\n\n");
	printf("             (3)递归后序遍历                   (6)迭代后序遍历\n\n");
	printf("             (7)层次遍历遍历                   (0)返回菜单\n\n");
	printf("*****************************************************************************\n");
	printf("请输入序号(0-7)：\n");

	while (!(scanf_s("%d", &choice) && getchar() == '\n'))
	{
		while (getchar() != '\n');					//清空缓存区
		printf("你输入的数据有误，请再输一遍！\n");	//温馨提醒
	}
	system("cls");
	switch (choice)
	{
	case 0:welcome(root); break;
	case 1:printf("递归前序排序为：\n");
		PreOderTraverse_re(root); printf("\n"); goto B;
	case 2:		printf("递归中序排序为：\n");
		InOderTraverse_re(root);
		printf("\n"); goto B;
	case 3:	printf("递归后序排序为：\n");
		PostOderTraverse_re(root);
		printf("\n"); goto B;
	case 4:PreOderTraverse_Nore(root); goto B;
	case 5:InOderTraverse_Nore(root); goto B;
	case 6:PostOderTraverse_Nore(root); goto B;
	case 7:LevelOderTraverse(root); goto B;
	default:printf("ERROR!\n");
	}
}


//*********以下为栈与队列的内容**************************
//*********以下为栈与队列的内容**************************
//*********以下为栈与队列的内容**************************
Status Push(SqStack& S, BSTree e)
{


	if (S.top - S.base == S.stacksize)  //顶-低=距离
		return ERROR;
	*S.top = e;     //*S.top++=e;  元素e压入栈顶
	S.top++;  //栈顶指针加1
	return OK;
}

//顺序栈出栈
Status Pop(SqStack& S, BSTree e)
{

	if (S.top == S.base) //栈空
		return ERROR;
	S.top--;
	e = *S.top;  //e=*--S.top;

	return OK;
}

Status InitStack(SqStack& S)
{
	S.base = new SElemType[MAXSIZE];  //申请空间

	if (!S.base)  //申请失败
	{
		printf("空间申请失败\n"); return ERROR;
	}
	S.top = S.base;
	S.stacksize = MAXSIZE;

	return OK;
}


//判断顺序栈是否为空
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
		return ERROR;  //栈空
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
		printf("空队列\n");
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

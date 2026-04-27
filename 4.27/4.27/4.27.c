//LeetCode - 用队列实现栈
typedef int QDataType;

typedef struct QueueNode
{
	QDataType val;
	struct QueueNode* next;
}QNode;

typedef struct Queue
{
	QNode* phead;
	QNode* ptail;
	int size;
}Queue;

//初始化
void QueueInit(Queue* pq);
//销毁
void QueueDestroy(Queue* pq);

//入队 出队
void QueuePush(Queue* pq, QDataType x);
void QueuePop(Queue* pq);

//队列元素个数
int QueueSize(Queue* pq);

//队头元素
QDataType QueueFront(Queue* pq);

//队尾元素
QDataType QueueBack(Queue* pq);

//判空
bool QueueEmpty(Queue* pq);


//初始化
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}

//销毁
void QueueDestroy(Queue* pq)
{
	assert(pq);

	QNode* cur = pq->phead;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}

//入队 出队
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("malloc failed!\n");
		return;
	}
	newnode->val = x;
	newnode->next = NULL;

	if (pq->ptail == NULL)
	{
		pq->ptail = pq->phead = newnode;
	}
	else
	{
		pq->ptail->next = newnode;
		pq->ptail = newnode;
	}
	pq->size++;
}
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->size);

	if (pq->phead->next == NULL)
	{
		//一个节点
		free(pq->phead);
		pq->phead = pq->ptail = NULL;
	}
	else
	{
		//多个节点
		QNode* next = pq->phead->next;
		free(pq->phead);
		pq->phead = next;
	}
	pq->size--;
}


//队列元素个数
int QueueSize(Queue* pq)
{
	assert(pq);
	return pq->size;
}

//队头元素
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->phead);

	return pq->phead->val;
}

//队尾元素
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->ptail);

	return pq->ptail->val;
}

//判空
bool QueueEmpty(Queue* pq)
{
	return pq->size == 0;
}

typedef struct
{
	Queue q1;
	Queue q2;
}MyStack;


MyStack* myStackCreate()
{
	//初始化队列
	//直接创建结构体，由于是局部变量，除了函数就销毁了
	//malloc之后这个创建的结构体还在
	MyStack* pst = (MyStack*)malloc(sizeof(MyStack));

	QueueInit(&pst->q1);
	QueueInit(&pst->q2);

	return pst;
}

void myStackPush(MyStack* obj, int x)
{
	//非空队列中push
	if (!QueueEmpty(&obj->q1))
	{
		QueuePush(&obj->q1, x);
	}
	else
	{
		QueuePush(&obj->q2, x);
	}
}

int myStackPop(MyStack* obj)
{
	//在非空队列中，将size-1个元素导入空队列，接着pop最后一个元素
	//假设法
	Queue* empty = &obj->q1;
	Queue* nonempty = &obj->q2;
	if (!QueueEmpty(&obj->q1))
	{
		empty = &obj->q2;
		nonempty = &obj->q1;
	}
	while (QueueSize(nonempty) > 1)
	{
		QueuePush(empty, QueueFront(nonempty));
		QueuePop(nonempty);
	}
	int top = QueueBack(nonempty);
	QueuePop(nonempty);

	return top;
}

int myStackTop(MyStack* obj)
{
	Queue* empty = &obj->q1;
	Queue* nonempty = &obj->q2;
	if (!QueueEmpty(&obj->q1))
	{
		empty = &obj->q2;
		nonempty = &obj->q1;
	}
	return QueueBack(nonempty);
}

bool myStackEmpty(MyStack* obj)
{
	return (QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2));
}

void myStackFree(MyStack* obj)
{
	QueueDestroy(&obj->q1);
	QueueDestroy(&obj->q2);

	free(obj);

}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/
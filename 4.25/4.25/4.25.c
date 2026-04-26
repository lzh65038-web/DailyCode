#include <stdio.h>
#include <stdlib.h>


struct Node 
{
    int val;
    struct Node* next;
    struct Node* random;
};

struct Node* copyRandomList(struct Node* head)
{
    if (head == NULL) return NULL;
    struct Node* cur = head;
    while (cur)
    {
        struct Node* next = cur->next;
        //复制一个新的节点
        struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->val = cur->val;
        newnode->next = cur->next;

        //尾插在cur后面
        newnode->next = cur->next;
        cur->next = newnode;

        cur = next;
    }
    //修改random的指向
    struct Node* pcur = head;
    while (pcur)
    {
        //pcur是原节点，next是复制节点
        struct Node* next = pcur->next;
        if (pcur->random)
            next->random = pcur->random->next;
        else next->random = NULL;
        //pcur只需遍历原节点
        pcur = pcur->next->next;
    }

    struct Node* newhead = NULL;
    struct Node* newtail = NULL;
    //串联复制链表
    while (head)
    {
        struct Node* ansnode = head->next;

        if (newtail == NULL)
        {
            //既是头指针也是尾指针
            newhead = newtail = ansnode;
        }
        else
        {
            //尾插在newtail后面
            newtail->next = ansnode;
            newtail = ansnode;
            free(head);
        }
        head = ansnode;

    }
    return newhead;
}

int main()
{
    //创建五个节点
    struct Node* newnode1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* newnode2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* newnode3 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* newnode4 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* newnode5 = (struct Node*)malloc(sizeof(struct Node));

    newnode1->val = 7; newnode1->next = newnode2; newnode1->random = NULL;
    newnode2->val = 13; newnode2->next = newnode3; newnode2->random = 0;
    newnode3->val = 11; newnode3->next = newnode4; newnode3->random = 4;
    newnode4->val = 10; newnode4->next = newnode5; newnode4->random = 2;
    newnode5->val = 1; newnode5->next = NULL; newnode5->random = 0;

    struct Node* head = newnode1;

    struct Node* cur = copyRandomList(head);

    while (cur)
    {
        printf("%d ", cur->val);
        cur = cur->next;
    }
    printf("\n");

    return 0;
}

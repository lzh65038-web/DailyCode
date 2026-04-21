#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode* next;
};

struct ListNode* CreateList(int n)
{
    //先创建一个节点
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = NULL;
    struct ListNode* tail = (struct ListNode*)malloc(sizeof(struct ListNode));
    tail = head;

    //再创建剩下的节点
    for (int i = 2; i <= n; i++)
    {
        struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newnode->val = i;
        newnode->next = NULL;
        tail->next = newnode;
        tail = newnode;
    }
    tail->next = head;

    return tail;
}

int ysf(int n, int m)
{
    // write code here
    //创建环形链表

    struct ListNode* prev = CreateList(n);
    struct ListNode* cur = prev->next;

    int cnt = 1;
    while (cur->next != prev)
    {
        while(cnt != m)
        {
            cnt++;
            prev = cur;
            cur = cur->next;
        }
        cnt = 1;
        struct ListNode* next = cur->next;
        prev->next = next;
        free(cur);
        cur = next;
    }
    return cur->val;
}

//int ysf(int n, int m)
//{
//    // write code here
//    //创建环形链表
//
//    struct ListNode* prev = CreateList(n);
//    struct ListNode* cur = prev->next;
//
//    int cnt = 1;
//    while (cur->next != prev)
//    {
//        if (cnt == m)
//        {
//            struct ListNode* next = cur->next;
//            prev->next = next;
//            free(cur);
//            cur = next;
//            cnt = 1;
//        }
//        cnt++;
//        prev = cur;
//        cur = cur->next;
//    }
//    return cur->val;
//}


int main()
{
    int n, m;
    scanf_s("%d %d", &n, &m);
    printf("%d", ysf(n, m));

    return 0;
}
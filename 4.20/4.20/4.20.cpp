/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeElements(struct ListNode* head, int val)
{
    //思路一：创建两个指针
    //先处理头节点
    while (head && head->val == val)
    {
        //更改头节点
        head = head->next;
    }

    struct ListNode* cur = head;
    struct ListNode* prev = head;

    while (cur)
    {
        if (cur->val == val)
        {
            //删除cur
            struct ListNode* next = cur->next;
            prev->next = cur->next;
            free(cur);
            cur = next;
        }
        else
        {
            //同时向后走
            prev = cur;
            cur = cur->next;
        }
    }
    return head;
}


struct ListNode* removeElements(struct ListNode* head, int val)
{
    //思路二 
    struct ListNode* cur = head;
    struct ListNode* newhead = NULL;
    struct ListNode* newtail = NULL;

    while (cur)
    {
        if (cur->val != val)
        {
            //加入到新链表中
            if (newhead == NULL)
            {
                //新链表的第一个节点，既是头节点，也是尾节点
                newhead = newtail = cur;
            }
            else
            {
                //尾插即可
                newtail->next = cur;
                newtail = cur;
            }
        }
        cur = cur->next;
    }
    if (newtail != NULL) newtail->next = NULL;

    return newhead;
}



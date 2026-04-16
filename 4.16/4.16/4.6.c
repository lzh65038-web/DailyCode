//链表的中间节点 
struct ListNode* middleNode(struct ListNode* head)
{
    struct ListNode* slow = head, * fast = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

//反转链表
struct ListNode* reverseList(struct ListNode* head)
{
    //双指针
    struct ListNode* newhead = NULL;
    struct ListNode* cur = head;

    while (cur)
    {
        struct ListNode* next = cur->next;
        cur->next = newhead;
        newhead = cur;
        cur = next;
    }
    return newhead;
}

//链表的回文结构
class PalindromeList {
public:

    struct ListNode* middleNode(struct ListNode* head)
    {
        struct ListNode* slow = head, * fast = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    struct ListNode* reverseList(struct ListNode* head)
    {
        //双指针
        struct ListNode* newhead = NULL;
        struct ListNode* cur = head;

        while (cur)
        {
            struct ListNode* next = cur->next;
            cur->next = newhead;
            newhead = cur;
            cur = next;
        }
        return newhead;
    }

    bool chkPalindrome(ListNode* A)
    {
        // write code here
        struct ListNode* mid = middleNode(A);
        struct ListNode* rmid = reverseList(A);

        while (rmid && A)
        {
            if (rmid->val != A->val) return false;
            rmid = rmid->next;
            A = A->next;
        }
        return true;
    }

};

//返回第k个节点
int kthToLast(struct ListNode* head, int k)
{
    struct ListNode* slow = head, * fast = head;
    //先走k步
    while (k--)
    {
        fast = fast->next;
    }
    //同时走
    while (fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow->val;

}

//相交链表
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
{
    //1.遍历链表，看尾节点是否相等
    struct ListNode* curA = headA, * curB = headB;
    //遍历到尾节点直接结束，尾节点不会被++，因此初始化为1
    int lenA = 1, lenB = 1;
    while (curA->next)
    {
        curA = curA->next;
        ++lenA;
    }
    while (curB->next)
    {
        curB = curB->next;
        ++lenB;
    }
    //相等即为相交
    if (curA != curB) return NULL;
    //节点多的链表先走差距步，再同时走
    int gap = abs(lenA - lenB);
    //假设法
    struct ListNode* longlist = headA, * shortlist = headB;
    if (lenA < lenB)
    {
        longlist = headB;
        shortlist = headA;
    }
    //先走差距步
    while (gap--)
    {
        longlist = longlist->next;
    }
    //同时走
    while (longlist != shortlist)
    {
        longlist = longlist->next;
        shortlist = shortlist->next;
    }
    return longlist;
}


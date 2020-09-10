#include <iostream>
#include <vector>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode *addNode(ListNode* l, int val)
{
    if (l == NULL)
    {
        l = new ListNode(val);
        return l;
    }
    ListNode *t = l;
    while(t->next)
    {
        t = t->next;
    }
    t->next = new ListNode(val);
    return l;
}
class Solution
{
public:
     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        ListNode *t1 = l1;
        ListNode *t2 = l2;
        ListNode *ret = NULL;
        while(t1 && t2)
        {
            if (t1->val < t2->val)
            {
                ret = addNode(ret, t1->val);
                t1 = t1->next;
            }
            else
            {
                ret = addNode(ret, t2->val);
                t2 = t2->next;
            }
        }
        ListNode *t = t1 ? t1 : t2;
        while(t)
        {
            ret = addNode(ret, t->val);
            t = t->next;
        }
        return ret;
    }
};

void PrintList(ListNode *l)
{
    while(l)
    {
        cout << l->val << " ";
        l = l->next;
    }

    cout << endl;
}

int main()
{
    Solution S;
    ListNode *l1 = NULL;
    l1 = addNode(l1, 1);
    l1 = addNode(l1, 2);
    l1 = addNode(l1, 4);
    ListNode *l2 = NULL;
    l2 = addNode(l2, 1);
    l2 = addNode(l2, 3);
    l2 = addNode(l2, 5);
    ListNode *ret = S.mergeTwoLists(l1, l2);
    PrintList(ret);
    return 0;
}

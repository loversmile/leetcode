#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

using namespace std;

ListNode* addNode(ListNode *l, int val)
{
    if (l == NULL)
    {
        l = new ListNode(val);
        return l;
    }
    ListNode* tmp = l;
    while(tmp->next)
        tmp = tmp->next;

    tmp->next = new ListNode(val);
    return l;
}

void PrintNode(ListNode* l)
{
    ListNode *tmp = l;
    while(tmp)
    {
        cout << tmp->val << " -> ";
        tmp = tmp->next;
    }
    cout << endl;
}

class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode *l2)
    {
        ListNode* ret = NULL;
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        int plus = 0;
        while(t1 && t2)
        {
            int num = (t1->val + t2->val + plus) % 10;
            plus = (t1->val + t2->val + plus )/10;
            t1 = t1->next;
            t2 = t2->next;
            if (ret == NULL)
            {
                ret = new ListNode(num);
            }
            else
            {
                ret = addNode(ret, num);
            }
        }
        if (t1 == NULL && t2 == NULL && plus == 1)
        {
            ret = addNode(ret, 1);
            plus = 0;
        }
        else
        {
            ListNode *t = t1 ? t1 : t2;
            while (t)
            {
                int num = (t->val + plus) % 10;
                plus = (t->val + plus) / 10;
                t = t->next;
                ret = addNode(ret, num);
            }
            if (plus == 1)
            {
                ret = addNode(ret, 1);
            }
        }
        return ret;
    }
};

int main()
{
    Solution S;

    ListNode* l1 = new ListNode(2);
    l1 = addNode(l1, 4);
    l1 = addNode(l1, 6);
    l1 = addNode(l1, 9);
    l1 = addNode(l1, 9);

    ListNode* l2 = new ListNode(5);
    l2 = addNode(l2, 6);
    l2 = addNode(l2, 4);

    PrintNode(l1);
    PrintNode(l2);

    ListNode* r = S.addTwoNumbers(l1, l2);
    PrintNode(r);

    return 0;
}

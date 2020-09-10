#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;

        ListNode* mid = head;
        ListNode* fast = head;

        while(fast->next != nullptr && fast->next->next != nullptr)
        {
            mid = mid->next;
            fast = fast->next->next;
        }

        ListNode* halfback = reverseLinked(mid->next);
        ListNode* h1 = head;
        ListNode* h2 = halfback;

        while(h2 != nullptr)
        {
            if (h1->val != h2->val) return false;
            h1 = h1->next;
            h2 = h2->next;
        }

        return true;
    }

    ListNode* reverseLinked(ListNode* head)
    {
        ListNode* cur = head;
        ListNode* prev = nullptr;

        while (cur != nullptr)
        {
            ListNode* tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        
        return prev;
    }
};

int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    //head->next->next->next = new ListNode(1);

    Solution S;
    cout << S.isPalindrome(head) << endl;

    return 0;
}
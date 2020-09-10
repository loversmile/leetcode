#include <iostream>
#include <queue>

using  namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    ListNode* getMid(ListNode* first, ListNode* last) {
        ListNode* fast = first;
        ListNode* slow = first;

        while(fast != last && fast->next != last) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
    TreeNode* buildTreeNode(ListNode* left, ListNode* right)
    {
        if (left == right) return nullptr;

        ListNode* mid = getMid(left, right);
        TreeNode* root = new TreeNode(mid->val);
        root->left = buildTreeNode(left, mid);
        root->right = buildTreeNode(mid->next, right);

        return root;
    }

/*     TreeNode* buildTree(ListNode* left, ListNode* right)
    {
        if (left == right) return nullptr;
        TreeNode* root = new TreeNode(left->val);

        TreeNode* tmp = root;
        ListNode* ltmp = left->next;
        while(ltmp != right) {
            tmp->right = new TreeNode(ltmp->val);
            tmp = tmp->right;
            ltmp = ltmp->next;
        }

        return root;
    } */
    TreeNode* sortedListToBST(ListNode* head) {
        return buildTreeNode(head, nullptr);
/*         ListNode* mid = getMid(head, nullptr);
        TreeNode* root = new TreeNode(mid->val);
        root->left = buildTree(head, mid);
        root->right = buildTree(mid->next, nullptr);

        return root; */
    }
};

// void printTreeNode(TreeNode* root)
// {
//     if (root == nullptr) {
//         cout << "null" << endl;
//         return;
//     }
//     cout << root->val << endl;
//     printTreeNode(root->left);
//     printTreeNode(root->right);
// }

void printTreeNode(TreeNode* root)
{
    if (root == nullptr) {
        cout << "null" << endl;
        return;
    }
    queue<TreeNode*> q;

    q.push(root);
    cout << root->val << endl;

    while(!q.empty())
    {
        int size = q.size();

        for(int i = 0; i < size; ++i)
        {
            TreeNode * front = q.front();
            q.pop();

            if (front->left)
            {
                q.push(front->left);
                cout << front->left->val << endl;
            } else if (front->right) { cout <<  "null" << endl;}
            if (front->right)
            {
                q.push(front->right);
                cout << front->right->val << endl;                
            } else if (front->left) { cout <<  "null" << endl;}
        }
    }
}

int main()
{
    Solution S;

    ListNode *head = new ListNode(-10);
    head->next = new ListNode(-3);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(5);
    head->next->next->next->next = new ListNode(9);

    // TreeNode *root = new TreeNode(0);
    // root->left = new TreeNode(-3);
    // root->left->left = new TreeNode(-10);
    // root->right = new TreeNode(9);
    // root->right->left = new TreeNode(5);

    TreeNode *root = S.sortedListToBST(head);

    printTreeNode(root);

}
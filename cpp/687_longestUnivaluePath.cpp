#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int ans = 0;

    int getValue(TreeNode* root)
    {
        if (root == nullptr) return 0;
        int maxLen = 0;

        int maxLeft  = getValue(root->left) ;
        int maxRight  = getValue(root->right);

        if (root->left && root->left->val == root->val
            && root->right && root->right->val == root->val)
        {
            ans = max(ans, maxLeft + maxRight + 2);
        }

        if (root->left && root->left->val == root->val)
        {
            maxLen = maxLeft + 1;
        }

        if (root->right && root->right->val == root->val)
        {
            maxLen = max(maxLen, maxRight + 1);
        }

        ans = max(ans, maxLen);

        return  maxLen;
    }

    int longestUnivaluePath(TreeNode* root) {
        getValue(root);
        return ans;
    }
};

int main()
{
    // TreeNode* head = new TreeNode(5);
    // head->left = new TreeNode(4);
    // head->right = new TreeNode(5);

    // head->left->left = new TreeNode(1);
    // head->left->right = new TreeNode(1);

    // head->right->right = new TreeNode(5);

    TreeNode* head = new TreeNode(1);
    head->left = new TreeNode(4);
    head->right = new TreeNode(5);

    head->left->left = new TreeNode(4);
    head->left->right = new TreeNode(4);

    head->right->right = new TreeNode(5);

    Solution S;

    cout << S.longestUnivaluePath(head) << endl;

    return 0;
}
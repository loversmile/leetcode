#include <iostream>
//#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int height(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

//        return height(root->left) > height(root->right) ? (height(root->left) + 1) : (height(root->right) + 1);
        return max(height(root->left), height(root->right)) + 1;
    }

    int abs(int a , int b) {
        int res = a - b;
        if (res < 0) return -res;
        return res;
    }

    bool isBalanced(TreeNode* root) {
        if (nullptr == root) return true;
        return abs(height(root->left), height(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};

int main()
{
    Solution S;

    TreeNode *tn = new TreeNode(1);

    tn->left = new TreeNode(2);

    //tn->left->left = new TreeNode(3);
    

    cout << S.isBalanced(tn) << endl;
}
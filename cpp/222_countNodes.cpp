#include <iostream>

#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    int countLevels(TreeNode* root)
    {
        int level = 0;
        while(root)
        {
            root = root->left;
            ++level;
        }
        return level;
    }
    int countNodes(TreeNode* root) {
        //return root == NULL ? 0 : 1 + countNodes(root->left) + countNodes(root->right);
/*        if (root == NULL) return 0;
        int left_level = countLevels(root->left);
        int right_level = countLevels(root->right);
        if (right_level == left_level)
        {
            // 2^left_level
            return (1 << left_level) - 1 + 1 + countNodes(root->right);
        }
        else
        {
            return (1 << right_level) - 1 + 1 + countNodes(root->left);
        }*/
        if (root == NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* front = q.front();
            q.pop();
            cout << front->val << "";
            if(front->left)
            {
                q.push(front->left);
            }
            if (front->right)
            {
                q.push(front->right);
            }
        }
        return 0;
    }
};


int main()
{
    Solution S;
    TreeNode *root = new TreeNode(1);

    root->left  = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    //cout << S.countNodes(root) << endl;
    return 0;
}
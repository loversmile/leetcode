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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            vector<int> level;
            for(int i = 0; i < size; ++i)
            {
                TreeNode* front = q.front();
                q.pop();
                level.push_back(front->val);
                if(front->left)
                {
                    q.push(front->left);
                }
                if (front->right)
                {
                    q.push(front->right);
                }
            }
            res.push_back(level);
        }
        return res;
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

    vector<vector<int>> res;
    res = S.levelOrder(root);

    for (auto r: res)
    {
        for(auto rr : r)
        {
            cout << rr << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
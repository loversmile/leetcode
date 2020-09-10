#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        vector<int> rt;
        if (root == NULL)
            return ret;
        if (root->left == NULL) {
            ret.push_back(root->val);
        } else {
            ret = inorderTraversal(root->left);
            ret.push_back(root->val);
        }
        for (int i = 0; i < ret.size(); i++)
        {
            rt.push_back(ret[i]);
        }
        if (root->right == NULL) {
            
        } else {
            ret = inorderTraversal(root->right);
            for (int i = 0; i < ret.size(); i++)
            {
                rt.push_back(ret[i]);
            }
        }
        
        
        
        return rt;
    }
};

int main()
{
    Solution S;
    return 0;
}

#include <iostream>
#include <vector>

#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    int next_int(string::iterator &begin, string::iterator &end) {
        int res = 0;
        while(begin < end && *begin != '-') res = res * 10 + (*(begin++) - '0');
        return res;
    }

    int cnt_dep(string::iterator &begin, string::iterator &end) {
        auto last = begin;
        while(begin < end && *begin == '-') begin++;
        return begin - last;
    }

    TreeNode* recoverFromPreorder(string S) {
        int len = S.length();
        if (len == 0) return nullptr;

        auto begin = S.begin(), end = S.end();

        TreeNode* node = new TreeNode(next_int(begin, end));

        stack<TreeNode*> stk({node});

        while(begin < end)
        {
            int dep = cnt_dep(begin, end);
            node = new TreeNode(next_int(begin, end));
            while(stk.size() > dep)
            {
                stk.pop();
            }
            if(stk.top()->left) stk.top()->right = node;
            else stk.top()->left = node;

            stk.push(node);
        }
        while(stk.size() > 1) stk.pop();
        return stk.top();
    }
};


int main()
{
    Solution S;
    string s = "1-2--3--4-5--6--7";
    TreeNode * node = S.recoverFromPreorder(s);
    cout << node->val << endl;
    cout << node->left->val << endl;
    cout << node->right->val << endl;
    return 0;
}

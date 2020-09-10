#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "";

        queue<TreeNode*> q;
        q.push(root);

        string res;
        while(!q.empty())
        {
            TreeNode* front = q.front();
            q.pop();
            if(front)
            {
                res += to_string(front->val);
                res += ",";
                q.push(front->left);
                q.push(front->right);

            }
            else
            {
                res += "null,";
            }
        }
        return res;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "") return nullptr;
        vector<string> sp = split_str(data);
        if (sp[0] == "null") return nullptr;


        queue<TreeNode*> q;
        q.push(new TreeNode(stoi(sp[0])));

        TreeNode *res = q.front();
        for(int i = 1; i < sp.size();)
        {
            if (sp[i] != "null")
            {
                auto p = new TreeNode(stoi(sp[i]));
                q.push(p);
                q.front()->left = p;
            }
            ++i;
            if (sp[i] != "null")
            {
                auto p = new TreeNode(stoi(sp[i]));
                q.push(p);
                q.front()->right = p;
            }
            ++i;
            q.pop();
        }
/*        for(auto s : sp)
        {
            cout << s << " ";
        }cout << endl;*/
        return res;   
    }

    vector<string> split_str(string& data)
    {
        int start = 0;
        vector<string> res;
        while(1)
        {
            auto end = data.find(',', start);
            if (end == string::npos)break;
            res.push_back(data.substr(start, end-start));
            start = end + 1;
        }
        return res;//move(res);
    }

};

int main()
{
    Codec S;
    TreeNode *root = new TreeNode(1);

    root->left  = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    string res;
    res = S.serialize(root);
    string r = "1,2,3,null,null,4,5,null,null,null,null";
    S.deserialize(r);

 

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> tmp;
    vector<vector<int>> res;

    void dfs(int cur, int n, int k)
    {
        if (tmp.size() + (n - cur + 1) < k)
            return;

        if (tmp.size() == k) {
            res.push_back(tmp);
            return;
        }

        tmp.push_back(cur);
        dfs(cur + 1, n, k);
        tmp.pop_back();
        dfs(cur + 1, n, k);
    }

    vector<vector<int>> combine(int n, int k) {
        dfs(1, n, k);

        return res;
    }
};

int main()
{
    Solution S;
    vector<vector<int>> res;

    res = S.combine(5, 2 );


    for (auto a : res)
    {
        for(auto r : a)
        {
            cout << r << " ";
        }
        cout << endl;
    }


    return 0;
}
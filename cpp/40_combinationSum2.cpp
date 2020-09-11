#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void dfs(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>& comb, int idx)
    {
        if (target == 0) {
            res.emplace_back(comb);
            return;
        }

        if (idx == candidates.size() || idx < 0) return;

        int len = candidates.size();
        for (int i = idx; i < len; ++i)
        {
            if (i > idx && candidates[i - 1] == candidates[i])//用来去重，只用当前的值，这样当前一样的还是会被用上
                continue;
            if (target - candidates[i] >= 0) {
                comb.emplace_back(candidates[i]);
                dfs(candidates, target - candidates[i], res, comb, i + 1);
                comb.pop_back();
            } else {
                return;
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> comb;

        sort(candidates.begin(), candidates.end());

        dfs(candidates, target, res, comb, 0);

        return res;
    }
};

int main()
{
    Solution S;

    // vector<int> candidates = {10,1,2,7,6,1,5};
    // int target = 8;

    vector<int> candidates = {2,5,2,1,2};
    int target = 5;

    vector<vector<int>> res;
    res = S.combinationSum2(candidates, target);

    for (auto a : res)
    {
        for (auto r: a)
        {
            cout << r << " ";
        }
        cout << endl;
    }

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>& combine, int idx)
    {
        if (idx == candidates.size()) return;
        if (target == 0) {
            res.emplace_back(combine);
            return;
        }

        dfs(candidates, target, res, combine, idx + 1);

        if (target - candidates[idx] >= 0)
        {
            combine.emplace_back(candidates[idx]);
            dfs(candidates, target - candidates[idx], res, combine, idx);
            combine.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> combine;

        dfs(candidates, target, res, combine, 0);

        return res;
    }
};

int main()
{
    Solution S;

    vector<int> candidates = {2,3,5,7};
    int target = 8;

    vector<vector<int>> res;
    res = S.combinationSum(candidates, target);

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
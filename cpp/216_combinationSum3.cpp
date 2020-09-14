#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
void dfs(vector<vector<int>>& res, vector<int>& line, int k, int n, int idx)
{
    if (k == line.size() && n == 0) {
        res.push_back(line);
        return;
    }

    if (n < 0) return;

    for( int i = idx; i <=9 ; ++i)
    {
        line.push_back(i);
        dfs(res, line, k, n - i, i + 1);
        line.pop_back();
    }


}
vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> res;
    vector<int> line;
    dfs(res, line, k, n, 1);
    return res;
}
};

int main()
{
    Solution S;

    vector<vector<int>> res;

    res = S.combinationSum3(3, 9);

    for(auto r : res)
    {
        for(auto a : r)
        {
            cout << a << " ";
        }
        cout << endl;
    }

}
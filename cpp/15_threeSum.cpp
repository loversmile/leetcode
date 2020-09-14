#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int size = nums.size();

        for(int i = 0; i < size - 2; ++i)
        {
            int k = size - 1;

            if (i > 0 && (nums[i] == nums[i - 1]))
            {
                continue;
            }
            for(int j = i + 1; j < size -1; ++j)
            {
                if (j > i + 1 && (nums[j] == nums[j - 1]))
                {
                    continue;
                }
                while( j < k && nums[j] + nums[k] + nums[i] > 0)
                {
                    --k;
                }
                if (j == k)
                {
                    break;
                }
                if (nums[j] + nums[k] + nums[i] == 0)
                {
                    res.push_back({nums[i], nums[j], nums[k]});
                }
            }
        }
        return res;
    }
};

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res;
    Solution S;
    res = S.threeSum(nums);

    for(auto r: res)
    {
        for(auto rr: r)
        {
            cout << rr << " ";
        }
        cout << endl;
    }
    cout << endl;
}
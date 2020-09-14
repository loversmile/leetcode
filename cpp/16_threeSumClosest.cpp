#include <iostream>

#include <vector>

using namespace std;


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        /*int size = nums.size();

        int res = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < size - 2; ++i)
        {
            for (int j = i + 1; j < size - 1; ++j)
            {
                for(int k = size - 1; k > j; --k)
                {
                    int sum = nums[i] + nums[j] + nums[k];
                    res = abs(sum - target) < abs(res - target) ? sum : res; 
                }
            }
        }
        return res;*/

        int size = nums.size();
        sort(nums.begin(), nums.end());
        int res = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < size; ++i)
        {
            int start = i + 1, end = size - 1;
            while(start < end)
            {
                int sum = nums[i] + nums[start] + nums[end];
                res = abs(sum - target) < abs(res - target) ? sum : res; 
                if (sum > target) --end;
                else if (sum < target) ++start;
                else return res;
            }
        }
        return res;
    }
};

int main()
{
    vector<int> nums = {-1,2,1,-4};
    int target = 1;


    Solution S;
    cout << S.threeSumClosest(nums, target) << endl;

    return 0;
}
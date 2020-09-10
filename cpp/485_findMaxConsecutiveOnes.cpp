#include <iostream>

#include <vector>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;
        int max_count = 0;
        int tmp_count = 0;
        for(int i = 0; i < size; ++i)
        {
            if (nums[i] == 1)
            {
                tmp_count++;
                //max_count = max_count < tmp_count ? tmp_count : max_count;
                continue;
            }
            //else
            //{
                max_count = max_count < tmp_count ? tmp_count : max_count;
                tmp_count = 0;
            //}
        }
        //return max_count;
        return max_count < tmp_count ? tmp_count : max_count;
    }
};

int main()
{
    Solution S;

    vector<int> nums = {1,1,0,1,1,1};

    int res = S.findMaxConsecutiveOnes(nums);

    cout << res << endl;

    return 0;
}

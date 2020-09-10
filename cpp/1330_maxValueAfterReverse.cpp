#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {
        int res;
        int len = nums.size();

        int sum = 0;
        int l = -100000;
        int r = 100000;
        for (int i = 0; i < len - 1; i++)
        {
            sum += abs(nums[i] - nums[i + 1]);
            l = max(l, min(nums[i], nums[i + 1]));
            r = min(r, max(nums[i], nums[i + 1]));
        }
        res = max(sum, sum + (l -r)*2);

        //临界情况交换的考虑
        for (int i = 1; i < len - 1; i++)
        {
            int sub = abs(nums[0] - nums[i + 1]) - abs(nums[i] - nums[i+1]);
            res = max(res, sum + sub);
            sub = abs(nums[len - 1] - nums[i - 1]) - abs(nums[i] - nums[i - 1]);
            res = max(res, sum + sub);
        }

        return res;
    }
};

int main()
{
    Solution S;

    vector<int> nums = {2,4,9,24,2,1,10};
    cout << S.maxValueAfterReverse(nums) << endl;
    return 0;
}

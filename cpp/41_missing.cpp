#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
        vector<int> t_nums;
        int i = 0;
        for ( i = 0; i < size; i++)
        {
            t_nums.push_back(0);
        }
        for ( i = 0; i < size; i++)
        {
            if (nums[i] <= size && nums[i] > 0)
            {
                t_nums[nums[i] - 1] = 1;
            }
        }
        for (i = 0; i < size; i++)
        {
            if (t_nums[i] == 0)
            {
                break;
            }
        }
        return i + 1;
    }
};

int main()
{
    Solution sl;
    vector<int> in;
    in.push_back(2);
    in.push_back(0);
    in.push_back(1);
    int ret = sl.firstMissingPositive(in);
    cout << ret << endl;
}

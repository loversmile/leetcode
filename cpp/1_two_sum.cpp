#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int size = nums.size();
        vector<int> ret;
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (target - nums[i] == nums[j])
                {
                    ret.push_back(i);
                    ret.push_back(j);
                    return ret;
                }
            }
        }
        return ret;
    }
};

void PrintVector(vector<int> vct)
{
    for (int i = 0; i < vct.size(); i++)
    {
        cout << vct[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> vi = {2,4,5,6};
    Solution S;
    vector<int> ret = S.twoSum(vi, 8);
    PrintVector(ret); 
}

#include <iostream>
#include <vector>
//[2,0,0] true
//[2,0] true
//[0] true
//[1] true
//[2,3,1,1,4] true
//[3,2,1,0,4] false
//[7,2,0,0,1,0,0] true
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int size = nums.size();
        if (size == 1)
            return true;

        for (int i = size - 1; i >0; i--)
        {
            int find = 0;
            for(int j = i - 1; j >=0; j--)
            {
                if (nums[j] >= i - j)
                {
                    find = 1;
                    break;
                }
            }
            if (find != 1)
                return false;
        }
        return true;
    }
    bool canJump2(vector<int> &nums)
    {
        int size = nums.size();
        if (size == 1)
            return true;

        int zero = 0;
        int find = 0;
        for (int i = 0; i < size; i++)
        {
            find = 0;
            if (nums[i] == 0)
                zero++;
            else
                zero = 0;

            for (int j = i - zero; j >=0; j--)
            {
                if (nums[j] > i - j)
                {
                    find = 1;
                    break;
                }
                if (i == size - 1 && nums[j] == i - j)
                {
                    find = 1;
                    break;
                }
            }
            if (find != 1)
                return false;
        }
        return true;
    }
};

int main()
{
    Solution S;
    vector<int> v;
    //v.push_back(5);
    //v.push_back(2);
    //v.push_back(0);
    //v.push_back(0);
    v.push_back(1);
    v.push_back(0);
    v.push_back(0);
    bool ret = S.canJump(v);
    bool ret2 = S.canJump2(v);
    cout << ret << endl;
    cout << ret2 << endl;
    return 0;
}

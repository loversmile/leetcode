#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        //(j-i) * y
        int length = height.size();
        if (length < 2)
        {
            return 0;
        }

        int l = 0;
        int r = length - 1;
        int y = 0;
        int max = 0;

        while(l < r)
        {
            int y = height[l] < height[r] ? height[l] : height[r];
            max = y * (r - l) > max ? y * (r - l) : max;
            if (height[l] < height[r])
            {
                ++l;
            }
            else
            {
                --r;
            }
        }
        return max;
    }
};

int main()
{
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    Solution S;
    cout << S.maxArea(height) << endl;
};

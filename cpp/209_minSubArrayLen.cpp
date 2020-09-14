#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int binarySearch(vector<int>& nums, int low, int high, int key)
    {
        while (low <= high)
        {
            int mid = (low + high) >> 1;
            if (nums[mid] == key) return mid;
            if (nums[mid] < key)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low;
    }
    int minSubArrayLen(int s, vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;
        vector<int> sums(size + 1, 0);

        int res = INT_MAX;

        for (int i = 0; i < size; ++i)
        {
            sums[i + 1] = sums[i] + nums[i];
        }
        for(int i = 1; i < size + 1; ++i)
        {
            int target = sums[i - 1] + s;
            int found = binarySearch(sums, i, size + 1, target);

            if (found <= size)
            {
                res = res < (found - i + 1 )? res : (found - i + 1 );
            }
        }

        return res == INT_MAX ? 0 : res;
    }
};

class Solssution {
public:
    int binarySearch(vector<int>& nums, int low, int high, int key)
    {
        while (low <= high)
        {
            int mid = (low + high) >> 1;
            if (nums[mid] == key) return mid;
            if (nums[mid] < key)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low;
    }
    int minSubArrayLen(int s, vector<int>& nums) {
/*        int size = nums.size();

        if (size == 0) return 0;
        int res = INT_MAX;

        int start = 0, end = 0;
        int sum = 0;

        while(end < size)
        {
            sum += nums[end];
            while(sum >= s)
            {
                res = res < (end - start + 1) ? res : (end - start + 1);
                sum -= nums[start];
                ++start;
            }
            ++end;
        }

        return res == INT_MAX ? 0 : res;*/
        int size = nums.size();
        if (size == 0) return 0;
        vector<int> sums(size + 1, 0);

        int res = INT_MAX;

        for (int i = 0; i < size; ++i)
        {
            sums[i + 1] = sums[i] + nums[i];
        }
        for(int i = 1; i < size + 1; ++i)
        {
            int target = sums[i - 1] + s;
            int found = binarySearch(sums, i, size + 1, target);
            cout << found;

            if (found <= size)
            {
                res = res < (found - i + 1 )? res : (found - i + 1 );
            }
        }

        return res == INT_MAX ? 0 : res;
    }
};


int main()
{
    Solution S;

    vector<int> test = {1,2,3,4,5,6,7,8};

    cout << S.binarySearch(test, 0, 7, 9) << endl;

    int s = 7;

    vector<int> nums = {2,3,1,2,4,3};

    cout << S.minSubArrayLen(s, nums) << endl;

    return 0;
}
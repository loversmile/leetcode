#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void siftDown(vector<int>& nums, int start, int end)
    {
        int left = start * 2 + 1;
        int largest;
        while(left <= end)
        {
            largest = start;
            // 此时节点有左孩子，判断是否需要更换最大位置
            if (nums[left] > nums[largest]) largest = left;
             // 判断 start 是否有右孩子，且是否需要更换最大位置
            if (left + 1 <= end && nums[left + 1] > nums[largest]) largest = left + 1;
            if (start != largest)
            {
                int tmp = nums[start];
                nums[start] = nums[largest];
                nums[largest] = tmp;
            }
            else
            {
                return;
            }
            start = largest;
            left = 2 * start + 1;
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();

        for(int i = len / 2 - 1; i >= 0; --i)
        {
            siftDown(nums, i, len - 1);
        }

        int end = len - 1;
        while(end > 0)
        {
            int tmp = nums[0];
            nums[0] = nums[end];
            nums[end] = tmp;

            if (len - end >= k) break;
            --end;
            siftDown(nums, 0, end);
        }

        return nums[len - k];
    }
};

int main()
{
    Solution S;
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    int k = 4;
    cout << S.findKthLargest(nums, k) << endl;

    return 0;
}
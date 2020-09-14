#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
    	/*unordered_map<int, int> count; O(n)

    	int size = nums.size();

    	for (int i = 0; i < size; i++)
    	{
    		if (count[nums[i]] > 0)
    		{
    			return nums[i];
    		}
    		count[nums[i]]++;
    	}
    	return -1;*/
    	int left = 0;
    	int right = nums.size() - 1; // shuzi 1-4, geishu 5+

    	while(left < right)
    	{
			int mid = left + (right - left) / 2;
			int count = 0;
			for(int num: nums)
			{
				if(num <= mid)
				{
					count++;
				}
			} 
			if (count > mid)
			{
				right = mid;
			}
			else
			{
				left = mid + 1;
			}
    	}
    	return left;
    }
};

int main()
{
	Solution s;
	vector<int> vi = {3,1,3,4,2};
	int res = s.findDuplicate(vi);
	cout << res << endl;
}
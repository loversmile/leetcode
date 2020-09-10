#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
/*    vector<int> productExceptSelf(vector<int>& nums) {
    	int size = nums.size();
    	// 当前位置的值的前面*后面
    	vector<int> front(size);
    	if (size == 0)
    		return front;

    	int m = 1;
    	for(int i = 0; i < size; i++)
    	{
    		front[i] = m;
    		m *= nums[i]; 
    	}

    	m = 1;
    	//这里用来求后面，front 直接用来存结果
    	for(int i = size - 1; i >= 0; i--)
    	{
    		front[i] *= m;
    		m *= nums[i];
    	}
    	return front;
    }*/

    vector<int> productExceptSelf(vector<int>& nums) {
		int size = nums.size();
		vector<int> res(size, 1);

		int left = 1, right = 1;
		for(int i = 0, j = size - 1; i < size; i++, j--)
		{
			res[i] *= left; res[j] *= right;
			left *= nums[i]; right *= nums[j];
		}
		return res;

    }
};

int main()
{
	Solution s;
	vector<int> v = {1,2,3,4};

	std::vector<int> res;

	res = s.productExceptSelf(v);

	for(auto r: res)
	{
		cout << r << " ";
	}
	cout << endl;

	return 0;
}
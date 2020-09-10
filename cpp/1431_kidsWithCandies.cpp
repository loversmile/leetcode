#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    	int size = candies.size();
    	vector<bool> res;
    	int max = candies[0];
    	for(int i = 1; i < size; ++i)
    	{
    		max = candies[i] > max ? candies[i] : max;
    	}

    	for(int i = 0; i < size; ++i)
    	{
    		if (candies[i] + extraCandies>= max)
    		{
    			res.push_back(true);
    		}
    		else
    		{
    			res.push_back(false);
    		}
    	}	
    	return res;
    }
};

int main()
{
	Solution s;

	vector<int> v = {2,3,5,1,3};
	int extraCandies = 3;

	vector<bool> res ;

	res = s.kidsWithCandies(v, extraCandies);

	for (bool r: res)
	{
		cout << r << endl;
	}

	return 0;
}
#include <iostream>

using namespace std;


class Solution {
public:
    int hammingWeight(uint32_t n)
    {
    	int count = 0;
    	for (int i = 0; i < 32; i++)
    	{
    		if (n & 0X0001 == 1)
    		{
    			count++;
    		}
    		n >>= 1;
    	}
    	return count;
    }
};

int main()
{
	Solution s;
	//string s ;
	cout << s.hammingWeight((uint32_t)0XFF01) << endl; //9

	return 0;
}
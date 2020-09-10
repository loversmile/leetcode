#include <iostream>

using namespace std;


class Solution {
public:
    int reverseBits(uint32_t n)
    {
    	uint32_t result = 0X0001 & n;
    	for (int i = 1; i < 32; i++)
    	{
    		n >>= 1;
            result <<= 1;
            result += 0X0001 & n;
    	}
    	return result;
    }
};

int main()
{
	Solution s;
	//string s ;
	cout << hex << s.reverseBits((uint32_t)0XFF01) << endl; //9

	return 0;
}
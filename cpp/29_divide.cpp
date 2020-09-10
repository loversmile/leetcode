#include <iostream>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
    	int res = 0;
        if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0))
        	res = div(abs(dividend), abs(divisor));
        if ((dividend < 0 && divisor > 0)||(dividend > 0 && divisor < 0))
        {
        	res = -div(abs(dividend), abs(divisor)) ;
        }

        return res;
    }

    int div(long a, long b)
    {
    	int count = 0;
    	if (a < b) return 0;

    	long res = b;
    	while(a > res)
    	{
    		count++;
    		res += b;
    	}
    	return count;
    }
};

int main()
{
	Solution s;
	int a, b;
	cin >> a;
	cin >> b;
	int res = s.divide(a, b);
	cout << res << endl;
	return res ;
}
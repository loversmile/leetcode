#include <iostream>
using namespace std;

class Solution {
public:
	int res = 0;
    int sumNums(int n) {
    	// int ret = 0;
    	/*bool x = n > 1 && sumNums(n - 1) > 0;
    	res += n;
    	return res;*/
    	n > 1 && (n += sumNums(n - 1));
    	return n;
/*    	if (n == 1)
    	{
    		return 1;
    	}

    	return n + sumNums(n - 1);	*/
    }
};

int main()
{
	Solution s;
	int input;
	cin >> input;

	cout << s.sumNums(input) << endl;
}
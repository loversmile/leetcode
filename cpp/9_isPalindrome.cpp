#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
/*        if (x < 0) return false;
        if (x < 10) return true;
        vector<int> vec;
        while(x)
        {
        	vec.push_back(x % 10);
        	x /= 10;
        }
        int size = vec.size();
        for(int i = 0; i < size / 2; ++i)
        {
        	if (vec[i] != vec[size - 1 -i])
        		return false;
        }
    	return true;*/
    	if ( x < 0 || (x % 10 == 0 && x != 0)) return false;
    	int tmp = 0;

    	while( x > tmp)
    	{
    		tmp = tmp * 10 + x % 10;
    		x /= 10;
    	}

    	return x == tmp || x == tmp / 10; //偶数长和奇数长

    }
};

int main()
{
	Solution s;
	int a ;
	cin >> a;
	cout << s.isPalindrome(a) << endl;

	return 0;
}
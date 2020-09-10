#include <iostream>

using namespace std;

class Solution {
public:
/*	int getLength(int num)
	{
		if ( num < 10)
		{
			return 1;
		}
		int count = 1;
		while (num /= 10)
		{
			count++;
		}
		return count;
	}*/
	/*
	        if (num < 10) return 1;
        return (num%100 < 10 || num%100 > 25) ? translateNum(num/10) : translateNum(num/10) + translateNum(num/ 100);
		*/
    int translateNum(int num) {
/*    	int res = 1;//结果数
    	int tmp = 1;// 之前的次数
    	int y = num % 10;
    	while(num != 0)
    	{
    		num /= 10;
    		int x = (num % 10) * 10 + y;// 判断现在的两位数
    		int c = (x >= 10 && x <= 25) ? res + tmp : res;
    		tmp = res;
    		res = c;
    		y = num % 10;
    	}
    	return res;*/
    	if (num < 10) return 1;
    	if (num % 100 >= 10 && num % 100 <= 25) return translateNum(num / 10) + translateNum(num / 100);
    	else return translateNum(num / 10);

    }
};

int main()
{
	Solution s;
	int a;
	cin >> a;
	cout << s.translateNum(a) << endl;

	return 0;
}
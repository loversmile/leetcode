#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool isPalindrome(string s)
	{
		int len = s.length();
		bool real = true;
		for(int i = 0; i < len/2; i++)
		{
			if (s[i] != s[len - 1 - i])
				return false;
		}
		return real;
	}

	int getForCenter(string& s, int left, int right)
	{
		while(left >= 0 && right < s.length() && s[left] == s[right])
		{
			left--;
			right++;
		}
		return right - left - 1;
	}

    string longestPalindrome(string s) {
    	int max = 0;

    	int start = 0;
    	int end = 0;
    	for (int i = 0; i < s.length(); i++)
    	{
    		int len1 = getForCenter(s, i, i); //ji
    		int len2 = getForCenter(s, i, i + 1); //ou
    		int tmp_len = len1 > len2 ? len1 : len2;
    		max = max > tmp_len ? max : tmp_len;
    		if (max > end - start + 1)
    		{
    			start = i - (max - 1) / 2;
    			end = i + max / 2;
    		}
    	}

        return s.substr(start, max);
    }
};

int main()
{
	Solution s;

	string a ;
	cin >> a;
	string res = s.longestPalindrome(a);
	cout << res << endl;
}
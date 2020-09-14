#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	string minWindow(string s, string t)
	{
		string r = "";
		int tl = t.length();
		int sl = s.length();
		if (tl > sl)
		{
			return "";
		}

		unordered_map <char, int> cnt;

		for (auto i: t)
		{
			cnt[i] ++;
		}

		int left = 0, right = 0;
		int len = 0;

		int minlen = sl;
		while (right < sl)
		{
			//char charRight = s[right];
			cnt[s[right]] --;
			if (cnt[s[right]] >= 0)
			{
				len++;
			}

			while (len == tl)
			{
				if (right - left + 1 <= minlen)
				{
					minlen = right - left + 1;
					r = s.substr(left, right - left + 1);
				}

				cnt[s[left]] ++;
				if (cnt[s[left]] > 0) 
				{
					len--;
				}
				left++;
			}
			right++;
		}

		return r;
	}
};

int main()
{
	string S = "ADOBECODEBANC";
	string T = "ABC";
	// cout  BANC

	Solution s;
	string r = s.minWindow(S, T);

	cout << r << endl;
}
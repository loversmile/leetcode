#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
/*	string getDigits(string &s, int &ptr)
	{
		string res = "";
		while(isdigit(s[ptr]))
		{
			res.push_back(s[ptr++]);
		}
		return res;
	}

	string getString(vector<string> &v)
	{
		string res;
		for(auto &s: v)
		{
			res += s;
		}
		return res;
	}

    string decodeString(string s) {
    	vector <string> stk;
    	int ptr = 0;

    	while (ptr < s.size())
    	{
    		char cur = s[ptr];

    		if (isdigit(cur))
    		{
    			string dig = getDigits(s, ptr);
    			stk.push_back(dig);
    		}
    		else if ( isalpha(cur) || cur == '[')
    		{
    			stk.push_back(string(1, cur));
    			ptr++;
    		}
    		else // 右括号
    		{
    			ptr++;
    			vector<string> sub;
    			while(stk.back() != "[")
    			{
    				sub.push_back(stk.back());
    				stk.pop_back();
    			}
    			std::reverse(sub.begin(), sub.end());
    			stk.pop_back();// 左括号出栈

    			string ret_str;
    			string str = getString(sub);
    			int num = stoi(stk.back());
    			stk.pop_back();

    			while(num--)
    			{
    				ret_str += str;
    			}
    			stk.push_back(ret_str);
    		}
    	}

    	return getString(stk);
    }
*/
    string src;
    int ptr;
    int getDigits()
    {
    	int ret = 0;
    	while(ptr < src.size() && isdigit(src[ptr]))
    	{
    		ret = ret * 10 + src[ptr++] - '0';
    	}
    	return ret;
    }

    string getString()
    {
    	if (ptr == src.size() || src[ptr] == ']')
    	{
    		return "";
    	}

    	char cur = src[ptr];
    	int repTime = 1;
    	string ret;

    	if (isdigit(cur))
    	{
    		repTime = getDigits();
    		++ptr; // 跳过左括号

    		string  str = getString();
    		++ptr; //跳过右括号

    		while(repTime--)
    		{
    			ret += str;
    		}
    	}
    	else if (isalpha(cur))
    	{
    		ret = string(1, src[ptr++]);
    	}


    	return ret + getString();
    }

    string decodeString(string s)
    {
    	src = s;
    	ptr = 0;
    	return getString();
    }
};

int main()
{
	Solution s;



	string str = "3[a]2[bc]";

	cout << s.decodeString(str) << endl;

	str = "3[a2[c]]";
	cout << s.decodeString(str) << endl;
	return 0;
}
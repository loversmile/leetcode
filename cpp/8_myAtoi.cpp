#include <iostream>
#include <climits>

using namespace std;


class Solution {
public:
    int myAtoi(string str) {
        int begin = 0;
        while(begin < str.length())
        {
            if (((str[begin] < '0') || (str[begin] > '9')) 
                && str[begin] != '-' 
                && str[begin] != '+' 
                && str[begin] != ' ')
                return 0;
            if (str[begin] == ' ')
            {
                begin++;
            }
            else
            {
                break;
            }
        }
        int end = begin + 1;
        while(end < str.length())
        {
            if (str[end] < '0' || (str[end] > '9'))
                break;
            end++;
        }

        string res = str.substr(begin, end - begin);

        long long ret = 0;
        if (res[0] == '-')
        {
            for (int i = 1; i < res.length(); ++i)
            {
                ret = ret * 10 + (res[i] - '0');
                if (-ret < INT_MIN)
                    return INT_MIN ;

            }
        }
        else
        {
            int b = (res[0] == '+' ? 1 : 0);
            for (int i = b; i < res.length(); ++i)
            {
                ret = ret * 10 + (res[i] - '0');
                if (ret > INT_MAX)
                    return INT_MAX ;
            }
        }

        return res[0] == '-' ? -ret : ret;
    }
};

int main()
{
    Solution S;

/*    cout << S.myAtoi("   -42") << endl;
    cout << S.myAtoi("3147483648") << endl;
    cout << S.myAtoi("42") << endl;
    cout << S.myAtoi("+42") << endl;
    cout << S.myAtoi("4193 with words") << endl;*/
    cout << S.myAtoi("    00000    ") << endl;

    return 0;
}
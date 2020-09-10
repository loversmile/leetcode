#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int a_len = a.length();
        int b_len = b.length();
        int max = a_len > b_len ? a_len : b_len;

        string res;
        int tmp = 0;

        while(a_len || b_len)
        {
            if (a_len && b_len)
            {
                a_len--;
                b_len--;
                int plus = tmp + b[b_len] - '0'  + a[a_len] - '0';
                res = res + (plus % 2 == 0 ? "0" : "1");
                cout << "[ab"<< res << "]";
                tmp = plus >= 2 ? 1 : 0;
            }
            else if (a_len)
            {
                a_len--;
                int plus = tmp + a[a_len] - '0';
                res = res + (plus % 2 == 0 ? "0" : "1");
                cout << "[a"<< res << "]";
                tmp = plus >= 2 ? 1 : 0;
            }
            else if (b_len)
            {
                b_len--;
                int plus = tmp + b[b_len] - '0';
                res = res + (plus % 2 == 0 ? "0" : "1");
                cout << "[b"<< res << "]";
                tmp = plus >= 2 ? 1 : 0;
            }
        }
        if (tmp == 1)
        {
            res = res + "1";
        }

        //string str;
        //str << res;
        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    Solution S;


    cout << S.addBinary("11", "1") << endl;
    cout << S.addBinary("1010", "1011") << endl;

    return 0;
}
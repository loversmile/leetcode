#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.length();

        if (len == 0) return false;

        for (int i = 0; i < len / 2; ++i)
        {
            if (s[i] != s[len - i - 1]) return false;
        }

        return true;
    }

    int countSubstrings(string s) {
        int res = 0;
        int len = s.length();

        for( int i = 0; i < len; ++i) {
            for(int j = i ; j < len; ++j) {
                string sub = s.substr(i, j + 1 - i);
                if (isPalindrome(sub))
                    ++res;
            }
        }

        return res;
    }
};

int main()
{
    Solution S;

    string s;
    cin >> s;

    cout << S.countSubstrings(s) << endl;

    string ss = "012345678";

    cout << ss.substr(0, 1);

    return 0;
}
#include <iostream>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_len = s.length();
        int t_len = t.length();
        int sl = 0, tl = 0;
        while(sl < s_len && tl < t_len)
        {
            if (s[sl] == t[tl])
            {
                ++sl;
            }
            ++tl;
        }
        return sl == s_len;
    }
};

int main()
{
    Solution S;

    string t = "abdec";
    string s = "ahbgdc";


    cout << S.isSubsequence(t, s) << endl;
    return 0;
}

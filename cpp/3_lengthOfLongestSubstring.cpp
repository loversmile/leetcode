#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0, begin = 0;
        int realbegin = 0;
        int size = s.size();
        for (int i = 0; i < size; i++)
        {
            int j = 0;
            for (j = begin; j < i; j++)
            {
                if (s[i] == s[j])
                {
                    begin = j + 1;
                    break;
                }
            }
            if (i - begin + 1> max)
            {
                max = i - begin + 1;
                realbegin = begin;
            }

        }
        cout << realbegin << endl;
        cout << s.substr(realbegin, max) << endl;
        return max;
    }
};

int main()
{
    string s = "aabcbaae";
    //string s = "abcabcbb";
    Solution S;
    cout << S.lengthOfLongestSubstring(s) << endl;;
}

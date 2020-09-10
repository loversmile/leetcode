#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        bool ret = false;
        stack<char> stk;

        int len = s.length();

        if (len == 0) return true;

        for (int i = 0; i < len; i++) {
            if (s[i] == '(' ||
                s[i] == '[' ||
                s[i] == '{') {
                stk.push(s[i]);
            } else if (s[i] == ')' ) {
                if (stk.size() > 0 && stk.top() == '(') {
                    stk.pop();
                    ret = true;
                } else {
                    return false;
                }
            } else if (s[i] == ']' ) {
                if (stk.size() > 0 && stk.top() == '[') {
                    stk.pop();
                    ret = true;
                } else {
                    return false;
                }
            } else if (s[i] == '}' ) {
                if (stk.size() > 0 && stk.top() == '{') {
                    stk.pop();
                    ret = true;
                } else {
                    return false;
                }
            }
        }

        if (stk.size() > 0) return false;

        return ret;
    }
};

int main()
{
    Solution S;
    string s;
    cin >> s;

    cout << S.isValid(s) << endl;

    return 0;
}
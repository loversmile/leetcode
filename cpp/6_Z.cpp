/*
将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：

L   C   I   R
E T O E S I I G
E   D   H   N
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。

请你实现这个将字符串进行指定行数变换的函数：

string convert(string s, int numRows);
示例 1:

输入: s = "LEETCODEISHIRING", numRows = 3
输出: "LCIRETOESIIGEDHN"
示例 2:

输入: s = "LEETCODEISHIRING", numRows = 4
输出: "LDREOEIIECIHNTSG"
解释:

L     D     R
E   O E   I I
E C   I H   N
T     S     G

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/zigzag-conversion
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) {
            return s;
        }
        string res = "";
        vector<string> temp(numRows);
        int length  = s.length();
        for(int i = 0; i < length; i++) {
            int cnt = i / (numRows - 1);
            int row = i % (numRows - 1);
            if (cnt  % 2 == 0 ) {
                temp[row].push_back(s[i]);
            } else {
                temp[numRows - 1 - row].push_back(s[i]);
            }
            
        }
        for (int i = 0; i < temp.size(); i++) {
            res += temp[i];
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout << s.convert("LEETCODEISHIRING", 3) << endl;
}

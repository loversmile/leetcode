#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long ret = 0;
        while(x)
        {
            ret = ret * 10 + x % 10;
            if (ret > INT_MAX || ret < INT_MIN) return 0;
            x /= 10;
        }

        return ret;
    }
};

int main()
{
    Solution S;
    int a ;
    cin >> a;
    cout << S.reverse(a) << endl;
}
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = numBottles;
        //int empty = numBottles;
        int change = 0;

        while(numBottles >= numExchange)
        {
            change = numBottles / numExchange;
            res += change;
            numBottles = change + numBottles % numExchange;
        }

        return res;

    }
};

int main()
{
    Solution S;

    int nBottles;
    int nExchange;
    cin >> nBottles;
    cin >> nExchange;
    cout << S.numWaterBottles(nBottles, nExchange) << endl;

    return 0;
}
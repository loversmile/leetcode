#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        if (numRows == 0)
        {
            return ret;
        }
    	vector<int> res(numRows, 0);
    	res[0] = 1;
        ret.push_back({1});
        for(int i = 1; i < numRows; ++i)
        {
            vector<int> tmp;
        	for (int j = i; j >= 1; --j)
        	{
        		res[j] += res[j - 1];
                tmp.push_back(res[j]);
        	}
            tmp.push_back(res[0]);
            ret.push_back(tmp);
        }
        return ret;
    }
};


int main()
{
	Solution s;

	vector<int> res;
	int a ;
	cin >> a;
	res = s.getRow(a);

	for(int r: res)
	{
		cout << r << " ";
	}
	cout << endl;
	return 0;
}
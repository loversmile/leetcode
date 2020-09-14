#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<int> getRow(int rowIndex) {
    	vector<int> res(rowIndex + 1, 0);
    	res[0] = 1;
        for(int i = 1; i < rowIndex + 1; ++i)
        {
        	for (int j = i; j >= 1; --j)
        	{
        		res[j] += res[j - 1];
        	}
        }
        return res;
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
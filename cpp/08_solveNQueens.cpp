#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	// col 表示要放的位置列，row 表示已经放的行，刚好是行号
	bool isValid(int col, int row, vector<int>& vec)//vec 存每一行的位置
	{
		for(int i = 0; i < vec.size(); ++i)
		{
			int data = vec[i];
			if ((col == data) 
				|| (i == row)
				|| (row - i == col - data) 
				|| (row - i == data - col)) 
			{
				return false;
			}
		}
		return true;
	}

	void setOne(int n, int set_one, vector<int>& one, vector<string>& dian, vector<vector<string>>& res)
	{
		if (n == set_one)
		{
			res.push_back(dian);
			return;
		}
		for (int i = 0; i < n; ++i)//i 表示列
    	{
    		if (isValid(i, set_one, one))
    		{
    			dian[set_one][i] = 'Q';
    			one.push_back(i);
    			setOne(n, set_one + 1, one, dian, res);
    			one.pop_back();
    			dian[set_one][i] = '.';
    		}
    	}

	}

    vector<vector<string>> solveNQueens(int n) {
    	vector<vector<string>> res;
    	vector<int> one;
    	vector<string> dian(n, string(n, '.'));

    	setOne(n, 0, one, dian, res);
    	
    	return res;
    }
};

int main()
{
	Solution s;
	int n;
	cin >> n;

	vector<vector<string>> v;
	v = s.solveNQueens(n);

	int count = 0;
	for(auto vv: v)
	{
		for(auto vvv: vv)
		{
			cout << vvv;
		}
		cout << endl;
		count++;
	}
	cout << count << endl;

	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    	if (matrix.empty())	return {};
    	int shang = 0, xia = matrix.size() - 1;
    	int zuo = 0, you = matrix[0].size() - 1;
    	int r = 0;

    	vector<int> res(matrix.size()*matrix[0].size(), 0);

    	while(1)
    	{
        	for(int i = zuo; i <= you; i++)
	    	{
	    		res[r++] = matrix[shang][i];
	    	}
	    	if (++shang > xia) break;

	    	for(int i = shang; i <= xia; i++)
	    	{
	    		res[r++] = matrix[i][you];
	    	}
	    	if(--you < zuo) break;

	    	for(int i = you; i >= zuo; i--)
	    	{
	    		res[r++] = matrix[xia][i];
	    	}
	    	if(--xia < shang)break;

	    	for(int i = xia; i >= shang; i--)
	    	{
	    		res[r++] = matrix[i][zuo];
	    	}
	    	if(++zuo > you)break;		
    	}

    	return res;
    }
};

int main()
{
	Solution s;
	vector<vector<int>> v = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
/*	vector<int> v1 = {1, 2, 3, 4};
	vector<int> v2 = {5, 6, 7, 8};
	vector<int> v3 = {9, 10, 11, 12};
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);*/
	//[1,2,3,4,8,12,11,10,9,5,6,7]


	vector<int> res;
	res = s.spiralOrder(v);

	for (int r : res)
	{
		cout << r << " ";
	}
	cout << endl;
}
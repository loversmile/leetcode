#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	static bool cmp(const string& a, const string& b)// 小的在前，是true
	{
		int i = 0, j = 0;
		while(a[i] != ' ') ++i;
		while(b[j] != ' ') ++j;
		string short_a = a.substr(i);
		string short_b = b.substr(j);
		if (short_a != short_b)
		{
			return short_a < short_b;
		}
		else// 相同时候，按照标识符排序
		{
			return a < b;
		}
	}
	// 因为字母要放前面，所以 cmp 没有办法比较数字和字母，所以字母要和数字分开
	// 数字不用排序
    vector<string> reorderLogFiles(vector<string>& logs) {
    	vector<string> res;
    	vector<string> alpha;
    	for(int i = 0; i < logs.size(); ++i)
    	{
    		int j = logs[i].find(' ');
    		if(logs[i][j + 1] >= '0' && logs[i][j + 1] <= '9')
    		{
    			res.push_back(logs[i]);
    		}
    		else
    		{
    			alpha.push_back(logs[i]);
    		}
    		
    	}
    	sort(alpha.begin(), alpha.end(), cmp);
    	res.insert(res.begin(), alpha.begin(), alpha.end()); //字母插入到最前面
    	return res;
    }
};

int main()
{
	Solution s;

	vector<string> v = {"a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"};

	vector<string> res;
	res = s.reorderLogFiles(v);

	for (auto r : res)
	{
		cout << r << endl;
	}
	//cout << endl;
	return 0;
}
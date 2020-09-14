#include <iostream>
#include <vector>

class UnionEnd
{
private:
    vector<int> parent;
public:
	UnionEnd()
	{
		parent.resize(26);
		iota(parent.begin(), parent.end(), 0);
	}

	int find(int index)
	{
		if(index == parent[index])
		{
			return index;
		}
		parent[index] = find(parent[index]);
		return parent[index];
	}

	void uein(int index1, int index2)
	{
		parent[find(index1)] = find(index2);
	}
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
    	UnionEnd ue;
    	for(const string& str: equations)
    	{
    		if (str[1] == '=')
    		{
    			int index1 = str[0] - 'a';
    			int index2 = str[3] - 'a';

    			ue.uein(index1, index2);
    		}
    	}

    	for(const string& str: equations)
    	{
    		if(str[1] == '!')
    		{
    			int index1 = str[0] - 'a';
    			int index2 = str[3] - 'a';
				if (ue.find(index1) == ue.find(index2)) {
                    return false;
                }
    		}
    	}
    	return true;
	}
};

int main()
{
	Solution s;

	vector<string> s = {"a==b","b!=c","c==a"};
	bool res = s.equationsPossible(s);
	cout << res << endl;
}
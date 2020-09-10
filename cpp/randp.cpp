#include <iostream>

#include <unistd.h>

#include <vector>
#include <set>

using namespace std;

int h()
{
	time_t t = time(NULL);
	srand(t);

	set<int> red;
	set<int> blue;

	for( int i = 0; i < 5;)
	{
		int tmp = rand() % 35 + 1;
		if (red.count(tmp) >= 1) continue;

		red.insert(tmp);
		++i;
	}

	for( int i = 0; i < 2;)
	{
		int tmp = rand() % 12 + 1;
		if (blue.count(tmp) >= 1) continue;

		blue.insert(tmp);
		++i;
	}
	for(auto r : red)
		cout << r << " ";
	cout << " | ";
	for(auto r : blue)
		cout << r << " ";
	cout << endl;
	usleep(100000);
	return 0;
}

int main()
{
	for (int i = 0 ; i < 3629; ++i)
	{
		h();
	}
	return 0;
}

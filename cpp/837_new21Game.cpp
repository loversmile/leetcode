#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double new21Game(int N, int K, int W) {
    	vector<double> dp(K + W + 1, 0);
    	// 求初试积分为0 的时候，的概率

    	//完成最后一次抽取，F>=K F<=K-1+W
    	// 求出初始积分为 K---K + W - 1 的概率
    	// 最后一次抽取后的概率非0，即1

    	//初始积分为i时候，下一次超的概率等于 1-W 超的概率 /W 表示取某一个的概率
    	//dp[i] = (dp[i + 1] + dp[i+2]...dp[i+W])/W
    	//dp[i + 1] = (dp[i + 2] + dp[i+3]...dp[i+W+1])/W
    	//dp[i] - dp[i+1] = (dp[i + 1] - dp[i + W + 1]) / W
    	//dp[i] = (dp[i + 1] *(W + 1) - dp[i + W + 1]) / W

    	//dp[K] = (dp[K + 1] + dp[K + 2] + ··· + dp[K + W]) / W;
    	//dp[K+W] = dp[K] * W - (dp[K + 1] + dp[K + 2] + ··· + dp[K + W - 1] )

    	int kw = 0;
    	for(int i = K; i <= K - 1 + W; i++)
    	{
    		if (i > N)
    			dp[i] = 0;
    		else
    			dp[i] = 1;
    		if (i != K)
    			kw += dp[i];
    	}
    	dp[K + W] = dp[K] * W - kw; //求dp[K+W]是需要

    	for (int i = K - 1; i >= 0; i--)
    	{
    		dp[i] = (dp[i + 1] *(W + 1) - dp[i + W + 1]) / (double)W;
    		//cout << i << ": "<< dp[i] << endl;
    	}

    	return dp[0];
    }
};

int main()
{
	Solution s;

	//int N = 10, K = 1, W = 10;
	//int N = 6, K = 1, W = 10;
	int N = 21, K = 17, W = 10;

	double a  = s.new21Game(N, K, W);
	cout << a << endl;
}
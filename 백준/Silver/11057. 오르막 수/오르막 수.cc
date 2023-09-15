#include <iostream>

using namespace std;

// DP[n][k] = sum(DP[0][k - 1], ..., DP[n][[k - 1]);

int DP[10][1001];

int main()
{
	int n;
	cin >> n;

	// 기저 조건
	for (int i = 0; i <= 9; i++)
	{
		DP[i][1] = 1;
	}

	// DP
	int tmp;
	for (int i = 2; i <= n; i++)
	{
		tmp = 0;
		for (int j = 0; j <= 9; j++)
		{
			tmp = (tmp + DP[j][i - 1]) % 10007;
			DP[j][i] = tmp;
		}
	}

	tmp = 0;
	for (int i = 0; i <= 9; i++)
	{
		tmp = (tmp + DP[i][n]) % 10007;
	}

	cout << tmp;
		
	return 0;
}
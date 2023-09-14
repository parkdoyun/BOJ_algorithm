#include <iostream>

using namespace std;

// DP[n][k] : n으로 끝나는 길이 k인 계단 수
// DP[n][k] = DP[n - 1][k - 1] + DP[n + 1][k - 1];

long long int DP[10][101];

int main()
{
	int n;
	cin >> n;

	// 기저 조건
	for(int i = 1; i <= 9; i++)
	{
		DP[i][1] = 1;
	}

	// DP
	for(int i = 2; i <= n; i++)
	{
		DP[0][i] = DP[1][i - 1];
		DP[9][i] = DP[8][i - 1];
		for(int j = 1; j < 9; j++)
		{
			DP[j][i] = (DP[j - 1][i - 1] + DP[j + 1][i - 1]) % (long long int)1000000000;
		}
	}

	long long int res = 0;
	for(int i = 0; i <= 9; i++)
	{
		res = (res + DP[i][n]) % (long long int)1000000000;
	}

	cout << res;

	return 0;
}
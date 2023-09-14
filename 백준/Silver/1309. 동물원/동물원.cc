#include <iostream>

using namespace std;

// DP[0][k] = DP[1][k - 1] + DP[2][k - 1];
// DP[1][k] = DP[0][k - 1] + DP[2][k - 1];
// DP[2][k] = DP[0][k - 1] + DP[1][k - 1] + DP[2][k - 1];

int DP[3][100001]; // DP[0][k] : k번째 0번만 있음, DP[1][k] : k번째 1번만 있음, DP[2][k] : 둘다 없음

int main()
{
	int n;
	cin >> n;

	// 기저 조건
	DP[0][1] = 1;
	DP[1][1] = 1;
	DP[2][1] = 1;

	// DP
	for(int k = 2; k <= n; k++)
	{
		DP[0][k] = (DP[1][k - 1] + DP[2][k - 1]) % 9901;
		DP[1][k] = (DP[0][k - 1] + DP[2][k - 1]) % 9901;
		DP[2][k] = (DP[0][k - 1] + DP[1][k - 1] + DP[2][k - 1]) % 9901;
	}

	int res = DP[0][n];
	res = ((res + DP[1][n]) % 9901 + DP[2][n]) % 9901;
	cout << res;

	return 0;
}
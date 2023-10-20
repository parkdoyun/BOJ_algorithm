#include <iostream>

using namespace std;

// 규칙
// ex) XX (나머지 1)
	// XX1 -> 나머지 1 + 1 = 2
	// XX2 -> 나머지 1 + 2 = 0
	// XX0 -> 나머지 1 + 0 = 1

// XXX가 나머지가 0이려면
	// 1. XX 나머지 1, XX2
	// 2. XX 나머지 2, XX1
	// 3. XX 나머지 0, XX0

// DP[N][M][k] : 끝이 N이고 나머지가 M인 k자리 수

#define divisor 1000000009

int n;
long long int DP[3][3][33334];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	
	// 기저 조건
	DP[1][1][1] = 1;
	DP[2][2][1] = 1;

	// DP
	for (int i = 2; i <= n; i++)
	{
		DP[0][0][i] = (DP[0][0][i - 1] + DP[1][0][i - 1] + DP[2][0][i - 1]) % (long long int)divisor;
		DP[1][0][i] = (DP[0][2][i - 1] + DP[1][2][i - 1] + DP[2][2][i - 1]) % (long long int)divisor;
		DP[2][0][i] = (DP[0][1][i - 1] + DP[1][1][i - 1] + DP[2][1][i - 1]) % (long long int)divisor;

		DP[0][1][i] = (DP[0][1][i - 1] + DP[1][1][i - 1] + DP[2][1][i - 1]) % (long long int)divisor;
		DP[1][1][i] = (DP[0][0][i - 1] + DP[1][0][i - 1] + DP[2][0][i - 1]) % (long long int)divisor;
		DP[2][1][i] = (DP[0][2][i - 1] + DP[1][2][i - 1] + DP[2][2][i - 1]) % (long long int)divisor;

		DP[0][2][i] = (DP[0][2][i - 1] + DP[1][2][i - 1] + DP[2][2][i - 1]) % (long long int)divisor;
		DP[1][2][i] = (DP[0][1][i - 1] + DP[1][1][i - 1] + DP[2][1][i - 1]) % (long long int)divisor;
		DP[2][2][i] = (DP[0][0][i - 1] + DP[1][0][i - 1] + DP[2][0][i - 1]) % (long long int)divisor;
	}
	
	long long int res = DP[0][0][n];
	res = (res + (long long int)(DP[1][0][n] + DP[2][0][n]) % (long long int)divisor) % (long long int)divisor;
	cout << res;

	return 0;
}
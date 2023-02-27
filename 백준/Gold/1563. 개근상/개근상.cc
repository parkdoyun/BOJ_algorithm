#include <iostream>

using namespace std;

// 백준 1563 - 개근상
// DP
// 골드 4

// 0 : 출석만
// 1 : 연속 결석 2
// 2 : 연속 결석 1
// 3 : 지각1 + 연속 결석 2
// 4 : 지각1 + 연속 결석 1
// 5 : 지각1

int DP[6][1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	// 초기 조건 (1회)
	DP[0][1] = 1;
	DP[1][1] = 0;
	DP[2][1] = 1;
	DP[3][1] = 0;
	DP[4][1] = 0;
	DP[5][1] = 1;

	// 초기 조건 (2회)
	DP[0][2] = 2; // 출 + 출, 결 + 출
	DP[1][2] = 1; // 결 + 결
	DP[2][2] = 1; // 출 + 결
	DP[3][2] = 0; 
	DP[4][2] = 1; // 지 + 결
	DP[5][2] = 3; // 출 + 지, 지 + 출, 결 + 지

	for (int i = 3; i <= n; i++)
	{
		DP[0][i] = (DP[0][i - 1] + DP[1][i - 1] + DP[2][i - 1]) % 1000000;
		DP[1][i] = DP[2][i - 1];
		DP[2][i] = DP[0][i - 1];
		DP[3][i] = DP[4][i - 1];
		DP[4][i] = DP[5][i - 1];
		DP[5][i] = (DP[0][i - 1] + DP[1][i - 1] + DP[2][i - 1] + DP[5][i - 1] + DP[3][i - 1] + DP[4][i - 1]) % 1000000;
	}

	int res = 0;
	for (int i = 0; i < 6; i++)
	{
		res += DP[i][n];
		res %= 1000000;
	}

	cout << res;

	return 0;
}
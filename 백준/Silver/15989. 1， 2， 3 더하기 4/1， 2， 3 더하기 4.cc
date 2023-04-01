#include <iostream>

using namespace std;

// 점화식 : 1 더할 수 있는 애들 + 2 더할 수 있는 애들 + 3 더할 수 있는 애들


// 겹치는 것 제외해야 함

int n;
int DP[3][10001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			DP[0][i] = 0;
			DP[1][i] = 0;
			DP[2][i] = 0;
		}

		// 초기 조건
		DP[0][1] = 1;
		DP[0][2] = 1; DP[1][2] = 1;
		DP[0][3] = 2; DP[2][3] = 1;

		for (int i = 4; i <= n; i++)
		{
			DP[0][i] = DP[0][i - 1] + DP[1][i - 1] + DP[2][i - 1];
			DP[1][i] = DP[1][i - 2] + DP[2][i - 2];
			DP[2][i] = DP[2][i - 3];
		}

		cout << DP[0][n] + DP[1][n] + DP[2][n]  << '\n';
	}

	return 0;
}
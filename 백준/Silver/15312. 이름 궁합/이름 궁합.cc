#include <iostream>
#include <string>

using namespace std;

// 점화식 DP[i][j] = DP[i - 1][j] + DP[i - 1][j + 1];
int stroke_n[26] = { 3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };
int DP[4001][4001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string A, B;
	cin >> A >> B;
	int n = A.length();
	int a_idx = 0;
	int b_idx = 0;
	for (int i = 0; i < n * 2; i++)
	{
		if (i % 2 == 0)
		{
			DP[0][i] = stroke_n[(int)(A[a_idx] - 'A')];
			a_idx++;
		}
		else
		{
			DP[0][i] = stroke_n[(int)(B[b_idx] - 'A')];
			b_idx++;
		}
	}

	for (int i = 1; i < n * 2 - 1; i++)
	{
		for (int j = 0; j < n * 2 - i; j++)
		{
			DP[i][j] = DP[i - 1][j] + DP[i - 1][j + 1];
			if (DP[i][j] >= 10) DP[i][j] -= 10;
		}
	}

	cout << DP[n * 2 - 2][0] << DP[n * 2 - 2][1];

	return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int DP[1001][1001];
int paper[1001][1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	int a, b;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		paper[a][b] = 1;
		paper[b][a] = 1;
	}

	for (int i = 1; i <= 1000; i++)
	{
		for (int j = 1; j <= 1000; j++)
		{
			DP[i][j] = max(DP[i - 1][j - 1], DP[i][j - 1]);
			DP[i][j] = max(DP[i][j], DP[i - 1][j]);
			if (paper[i][j] == 1) // 종이 있다면
			{
				DP[i][j]++;
			}
		}
	}

	cout << DP[1000][1000];

	return 0;
}
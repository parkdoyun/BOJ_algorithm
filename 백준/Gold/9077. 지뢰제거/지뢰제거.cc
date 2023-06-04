#include <iostream>

using namespace std;

// 메모리 초과
// arr 비트로 바꾸자

char arr[10012][10012];
int sumArr[10012][10012]; // sumArr[i][j] = sumArr[i - 10][j - 10]부터 지뢰 갯수

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T, n;
	cin >> T;
	int max_cnt;

	for (int tc = 1; tc <= T; tc++)
	{
		// 초기화
		max_cnt = 0;
		for (int i = 0; i <= 10011; i++)
		{
			for (int j = 0; j <= 10011; j++)
			{
				arr[i][j] = 0;
				sumArr[i][j] = 0;
			}
		}

		cin >> n;
		int y, x;
		for (int i = 0; i < n; i++)
		{
			cin >> x >> y;
			arr[y + 11][x + 11] = 1;
		}

		for (int i = 11; i <= 10011; i++)
		{
			for (int j = 11; j <= 10011; j++)
			{ 
				/*
				if (i == 0 && j == 0) // 초기 조건
				{
					sumArr[i][j] = (int)arr[i][j];
				}
				else if (i < 11 && j < 11) // 초기 조건
				{
					sumArr[i][j] = (int)arr[i][j] + sumArr[i - 1][j] + sumArr[i][j - 1] - sumArr[i - 1][j - 1];
				}
				else if (i == 0)
				{
					sumArr[i][j] = (int)arr[i][j] + sumArr[i][j - 1] - (int)arr[i][j - 11];
				}
				else if (j == 0)
				{
					sumArr[i][j] = (int)arr[i][j] + sumArr[i - 1][j] - (int)arr[i - 11][j];
				}
				else if (i < 11)
				{
					sumArr[i][j] = (int)arr[i][j] + sumArr[i - 1][j] + sumArr[i][j - 1] - sumArr[i - 1][j - 1] - (int)arr[i][j - 11];
				}
				else if (j < 11)
				{
					sumArr[i][j] = (int)arr[i][j] + sumArr[i - 1][j] + sumArr[i][j - 1] - sumArr[i - 1][j - 1] - (int)arr[i - 11][j];
				}
				else
				{
					sumArr[i][j] = (int)arr[i][j] + sumArr[i - 1][j] + sumArr[i][j - 1] - sumArr[i - 1][j - 1] + (int)arr[i - 11][j - 11] - (int)arr[i - 11][j] - (int)arr[i][j - 11];
				}
				*/
				sumArr[i][j] = (int)arr[i][j] + sumArr[i - 1][j] + sumArr[i][j - 1] - sumArr[i - 1][j - 1] + (int)arr[i - 11][j - 11] - (int)arr[i - 11][j] - (int)arr[i][j - 11];
				if (sumArr[i][j] > max_cnt) max_cnt = sumArr[i][j];
			}
		}

		cout << max_cnt << '\n';
	}

	return 0;
}
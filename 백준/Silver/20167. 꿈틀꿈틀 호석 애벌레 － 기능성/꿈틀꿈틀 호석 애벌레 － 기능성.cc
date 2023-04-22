#include <iostream>
#include <algorithm>

using namespace std;

// DP
// i번째 먹이 먹을건지 포기할건지?
// 점화식
// max(i + 1번째까지의 DP, i번째가 처음인 애)
// DP[i] = max(DP[i + 1], i번째가 처음)

int n, k;
int food[21];
int DP[21];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		cin >> food[i];
	}

	// 기저 조건
	int tmp = 0;
	int idx;
	for (int i = n; i >= 1; i--)
	{
		tmp += food[i];
		if (tmp >= k)
		{
			idx = i;
			break;
		}
	}
	if (tmp - k < 0) idx = 1;
	else DP[idx] = tmp - k;
	
	// DP
	for (int i = idx - 1; i >= 1; i--)
	{
		tmp = 0;
		for (int j = i; j <= n; j++)
		{
			tmp += food[j];
			if (tmp >= k)
			{
				idx = j;
				break;
			}
		}
		if (tmp - k < 0) DP[i] = DP[i + 1];
		else DP[i] = max(DP[i + 1], DP[idx + 1] + tmp - k);
	}

	cout << DP[1];

	return 0;
}
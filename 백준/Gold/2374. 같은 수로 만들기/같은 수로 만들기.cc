#include <iostream>

using namespace std;

// 최댓값이 되도록 만들어야 함
// 점화식 
// 1. 만약 num[i] >= num[i - 1]이면 같이 증가할 것임 -> DP[i] = DP[i - 1];
// 2. num[i] <= num[i - 1]이면 얘 먼저 올리고 i - 1번쨰와 같이 올려야 함 -> DP[i] = DP[i - 1] + (num[i] - num[i - 1]);

int n, max1;
int num[1001];
long long int DP[1001];

int main()
{
	max1 = 0;

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> num[i];
		if (num[i] > max1) max1 = num[i];
	}

	// DP
	// 기저 조건
	DP[1] = max1 - num[1];

	for (int i = 2; i <= n; i++)
	{
		if (num[i] >= num[i - 1]) DP[i] = DP[i - 1];
		else
		{
			DP[i] = DP[i - 1] + (long long int)(num[i - 1] - num[i]);
		}
	}

	cout << DP[n];

	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

vector<int> coin;

int DP[10001];

// 백준 2293 - 동전 1
// DP, 골드 5
// 점화식 -> DP[i] = DP[i] + DP[i - coin[j]];
// 이전 동전까지의 가짓수(현재 동전이 포함 안 된)에
// 현재 동전이 포함된 가짓수를 포함한다.
// 마지막 동전이 포함된 가짓수까지 다 포함한 후 결과 출력

int main()
{
	int n, k, c;
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> c;
		coin.push_back(c);
	}

	DP[0] = 1;

	for (int j = 0; j < coin.size(); j++)
	{
		for (int i = coin[j]; i <= k; i++)
		{
			DP[i] = DP[i] + DP[i - coin[j]]; // 점화식
		}
	}
	
	cout << DP[k];

	return 0;
}
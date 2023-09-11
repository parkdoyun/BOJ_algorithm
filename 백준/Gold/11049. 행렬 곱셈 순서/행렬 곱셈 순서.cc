#include <iostream>
#include <algorithm>

using namespace std;

// 파일 합치기 문제와 비슷한 듯?

int n;
long long int arr[2][501];
long long int chk[501][501];

long long int DFS(int left, int right)
{
	if(chk[left][right] != 0) return chk[left][right]; // 시간초과 막기 위해 
	if(left == right) return 0;
	else if(left == right - 1)
	{
		chk[left][right] = arr[0][left] * arr[1][left] * arr[1][right];
		return arr[0][left] * arr[1][left] * arr[1][right];
	}

	long long int min1 = DFS(left + 1, right) + arr[0][left] * arr[1][left] * arr[1][right];
	long long int min2 = DFS(left, right - 1) + arr[0][left] * arr[0][right] * arr[1][right];
	chk[left][right] = min(min1, min2);
	for(int i = left + 1; i < right - 1; i++)
	{
		chk[left][right] = min(chk[left][right], DFS(left, i) + arr[0][left] * arr[1][i] * arr[1][right] + DFS(i + 1, right));
	}

	return chk[left][right];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> arr[0][i] >> arr[1][i];
	}

	cout << DFS(0, n - 1);

	return 0;
}
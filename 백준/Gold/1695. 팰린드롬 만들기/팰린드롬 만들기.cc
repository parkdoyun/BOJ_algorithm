#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>

using namespace std;

// 양쪽 수가 같은 경우 -> left++; right--;
// 양쪽 수가 다른 경우 -> 둘 중 어느 쪽에 채울건지
// 왼쪽 채우는 것이 최소인지 오른쪽 채우는 것이 최소인지?

int arr[5001];
int DP[5001][5001];

int DFS(int left, int right)
{
	if(left >= right) return 0;
	if(DP[left][right] != -1) return DP[left][right];

	DP[left][right] = 0;
	if(arr[left] == arr[right]) DP[left][right] += DFS(left + 1, right - 1);
	else DP[left][right] += 1 + min(DFS(left + 1, right), DFS(left, right - 1)); // 하나 추가하므로
	return DP[left][right];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;

	for(int i = 0; i < n; i++) cin >> arr[i];

	memset(DP, -1, sizeof(DP));

	cout << DFS(0, n - 1);

	return 0;
}
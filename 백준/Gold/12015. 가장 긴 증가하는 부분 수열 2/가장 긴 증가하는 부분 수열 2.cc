#include <iostream>

using namespace std;

// 백준 12015 - 가장 긴 증가하는 부분 수열 2
// 골드 2
// LIS (Longest Increasing Sequence) - binary-search

// 1. 어차피 가장 긴 수열의 **길이**를 구하면 된다
// 2-1. arr[i]가 현재 수열의 마지막보다 클 경우, 뒤에 붙인다 (이 때 최댓값 갱신)
// 2-2. arr[i]가 현재 수열의 마지막보다 작을 경우, 맞는 위치 찾아서 넣는다
	// 같은 값 있으면 넣지 않고, 나보다 작은 수들 중 제일 큰 수 다음으로 넣는다
	// (만약에 중간으로 들어간다 해도 어차피 최장 수열의 길이를 구하기 때문에 상관없다!)
	// ex) 1 3 4 5, arr[i] = 2, 최댓값 : 4
	// ex) 1 2 4 5, 중간에 껴도 최댓값은 i - 1번째의 길이 4임!!
	// 4보다 길어질 때 -> i + 1부터 더 길어지는 수열 있기 때문 -> 중간에 껴도 상관 X
// 3. 최댓값 출력

// DP로 푸니까 시간초과

int n;
int arr[1000001];
int DP[1000001];

int binary_search(int left, int right, int tmp)
{
	int idx = 1;
	int start = left;
	int end = right;
	int mid;
	
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (DP[mid] == tmp) return -1; // 같은 값 있으므로 pass
		else if (DP[mid] > tmp)
		{
			end = mid - 1;
		}
		else // DP[mid] < tmp
		{
			start = mid + 1;
			if (mid + 1 > idx) idx = mid + 1;
		}
	}
	return idx;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) cin >> arr[i];

	// 기저 조건
	DP[1] = arr[1];

	// DP
	int last_idx = 1;
	int tmp;
	for (int i = 2; i <= n; i++)
	{
		if (arr[i] == DP[last_idx]) continue;
		else if (arr[i] > DP[last_idx])
		{
			last_idx++;
			DP[last_idx] = arr[i];
		}
		else // arr[i] < DP[last_idx]
		{
			tmp = binary_search(1, last_idx, arr[i]);
			if (tmp != -1)
			{
				DP[tmp] = arr[i];
			}
		}
	}

	cout << last_idx;

	return 0;
}
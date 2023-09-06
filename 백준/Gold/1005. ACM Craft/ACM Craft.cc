#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 부모 건물이 여러개 일수도 있다
// 부모로 거슬러 올라가면서 큰 값 더하기???

int n, k, w;
int time1[1001];
vector<vector<int> > par;
int DP[1001]; // 

int DFS(int now)
{
	if(DP[now] != -1) return DP[now];
	if(par[now].size() == 0) // root
	{
		DP[now] = time1[now];
		return DP[now];
	}

	DP[now] = 0;
	for(int i = 0; i < par[now].size(); i++)
	{
		DP[now] = max(DP[now], DFS(par[now][i]) + time1[now]);
	}
	return DP[now];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	for(int tc = 1; tc <= T; tc++)
	{
		cin >> n >> k;
		par.clear();
		par.resize(n + 1);

		for(int i = 1; i <= n; i++)
		{
			DP[i] = -1;
			cin >> time1[i];
		}

		int x, y;
		for(int i = 0; i < k; i++)
		{
			cin >> x >> y;
			par[y].push_back(x);
		}

		cin >> w; // w 건물 지어야 함

		cout << DFS(w) << '\n';

	}

	return 0;
}
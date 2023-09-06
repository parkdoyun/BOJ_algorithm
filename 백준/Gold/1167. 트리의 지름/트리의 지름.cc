#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 각 정점에서 가장 큰 두개의 가중치의 정점들의 가중치 합이 최대
// 재귀로 끝까지 내려갔다가 올라오면서 계산
// 한번만 순회해도 됨

bool cmp(int a, int b)
{
	return a > b;
}

struct edge
{
	int oppo;
	int weight;
};
int V;
vector<vector<edge>> E;
int max1 = 0;
int chk[100001]; // 1 : 재귀로 들어감, 2 : 아예 끝

int traversal(int now, int score, int weight)
{
	chk[now] = 1;
	vector<int> tmp_vec;

	tmp_vec.push_back(score);
	
	int tmp;
	int tmp_max1 = 0;
	for (auto e : E[now])
	{
		if (chk[e.oppo] == 1 || chk[e.oppo] == 2) continue;
		tmp = traversal(e.oppo, score + e.weight, e.weight);
		tmp_vec.push_back(tmp);
		if (tmp_max1 < tmp) tmp_max1 = tmp;
	}

	if (tmp_vec.size() == 1) // leaf
	{
		if (max1 < tmp_vec[0]) max1 = tmp_vec[0];
		
		chk[now] = 2;
		return weight;
	}

	sort(tmp_vec.begin(), tmp_vec.end(), cmp);
	if (max1 < tmp_vec[0] + tmp_vec[1]) max1 = tmp_vec[0] + tmp_vec[1];
	
	chk[now] = 2;
	return tmp_max1 + weight;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> V;
	E.resize(V + 1);

	int u, v, w;
	int root;
	for (int i = 0; i < V; i++)
	{
		cin >> u;
		for (int j = 0; j < V; j++)
		{
			cin >> v;
			if (v == -1) break;
			cin >> w;
			E[u].push_back({ v, w });
		}
	}

	for (int i = 1; i <= V; i++)
	{
		if (E[i].size() == 1) // 연결 정점 하나밖에 없음
		{
			root = i;
			break;
		}
	}

	traversal(root, 0, 0);

	cout << max1;

	return 0;
}
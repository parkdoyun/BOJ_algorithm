#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// BFS
// 전부 해보면 되겠다
// 도착 못 한다면 -1

#define INF 999999999

int n, t, m, l;

struct node
{
	int num; // 현재 건물 번호
	int time; // 걸린 시간
	int money; // 사용된 돈
};
bool operator<(node n1, node n2)
{
	if (n1.money > n2.money) return true;
	else if (n1.money == n2.money && n1.time > n2.time) return true;
	return false;
}
priority_queue<node> pq;

int visit[102]; // visit 함수
vector<vector<node>> E;
int min_money = INF;

void BFS()
{
	pq.push({ 1, 0, 0 });

	while (!pq.empty())
	{
		node tmp = pq.top();
		pq.pop();

		//if (visit[tmp.num] == 1) continue;
		//visit[tmp.num] = 1;

		if (tmp.num == n)
		{
			if(min_money > tmp.money) min_money = tmp.money;
			continue;
		}

		for (int i = 0; i < E[tmp.num].size(); i++)
		{
			if (visit[E[tmp.num][i].num] == 0 && tmp.money + E[tmp.num][i].money <= m &&
				tmp.time + E[tmp.num][i].time <= t)
			{
				pq.push({ E[tmp.num][i].num, tmp.time + E[tmp.num][i].time, tmp.money + E[tmp.num][i].money });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> t >> m >> l;

	E.resize(n + 1);

	int u, v, t1, m1;
	for (int i = 0; i < l; i++)
	{
		cin >> u >> v >> t1 >> m1;
		E[u].push_back({ v, t1, m1 });
		E[v].push_back({ u, t1, m1 });
	}

	BFS();

	if(min_money == INF) cout << -1;
	else cout << min_money;

	return 0;
}
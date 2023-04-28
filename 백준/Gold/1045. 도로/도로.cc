#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int total_cnt = 0;

struct tp
{
	int u;
	int v;
};
bool operator<(tp t1, tp t2)
{
	if (t1.u > t2.u) return true;
	else if (t1.u == t2.u && t1.v > t2.v) return true;
	return false;
}
bool cmp(tp t1, tp t2)
{
	if (t1.u < t2.u) return true;
	else if (t1.u == t2.u && t1.v < t2.v) return true;
	return false;
}
priority_queue<tp> pq;
vector<tp> vec;
int print[51];

int root[51];
int find(int a)
{
	if (root[a] == a) return a;
	return root[a] = find(root[a]);
}
void Union(int a, int b)
{
	int ar = find(a);
	int br = find(b);
	if (ar == br)
	{
		vec.push_back({ a, b });
		return;
	}
	print[a]++;
	print[b]++;
	total_cnt++;
	if (ar <= br) root[br] = ar;
	else root[ar] = br;
}

bool allVisit()
{
	for (int i = 0; i < n; i++)
	{
		if (find(i) != 0) return false;
	}
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	char c;
	for (int i = 0; i < n; i++)
	{
		root[i] = i;
		for (int j = 0; j < n; j++)
		{
			cin >> c;
			if (c == 'Y')
			{
				if (i < j)
				{
					pq.push({ i, j });
				}
			}
		}
	}

	while (!pq.empty())
	{
		tp tmp = pq.top();
		pq.pop();

		Union(tmp.u, tmp.v);
		if (total_cnt == m) break;
	}

	if (total_cnt == m)
	{
		if (!allVisit()) cout << -1;
		else
		{
			for (int i = 0; i < n; i++) cout << print[i] << ' ';
		}
	}
	else
	{
		if (allVisit()) // 채우기
		{
			// vec에서 채워보기
			int flag = -1;
			sort(vec.begin(), vec.end(), cmp);
			for (int i = 0; i < vec.size(); i++)
			{
				print[vec[i].u]++;
				print[vec[i].v]++;
				total_cnt++;
				if (total_cnt == m)
				{
					flag = 1;
					break;
				}
			}
			if (flag == -1) cout << -1;
			else for (int i = 0; i < n; i++) cout << print[i] << ' ';
		}
		else cout << -1;
	}

	return 0;
}
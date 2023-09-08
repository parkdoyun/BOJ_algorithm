#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// 위상 정렬
stack<int> st;
vector<vector<int> > par;
vector<vector<int> > chi;
vector<int> res;
int visit[1001];
int n, m;

void push(int p, int c)
{
	int flag = -1;
	for(int i = 0; i < par[c].size(); i++)
	{
		if(par[c][i] == p)
		{
			flag = 1;
			break;
		}
	}
	if(flag == -1) par[c].push_back(p);
	flag = -1;
	for(int i = 0; i < chi[p].size(); i++)
	{
		if(chi[p][i] == c)
		{
			flag = 1;
			break;
		}
	}
	if(flag == -1) chi[p].push_back(c);
}

int DFS(int now)
{
	if(visit[now] == 2) return 0;
	if(visit[now] == 1) return -1; // cycle
	visit[now] = 1;
	st.push(now);

	for(int i = 0; i < par[now].size(); i++)
	{
		if(DFS(par[now][i]) == -1) return -1;
	}

	res.push_back(st.top());
	st.pop();

	visit[now] = 2;
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	par.resize(n + 1);
	chi.resize(n + 1);

	int k, a, prev;
	for(int i = 0; i < m; i++)
	{
		cin >> k;
		for(int j = 0; j < k; j++)
		{
			cin >> a;
			if(j != 0)
			{
				push(prev, a);
			}
			prev = a;
		}
	}

	// 위상 정렬
	int flag = -1;
	for(int i = 1; i <= n; i++)
	{
		if(!chi[i].empty()) continue; 
		flag = 1;
		if(DFS(i) == -1) 
		{
			flag = -1;
			break;
		}
	}

	if(flag == -1) cout << 0;
	else 
	{
		for(int i = 0; i < res.size(); i++) cout << res[i] << '\n';
	}

	return 0;
}
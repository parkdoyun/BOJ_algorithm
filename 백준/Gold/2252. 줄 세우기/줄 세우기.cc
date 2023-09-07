#include <iostream>
#include <vector>

using namespace std;

int n, m;
int chk[32001]; // 줄 섰는지 (섰다면 1)
vector<vector<int> > par; // 먼저 서야 하는 애들

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
	cin >> n >> m;
	par.resize(n + 1);

	int a, b;
	for(int i = 0; i < m; i++)
	{
		cin >> a >> b;
		par[b].push_back(a);
	}

	// par 없는 애들 먼저
	int cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		if(par[i].empty())
		{
			cout << i << ' ';
			chk[i] = 1;
			cnt++;
		}
	}

	// 계속 돌아가면서 비교
	while(cnt < n)
	{
		for(int i = 1; i <= n; i++)
		{
			if(chk[i] == 1) continue;
			int flag = 1;
			for(int j = 0; j < par[i].size(); j++)
			{
				if(chk[par[i][j]] == 0)
				{
					flag = -1;
					break;
				}
			}
			if(flag == 1)
			{
				cout << i << ' ';
				chk[i] = 1;
				cnt++;
			}
			if(cnt == n) break;
		}
	}

	return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// 백준 14725 - 개미굴
// 나중에 트리 저장 위해 순회 시 정렬하면서 순회

int n;
vector<string> info; // 0번 루트
vector<vector<int> > child; // 자식, 0번 루트
struct node
{
	int idx;
	string name;
};
bool cmp(node n1, node n2)
{
	return n1.name < n2.name;
}

void traversal(int now, int depth)
{
	if(now != 0)
	{
		for(int i = 0; i < depth - 1; i++) cout << "--";
		cout << info[now] << '\n';
	}

	vector<node> vec_tmp;
	for(int i = 0; i < child[now].size(); i++)
	{
		node n2;
		n2.idx = child[now][i];
		n2.name = info[child[now][i]];
		vec_tmp.push_back(n2);
	}

	sort(vec_tmp.begin(), vec_tmp.end(), cmp);

	for(int i = 0; i < vec_tmp.size(); i++)
	{
		traversal(vec_tmp[i].idx, depth + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	info.resize(1);
	child.resize(15001);

	int k;
	string str;
	int pos; // 위치
	int flag;

	for(int i = 0; i < n; i++)
	{
		cin >> k;
		pos = 0; // root
		for(int j = 0; j < k; j++)
		{
			cin >> str;

			flag = -1;
			for(int r = 0; r < child[pos].size(); r++)
			{
				if(info[child[pos][r]] == str)
				{
					flag = 1;
					pos = child[pos][r];
					break;
				}
			}
			if(flag == -1) // 추가
			{
				info.push_back(str);
				child[pos].push_back(info.size() - 1);
				pos = info.size() - 1;
			}
		}
	}

	// 순회
	traversal(0, 0);


	return 0;
}
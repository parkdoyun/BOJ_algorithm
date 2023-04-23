#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>

using namespace std;

// 백준 6443 - 애너그램

// backtracking
// 시간초과

// bfs, 비트마스킹으로 해보자
// 아니면 한 for문 돌때 벡터 전부 확인 (비트 마스킹 검사해서 붙일지 말지)
// 만약 map에 있다면 추가 안 함

int path[21];
int n, len;
string origin_s;

struct alpha
{
	string s = "";
	int flag = 0;
};
queue<alpha> q;
vector<string> vec;
map<string, int> map1;

void bfs()
{
	while (!q.empty()) q.pop();
	vec.clear();

	q.push({ "", 0 });

	while (!q.empty())
	{
		alpha tmp = q.front();
		q.pop();

		if (map1.find(tmp.s) != map1.end()) continue;
		map1.insert({ tmp.s, 1 });

		if (tmp.s.length() == len)
		{
			vec.push_back(tmp.s);
			continue;
		}

		for (int i = 0; i < len; i++)
		{
			if (((1 << i) & tmp.flag) != 0) continue;
			q.push({ tmp.s + origin_s[i], tmp.flag | (1 << i) });
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	string print_s;
	for (int i = 0; i < n; i++)
	{
		cin >> origin_s;
		len = origin_s.length();
		bfs();
		sort(vec.begin(), vec.end());
		
		print_s = vec[0];
		cout << print_s << '\n';
		for (int j = 1; j < vec.size(); j++)
		{
			if (print_s == vec[j]) continue;
			print_s = vec[j];
			cout << print_s << '\n';
		}
		map1.clear();
	}

	return 0;
}
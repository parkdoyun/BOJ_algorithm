#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 자신보다 큰 사람과 추고 싶어하는 사람과 작은 사람과 추고 싶어하는 사람 따로

bool cmp(int a, int b)
{
	return a < b;
}

int n;
vector<int> boy_h;
vector<int> boy_l;
vector<int> girl_h;
vector<int> girl_l;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	int a;
	for(int i = 0; i < n; i++)
	{
		cin >> a;
		if(a < 0) boy_l.push_back(a * -1);
		else boy_h.push_back(a);
	}

	for(int i = 0; i < n; i++)
	{
		cin >> a;
		if(a < 0) girl_l.push_back(a * -1);
		else girl_h.push_back(a);
	}

	sort(boy_h.begin(), boy_h.end(), cmp);
	sort(boy_l.begin(), boy_l.end(), cmp);
	sort(girl_h.begin(), girl_h.end(), cmp);
	sort(girl_l.begin(), girl_l.end(), cmp);

	// 쌍 맞추기
	int cnt = 0;
	int oppo = 0;
	for(auto e : boy_h)
	{
		while(oppo < girl_l.size() && girl_l[oppo] <= e) oppo++;
		if(oppo == girl_l.size()) break; // 끝까지 다 왔음
		cnt++;
		oppo++;
	}

	oppo = 0;
	for(auto e : girl_h)
	{
		while(oppo < boy_l.size() && boy_l[oppo] <= e) oppo++;
		if(oppo == boy_l.size()) break; // 끝까지 다 왔음
		cnt++;
		oppo++;
	}

	cout << cnt;

	return 0;
} 
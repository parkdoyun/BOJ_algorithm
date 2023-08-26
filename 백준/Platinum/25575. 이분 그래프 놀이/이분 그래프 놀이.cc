#include <iostream>
#include<vector>
#include<cassert>
#include<cstdio>
#include<map>
#include<set>
#include<cstring>
#include<cstring>
#include<memory>
#include<algorithm>
#include<string>
#include<iostream>
#include<queue>
using namespace std;

// 최대 그래프 -> 차원 높을수록 높은 번호 부여
// 그 후, 간선 하나씩 빼면서 각 최대 그래프 구하고, 그 중 최댓값 출력

#define FOR(_i,_a,_b) for(int _i = (_a); _i < (_b); _i++)
#define FORE(it,x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); ++it)
#define pb push_back
typedef long long ll;

const int maxn = 16384, maxm = 131072;

int n, m, k;
int dv[maxn], dw[maxn];
int tmp_dv[maxn], tmp_dw[maxn];
int ed[maxm][2];
ll minv[maxn], minw[maxn];

class Sol {

	ll solve_once() {
		ll tot = 0;
		FOR(i, 0, n) tmp_dv[i] = dv[i];
		FOR(i, 0, m) tmp_dw[i] = dw[i];
		sort(tmp_dv, tmp_dv + n); // 차원 순으로 정렬
		sort(tmp_dw, tmp_dw + m);
		memset(minv, -1, sizeof(minv));
		memset(minw, -1, sizeof(minw));
		FOR(i, 0, n) { // 각 정점마다 (X)
			ll v1 = i + 1, v2 = tmp_dv[i];
			tot += v1 * v2; // 번호 * 연결된 간선 갯수 더하기
			if (minv[tmp_dv[i]] == -1) minv[tmp_dv[i]] = v1;
		}

		FOR(i, 0, m) { // 각 정점마다 (Y)
			ll v1 = i + 1, v2 = tmp_dw[i];
			tot += v1 * v2; // 번호 * 연결된 간선 갯수 더하기
			if (minw[tmp_dw[i]] == -1) minw[tmp_dw[i]] = v1;
		}
		return tot;
	}
public:
	pair<ll, ll> solve() {
		pair<ll, ll> ans;
		ans.first = solve_once(); // 가장 차원 많은 정점 순으로 번호 부여, 최대 그래프 계산
		ans.second = 0;
		FOR(i, 0, k) { // 간선 하나씩 빼기
			ll val = 0;
			val = ans.first - minv[dv[ed[i][0]]] - minw[dw[ed[i][1]]];
			ans.second = max(ans.second, val); // 그렇게 만든 최대 그래프 비교
		}
		return ans;
	}
};

int main() {
	Sol* ins = new Sol();
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		memset(dv, 0, sizeof(dv));
		memset(dw, 0, sizeof(dw));

		// 그래프 입력
		FOR(i, 0, k) {
			cin >> ed[i][0] >> ed[i][1];
			ed[i][0]--;
			ed[i][1]--;
			dv[ed[i][0]]++; // 해당 정점의 차원 갯수 추가 (X)
			dw[ed[i][1]]++; // 해당 정점의 차원 갯수 추가 (Y)
		}

		// 계산
		pair<ll, ll> ans = ins->solve();
		cout << ans.first << ' ' << ans.second << '\n';
	}
	return 0;
}
#include <iostream>
#include <string>

using namespace std;

// 어차피 절대 절반을 안 넘는다 (N이)
// 왼쪽 절반만 따져도 됨

int n;
bool flag = false;
char res;
void traversal(int left, int &right, int depth, int &len)
{
	if (flag == true) return;

	if (depth == 0)
	{
		right = left + 2;
		len = 2;
		return;
	}

	int r, ll;
	traversal(left, r, depth - 1, ll);
	if (flag == true) return;

	if (n >= left && n <= r)
	{
		if (n == left) res = 'm';
		else res = 'o';
		flag = true;
		return;
	}
	else if (n >= r + 1 && n <= r + 1 + depth + 2) // 사이에
	{
		if (n == r + 1) res = 'm';
		else res = 'o';
		flag = true;
		return;
	}
	else if (n >= r + depth + 4 && n <= r + depth + 4 + ll)
	{
		// 어차피 첫번째 traversal한 거랑 똑같음
		int rr, ll2;
		traversal(r + depth + 4, rr, depth - 1, ll2);
		if (flag == true) return;
		if (n == r + depth + 4) res = 'm';
		else res = 'o';
		flag = true;
	}

	right = r + depth + 4 + ll;
	len = right - left;
}

int find(int num)
{
	if (num == 1 || num == 2) return 1;
	int res = 3;
	for (int i = 1; i <= num; i++)
	{
		if (res >= num) return i;
		res = (res * 2) + i + 3;
	}
	return -1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	int total_depth = find(n); // 시간 단축 위하여 (어차피 초반부 더해지는 거 똑같음, N에 비하여 S(N) 엄청 큼)
	//cout << total_depth;

	int r, l;
	traversal(1, r, total_depth, l);

	cout << res;

	return 0;
}
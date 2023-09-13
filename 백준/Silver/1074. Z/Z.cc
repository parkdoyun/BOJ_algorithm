#include <iostream>
#include <cmath>

using namespace std;

int r, c;
bool flag = false;

int traversal(int y, int x, int n, int num)
{
	if(flag == true) return -1;
	if(n == 1)
	{
		if(y == r && x == c)
		{
			cout << num;
			flag = true;
		}
		return num + 1;
	}

	int s = n / 2;

	int a = traversal(y, x, s, num);
	int t = a - num;
	if(r >= y && r <= y + s && c >= x + s && c <= x + s + s) traversal(y, x + s, s, a);
	if(r >= y + s && r <= y + s + s && c >= x && c <= x + s) traversal(y + s, x, s, a + t);
	if(r >= y + s && r <= y + s + s && c >= x + s && c <= x + s + s) traversal(y + s, x + s, s, a + t * 2);

	return a + t * 3;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n >> r >> c;

	traversal(0, 0, pow(2, n), 0);

	return 0;
}
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 소수
// 맨 첫번째에는 2, 3, 5, 7만 가능 (소수)
// 두번째부터는 홀수 가능 1, 3, 5, 7, 9 붙여보고 소수인지 확인

bool IsPrime(int num)
{
	for (int i = 2; i < num; i++)
	{
		if (num % i == 0) return false;
	}
	return true;
}
int n;

string arr[] = { "1", "3", "5", "7", "9" };
void DFS(int lv, string now)
{
	if (!IsPrime(stoi(now))) return;

	if (lv == n)
	{
		cout << now << '\n';
		return;
	}

	for (int i = 0; i < 5; i++)
	{
		DFS(lv + 1, now + arr[i]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	DFS(1, "2");
	DFS(1, "3");
	DFS(1, "5");
	DFS(1, "7");

	return 0;
}
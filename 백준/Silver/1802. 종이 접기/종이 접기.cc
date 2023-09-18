#include <iostream>
#include <string>

using namespace std;

// 절반 나눌 때 반씩 반전이어야 함
// 100 0 110 -> 100 / 110 반전이므로 괜찮다
// 1 0 0 -> 1 / 0
// 1 1 0 -> 1 / 0 -> YES

// 0 0 0 -> 0 / 0 반전 아니므로 NO

bool traversal(string s1, string s2, int n)
{
	if (n == 1)
	{
		if (s1 != s2) return true;
		else return false;
	}

	if (!traversal(s1.substr(0, n / 2), s1.substr(n / 2 + 1), n / 2)) return false;
	if (!traversal(s2.substr(0, n / 2), s2.substr(n / 2 + 1), n / 2)) return false;
	for (int i = 0; i < s1.length(); i++)
	{
		if (s1[i] == s2[s1.length() - i - 1]) return false;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	string tmp, s1, s2;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> tmp;
		if (tmp.length() == 1) // 예외
		{
			cout << "YES\n";
			continue;
		}
		
		s1 = tmp.substr(0, tmp.length() / 2);
		s2 = tmp.substr(tmp.length() / 2 + 1);

		if (traversal(s1, s2, tmp.length() / 2))
		{
			cout << "YES\n";
		}
		else cout << "NO\n";
	}

	return 0;
}
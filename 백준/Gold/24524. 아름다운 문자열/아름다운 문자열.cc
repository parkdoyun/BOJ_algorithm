#include <iostream>
#include <string>

using namespace std;

// 무조건 앞쪽부터 가져가는 게 낫다 (순서 유지)
int chk[1000001][27];
int alpha_pos[26]; // T에서 각 알파벳의 위치
int alpha_height[26]; // 채워진 높이

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
	string S, T;
	cin >> S >> T;

	for(int i = 0; i < 26; i++) alpha_pos[i] = -1; // T에 안 들어가는 알파벳 -1

	for(int i = 0; i < T.length(); i++)
	{
		alpha_pos[(int)(T[i] - 'a')] = i;
	}

	int now = 0;
	int pos;
	for(int i = 0; i < S.length(); i++)
	{
		pos = alpha_pos[(int)(S[i] - 'a')];
		if(pos == -1) continue; // T에 없는 문자

		if(pos != 0 && (alpha_height[pos - 1] <= alpha_height[pos])) continue; // 얘를 붙일 수 없음

		chk[alpha_height[pos]][pos] = 1;
		alpha_height[pos]++;
	}

	// check
	cout << alpha_height[T.length() - 1] << '\n';

	return 0;
}
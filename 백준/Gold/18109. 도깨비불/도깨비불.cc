#include <iostream>
#include <string>
#include <map>

using namespace std;

// 1. 이전 글자가 종성 X, 다음 글자가 있을 때
// 2. 이전 글자의 종성과 다음 글자의 초성이 합쳐져 이중 받침이 될 때 (ㄳ, ㄵ, ㄶ, ㄺ, ㄻ, ㄼ, ㄽ, ㄾ, ㄿ, ㅀ, ㅄ)
// (+) 이전 글자의 종성이 이중 받침이라면 / 단일 받침인데 이중 받침 될 수 없다면 도깨비불 현상 X
// (r, t), (s, w/g), (f, r/a/q/t/x/v/g), (q, t) 

//  초성, 중성, 종성
string first[] = {"r", "R", "s", "e", "E", "f", "a", "q", "Q", "t", "T", "d", "w", "W", "c", "z", "x", "v", "g"};
string middle[] = {"k", "o", "i", "O", "j", "p", "u", "P", "h", "hk", "ho", "hl", "y", "n", "nj", "np", "nl", "b", "m", "ml", "l"};
string last[] = {"r", "R", "rt", "s", "sw", "sg", "e", "f", "fr", "fa", "fq", "ft", "fx", "fv", "fg", "a", "q", "qt", "t", "T", "d", "w", "c", "z", "x", "v", "g"};

map<string, bool> map_first;
map<string, bool> map_middle;
map<string, bool> map_last;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// map insert
	for (auto e : first)
	{
		map_first.insert({e, true});
	}
	for (auto e : middle)
	{
		map_middle.insert({e, true});
	}
	for (auto e : last)
	{
		map_last.insert({e, true});
	}

	string s;

	int cnt = 0;

	string tmp;
	string prev_last; // 이전 종성

	cin >> s;
	while(!cin.eof())
	{
		int s_len = s.length();
		int flag = -1; // 종성 없었다면 1, 있었는데 이중 받침이 될 수 있는 애였으면 2, 나머지 -1
		for(int i = 0; i < s_len; )
		{
			// 초성 확인
			tmp = "";
			tmp += s[i];
			if(flag == 1 && (map_last.find(tmp) != map_last.end())) cnt++; // 1. 이전 글자가 종성 X, 초성이 종성에 올 수 있을 때
			if(i + 1 < s_len) tmp += s[i + 1];
			if((i + 1 < s_len) && (map_first.find(tmp) != map_first.end())) i += 2;
			else if(i + 1 < s_len)
			{
				tmp.pop_back();
				i++;
			}
			else i++;
			//cout << tmp << '\n';
			if(flag == 2) // 2. 이전 글자의 종성과 다음 글자의 초성이 합쳐져 이중 받침이 될 때
			{
				if(tmp.length() == 1 && prev_last.length() == 1)
				{
					if(prev_last == "r" && tmp == "t") cnt++;
					else if(prev_last == "s")
					{
						if(tmp == "w" || tmp == "g") cnt++;
					}
					else if(prev_last == "f")
					{
						if(tmp == "r" || tmp == "a" || tmp == "q" || tmp == "t" || tmp == "x" || tmp == "v" || tmp == "g") cnt++;
					}
					else if(prev_last == "q" && tmp == "t") cnt++;
				}
			}
			flag = -1;
			if(i >= s_len) break;

			// 중성 확인
			tmp = "";
			tmp += s[i];
			if(i + 1 < s_len) tmp += s[i + 1];
			if((i + 1 < s_len) && (map_middle.find(tmp) != map_middle.end())) i += 2;
			else if(i + 1 < s_len)
			{
				tmp.pop_back();
				i++;
			}
			else i++;
			//cout << tmp << '\n';
			if(i >= s_len) break;

			// 종성 있는지 확인
			// 다음 중성 전까지 몇개 있는지 확인
			// 3개 -> 종성 2 초성 1 (도깨비불 X, flag = -1)
			// 2개 -> 종성과 초성 하나씩 (flag = 2)
			// 1개 -> 초성 하나 (flag = 1)
			int next_i = s_len;
			for(int j = i; j < s_len; j++)
			{
				tmp = "";
				tmp += s[j];
				if(map_middle.find(tmp) != map_middle.end())
				{
					next_i = j;
					break;
				}
			}
			if(next_i == s_len) // 이 종성이 끝임
			{
				break;
			}

			prev_last = "";
			if(next_i - i == 3) // 3개 -> 종성 2 초성 1 (도깨비불 X, flag = -1)
			{
				prev_last = prev_last + s[i] + s[i + 1];			
				flag = -1;
				i += 2;
			}
			else if(next_i - i == 2) // 2개 -> 종성과 초성 하나씩 (flag = 2)
			{
				prev_last = prev_last + s[i];
				flag = 2;
				i++;
			}
			else if(next_i - i == 1) // 1개 -> 초성 하나 (flag = 1)
			{
				flag = 1;
			}
			else // 예외 처리
			{
				i++;
				flag = -1;
			}
			//cout << prev_last << ' ' << flag << '\n';

		}

		cin >> s;
	}

	cout << cnt;

	return 0;
} 
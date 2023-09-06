#include <iostream>
#include <string>
#include <stack>

using namespace std;

// 백준 4828 - XML
// string

/*
1. 문자열 검사
	1-1. 모든 문자가 32 ~ 127 사이에 있는지
	1-2. <, >, &이 있진 않은지
	1-3. &xHEX에서 올바른 16진수인지 (안 되는 경우 : 0x6, 0xHH, 0x128, ..)
	1-4. 태그 짝 맞는지
	1-5. 빈 문자열도 올바른 문자열
2. 검사 후 stack 비었는지
*/

stack<string> st; // 태그 체크용

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string input, tmp;

	while(true)
	{
		getline(cin, input); // 한줄 입력
		if(cin.eof()) break; // End Of File

		while(!st.empty()) st.pop();
		int flag = -1;
		for(int i = 0; i < input.length(); i++)
		{
			if(input[i] == '<') // '>'까지 확인
			{
				tmp = "";
				i++;
				while(true)
				{
					if(i == input.length()) // 입력 끝이라면
					{
						flag = 1;
						break;
					}
					if(input[i] == '>')
					{
						break;
					}
					else if(input[i] == '<')
					{
						flag = 1;
						break;
					}
					else if(input[i] == '/')
					{
						if(i + 1 == input.length())
						{
							flag = 1;
							break;
						}
						else if(tmp.length() > 0 && input[i + 1] != '>') 
						{
							flag = 1;
							break;
						}
					}
					else if(!((input[i] >= '0' && input[i] <= '9') || (input[i] >= 'a' && input[i] <= 'z'))) // 태그 내부는 숫자, 알파벳 소문자만
					{
						flag = 1;
						break;
					}
					tmp += input[i];
					i++;					
				}
				if(flag == -1) // 안전한 문자열
				{
					if(tmp[0] == '/' && tmp[tmp.length() - 1] == '/') // </tag/>
					{
						flag = 1;
					}
					else if(tmp[0] == '/') // 태그 비교
					{
						tmp.erase(0, 1); // 첫 글자 지우기
						if(st.empty()) flag = 1; // 스택 비었다면
						else if(tmp == st.top()) st.pop(); // 맞다면 스택에서 제거
						else flag = 1; // 다르다면
					}
					else if(tmp[tmp.length() - 1] == '/')
					{
						;
					}
					else // stack push
					{
						st.push(tmp);
					}
				}
			}
			else if(input[i] == '>') // 짝 없는 괄호 -> invalid
			{
				flag = 1;
				break;
			}
			else if(input[i] == '&') // 16진수 및 인코딩 문자열인지 확인
			{
				tmp = "";
				i++;
				while(true)
				{
					if(i == input.length())
					{
						flag = 1;
						break;
					}
					else if(input[i] == ';')
					{
						break;
					}
					else if(input[i] == '>' || input[i] == '<')
					{
						flag = 1;
						break;
					}
					else if(input[i] >= 32 && input[i] <= 127)
					{
						;
					}
					else 
					{
						flag = 1;
						break;
					}
					tmp += input[i];
					i++;
				}
				if(flag == -1) // 올바른 문자열
				{
					if(tmp[0] == 'x') // 16진수 체크
					{
						tmp.erase(0, 1);
						if(tmp.empty() || (tmp.length() % 2 == 1)) flag = 1;
						else
						{
							for(int j = 0; j < tmp.length(); j++)
							{
								if(tmp[j] >= '0' && tmp[j] <= '9') continue;
								else if(tmp[j] >= 'A' && tmp[j] <= 'F') continue;
								else if(tmp[j] >= 'a' && tmp[j] <= 'f') continue; // 16진수 소문자도 됨
								flag = 1; 
								break;
							}
						}
					}
					else if(!(tmp == "lt" || tmp == "gt" || tmp == "amp")) flag = 1;
				}
			}
			else if(input[i] >= 32 && input[i] <= 127) continue;
			else{
				flag = 1;
				break;
			}
			if(flag == 1) break;
		}

		if(!st.empty()) flag = 1; // stack 비었는지 확인

		if(flag == -1) cout << "valid\n";
		else cout << "invalid\n";
	}
	return 0;
}
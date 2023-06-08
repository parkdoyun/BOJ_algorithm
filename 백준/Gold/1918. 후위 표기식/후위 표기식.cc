#include <iostream>
#include <string>
#include <stack>

using namespace std;

// 괄호 안에 있거나, 연산자 우선순위 높다면 (+,- vs *,/) 먼저 수식에 들어가야 함
// 괄호 끝나거나/우선순위 높은 연산(*, /) 후 무조건 뒤에 연산자 붙음
// 괄호 안에 들어가 있거나 높은 연산자면 무조건 넣기

struct node
{
	char op; // 연산자
	int depth = 0; // 괄호 깊이
};

stack<node> st;
stack<string> oper; // 피연산자

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string origin_expr, expr;
	cin >> origin_expr;
	expr = "";

	string tmp_operand = "";
	char e;
	int par_depth = 0; // 현재 괄호 깊이
	for (int i = 0; i < origin_expr.size(); i++)
	{
		e = origin_expr[i];
		if (e >= 'A' && e <= 'Z')
		{
			expr += e;
			tmp_operand += e;
		}
		else if (e == '+' || e == '-')
		{
			while (!st.empty() && (((st.top().op == '*'|| st.top().op == '/') && par_depth < st.top().depth) || ((st.top().op == '+' || st.top().op == '-') && par_depth <= st.top().depth)))
			{
				expr += st.top().op;
				st.pop();
				oper.pop();
			}
			oper.push(tmp_operand);
			tmp_operand.clear();
			st.push({ e , par_depth});
		}
		else if (e == '*' || e == '/')
		{
			while (!st.empty() && (((st.top().op == '*' || st.top().op == '/') && par_depth <= st.top().depth) || ((st.top().op == '+' || st.top().op == '-') && par_depth < st.top().depth)))
			{
				expr += st.top().op;
				st.pop();
				oper.pop();
			}
			if (origin_expr[i + 1] >= 'A' && origin_expr[i + 1] <= 'Z')
			{
				tmp_operand += origin_expr[i + 1];
				//oper.push(tmp_operand);

				expr += origin_expr[++i];
				expr += e;
				if (origin_expr[i + 1] == ')') // 괄호 닫는 연산일 때
				{
					i++;
					par_depth--;
				}
			}
			else if (origin_expr[i + 1] == '(') // 바로 다음 괄호 있을 때
			{
				oper.push(tmp_operand);
				tmp_operand.clear();
				st.push({ e, par_depth });
			}
		}
		else if (e == '(')
		{
			par_depth++;
		}
		else // e == ')'
		{
			par_depth--;
			if (st.empty()) continue;
 			expr += st.top().op;
			st.pop();

			tmp_operand = oper.top() + tmp_operand;
			oper.pop();
			oper.push(tmp_operand);
			tmp_operand.clear();

			// 여기서 처리
			if (i + 1 != origin_expr.size())
			{
				if (origin_expr[i + 1] == '/' || origin_expr[i + 1] == '*')
				{
					if (!st.empty() && (st.top().op == '/' || st.top().op == '*'))
					{
						while (!st.empty() && st.top().depth >= par_depth && (st.top().op == '/' || st.top().op == '*'))
						{
							expr += st.top().op;
							st.pop();
							oper.pop();
						}
					}
					else continue;
				}
			}
		}
	}
	while (!st.empty())
	{
		expr += st.top().op;
		st.pop();
	}

	cout << expr;	

	return 0;
}
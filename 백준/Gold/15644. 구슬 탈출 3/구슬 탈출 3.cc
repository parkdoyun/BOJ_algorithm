#include <iostream>
#include <string>
#include <queue>

using namespace std;

#define INF 999999999

int n, m;
char board[11][11];
int chk[11][11][11][11]; // 빨간 구슬, 파란 구슬 동시에 검사
int y_mov[] = { -1, 1, 0, 0 };
int x_mov[] = { 0, 0, -1, 1 };
string cmd[] = { "U", "D", "L", "R" };

struct node
{
	int cnt = 0; // 움직인 횟수
	string path = "";
	int ry; int rx;
	int by;	int bx;
};
queue<node> q;
int min1 = INF;
string res_path;

int move(int &y, int &x, int dir) // 1 : 구멍에 들어감, 0 : 안 들어감
{
	while (y >= 0 && y < n && x >= 0 && x < m && board[y][x] != '#' && board[y][x] != 'R' && board[y][x] != 'B')
	{
		y += y_mov[dir];
		x += x_mov[dir];
		if (board[y][x] == 'O') return 1;
	}
	y -= y_mov[dir];
	x -= x_mov[dir];
	return 0;
}

void BFS()
{
	int ry2, rx2, by2, bx2, t;
	while (!q.empty())
	{
		node tmp = q.front();
		q.pop();

		if (chk[tmp.ry][tmp.rx][tmp.by][tmp.bx] == 1) continue;
		chk[tmp.ry][tmp.rx][tmp.by][tmp.bx] = 1;
		
		if (tmp.cnt == 10) return;

		// 위쪽
		ry2 = tmp.ry; rx2 = tmp.rx;
		by2 = tmp.by; bx2 = tmp.bx;
		if (tmp.ry <= tmp.by) // 빨간 구슬 먼저
		{
			if (move(ry2, rx2, 0) == 1) // 들어감
			{
				if (move(by2, bx2, 0) == 1) // 들어감 -> X
				{
					;
				}
				else // 안 들어감
				{
					min1 = tmp.cnt + 1;
					res_path = tmp.path + cmd[0];
					return;
				}
			}
			else // 안 들어감
			{
				board[ry2][rx2] = 'R';
				t = move(by2, bx2, 0);
				board[ry2][rx2] = '.';
				if (t == 1) // 들어감
				{
					;
				}
				else // 안 들어감
				{
					q.push({ tmp.cnt + 1, tmp.path + cmd[0], ry2, rx2, by2, bx2 });
				}
			}
		}
		else // 파란 구슬 먼저
		{
			if (move(by2, bx2, 0) == 1) // 들어감
			{
				;
			}
			else // 안 들어감
			{
				board[by2][bx2] = 'B';
				t = move(ry2, rx2, 0);
				board[by2][bx2] = '.';
				if (t == 1) // 들어감
				{
					min1 = tmp.cnt + 1;
					res_path = tmp.path + cmd[0];
					return;
				}
				else
				{
					q.push({ tmp.cnt + 1, tmp.path + cmd[0], ry2, rx2, by2, bx2 });
				}
			}
		}

		// 아래쪽
		ry2 = tmp.ry; rx2 = tmp.rx;
		by2 = tmp.by; bx2 = tmp.bx;
		if (tmp.ry >= tmp.by) // 빨간 구슬 먼저
		{
			if (move(ry2, rx2, 1) == 1) // 들어감
			{
				if (move(by2, bx2, 1) == 1) // 들어감 -> X
				{
					;
				}
				else // 안 들어감
				{
					min1 = tmp.cnt + 1;
					res_path = tmp.path + cmd[1];
					return;
				}
			}
			else // 안 들어감
			{
				board[ry2][rx2] = 'R';
				t = move(by2, bx2, 1);
				board[ry2][rx2] = '.';
				if (t == 1) // 들어감
				{
					;
				}
				else // 안 들어감
				{
					q.push({ tmp.cnt + 1, tmp.path + cmd[1], ry2, rx2, by2, bx2 });
				}
			}
		}
		else // 파란 구슬 먼저
		{
			if (move(by2, bx2, 1) == 1) // 들어감
			{
				;
			}
			else // 안 들어감
			{
				board[by2][bx2] = 'B';
				t = move(ry2, rx2, 1);
				board[by2][bx2] = '.';
				if (t == 1) // 들어감
				{
					min1 = tmp.cnt + 1;
					res_path = tmp.path + cmd[1];
					return;
				}
				else
				{
					q.push({ tmp.cnt + 1, tmp.path + cmd[1], ry2, rx2, by2, bx2 });
				}
			}
		}

		// 왼쪽
		ry2 = tmp.ry; rx2 = tmp.rx;
		by2 = tmp.by; bx2 = tmp.bx;
		if (tmp.rx <= tmp.bx) // 빨간 구슬 먼저
		{
			if (move(ry2, rx2, 2) == 1) // 들어감
			{
				if (move(by2, bx2, 2) == 1) // 들어감 -> X
				{
					;
				}
				else // 안 들어감
				{
					min1 = tmp.cnt + 1;
					res_path = tmp.path + cmd[2];
					return;
				}
			}
			else // 안 들어감
			{
				board[ry2][rx2] = 'R';
				t = move(by2, bx2, 2);
				board[ry2][rx2] = '.';
				if (t == 1) // 들어감
				{
					;
				}
				else // 안 들어감
				{
					q.push({ tmp.cnt + 1, tmp.path + cmd[2], ry2, rx2, by2, bx2 });
				}
			}
		}
		else // 파란 구슬 먼저
		{
			if (move(by2, bx2, 2) == 1) // 들어감
			{
				;
			}
			else // 안 들어감
			{
				board[by2][bx2] = 'B';
				t = move(ry2, rx2, 2);
				board[by2][bx2] = '.';
				if (t == 1) // 들어감
				{
					min1 = tmp.cnt + 1;
					res_path = tmp.path + cmd[2];
					return;
				}
				else
				{
					q.push({ tmp.cnt + 1, tmp.path + cmd[2], ry2, rx2, by2, bx2 });
				}
			}
		}

		// 오른쪽
		ry2 = tmp.ry; rx2 = tmp.rx;
		by2 = tmp.by; bx2 = tmp.bx;
		if (tmp.rx >= tmp.bx) // 빨간 구슬 먼저
		{
			if (move(ry2, rx2, 3) == 1) // 들어감
			{
				if (move(by2, bx2, 3) == 1) // 들어감 -> X
				{
					;
				}
				else // 안 들어감
				{
					min1 = tmp.cnt + 1;
					res_path = tmp.path + cmd[3];
					return;
				}
			}
			else // 안 들어감
			{
				board[ry2][rx2] = 'R';
				t = move(by2, bx2, 3);
				board[ry2][rx2] = '.';
				if (t == 1) // 들어감
				{
					;
				}
				else // 안 들어감
				{
					q.push({ tmp.cnt + 1, tmp.path + cmd[3], ry2, rx2, by2, bx2 });
				}
			}
		}
		else // 파란 구슬 먼저
		{
			if (move(by2, bx2, 3) == 1) // 들어감
			{
				;
			}
			else // 안 들어감
			{
				board[by2][bx2] = 'B';
				t = move(ry2, rx2, 3);
				board[by2][bx2] = '.';
				if (t == 1) // 들어감
				{
					min1 = tmp.cnt + 1;
					res_path = tmp.path + cmd[3];
					return;
				}
				else
				{
					q.push({ tmp.cnt + 1, tmp.path + cmd[3], ry2, rx2, by2, bx2 });
				}
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	int ry, rx, by, bx;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 'R')
			{
				ry = i;
				rx = j;
				board[i][j] = '.';
			}
			else if (board[i][j] == 'B')
			{
				by = i;
				bx = j;
				board[i][j] = '.';
			}
		}
	}

	q.push({ 0, "", ry, rx, by, bx });
	BFS();

	if (min1 == INF) cout << -1;
	else cout << min1 << '\n' << res_path;

	return 0;
}
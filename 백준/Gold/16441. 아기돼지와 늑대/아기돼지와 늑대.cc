#include <iostream>
#include <queue>

using namespace std;

struct node 
{
	int y;
	int x;
	int dir;
};

int n, m;
char board[101][101];
int chk[4][101][101];
int y_mov[] = {-1, 1, 0, 0};
int x_mov[] = {0, 0, -1, 1};
queue<node> q;

void BFS()
{
	int ty, tx;
	while(!q.empty())
	{
		node tmp = q.front();
		q.pop();

		if(chk[tmp.dir][tmp.y][tmp.x] == 1) continue;
		chk[tmp.dir][tmp.y][tmp.x] = 1;
		if(board[tmp.y][tmp.x] == '#') continue;

		//cout << tmp.y << ' ' << tmp.x << '\n';

		if(board[tmp.y][tmp.x] == '+') // 빙판
		{
			ty = tmp.y;
			tx = tmp.x;
			while(board[ty][tx] == '+')
			{
				ty += y_mov[tmp.dir];
				tx += x_mov[tmp.dir];
				if(board[ty][tx] != '#') chk[tmp.dir][ty][tx] = 1;
			}
			if(board[ty][tx] == '#') // 산에 부딪힌 경우
			{
				ty -= y_mov[tmp.dir];
				tx -= x_mov[tmp.dir];
				//cout << ty << ',' << tx << '\n';
			}
			int ty2 = ty;
			int tx2 = tx;
			for(int k = 0; k < 4; k++)
			{
				ty = ty2 + y_mov[k];
				tx = tx2 + x_mov[k];
				if(ty >= 0 && ty < n && tx >= 0 && tx < m && chk[k][ty][tx] == 0 && board[ty][tx] != '#')
				{
					q.push({ty, tx, k});
				}
			}
		}
		else
		{
			for(int k = 0; k < 4; k++)
			{
				ty = tmp.y + y_mov[k];
				tx = tmp.x + x_mov[k];
				if(ty >= 0 && ty < n && tx >= 0 && tx < m && chk[k][ty][tx] == 0 && board[ty][tx] != '#')
				{
					q.push({ty, tx, k});
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

	int ty, tx;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			if(board[i][j] == 'W')
			{
				q.push({i, j, 0});
				q.push({i, j, 1});
				q.push({i, j, 2});
				q.push({i, j, 3});
			}
		}
	}

	BFS();

	// board 중 chk[i][j] = 0인 곳 중 '.'인 곳 'P'로 표시
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			int tmp_flag = 0;
			for(int k = 0; k < 4; k++)
			{
				if(chk[k][i][j] == 1)
				{
					tmp_flag = -1;
					break;
				}
			}
			if(tmp_flag == 0 && board[i][j] == '.') cout << 'P';
			else cout << board[i][j];
		}
		cout << '\n';
	}

	return 0;
} 
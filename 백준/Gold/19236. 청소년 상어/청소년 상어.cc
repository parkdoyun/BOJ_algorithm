#include <iostream>
#include <vector>

using namespace std;

// 백준 19236 - 청소년 상어

// 상어가 이동할 수 있는 최대 가짓수는 3가지
// backtraking -> 현재 board와 물고기 상황 계속 기록

struct fish
{
	int idx;
	int dir; // 방향 -> -1이면 먹힘
	int y;
	int x;
};

vector<vector<int>> board; // 0 -> 물고기 X, -1 : 상어
int y_mov[] = { -1, -1, 0, 1, 1, 1, 0, -1 }; // 방향
int x_mov[] = { 0, -1, -1, -1, 0, 1, 1, 1 };

void movFish(vector<vector<int>> &tmp_board, vector<fish> &tmp_vec)
{
	int ty, tx, tdir;

	for (int i = 1; i <= 16; i++)
	{
		if (tmp_vec[i].dir == -1)
		{
			continue; // 이미 먹힘
		}
		tdir = tmp_vec[i].dir;
		ty = tmp_vec[i].y + y_mov[tdir];
		tx = tmp_vec[i].x + x_mov[tdir];

		while (!(ty >= 0 && ty < 4 && tx >= 0 && tx < 4 && tmp_board[ty][tx] != -1))
		{
			tdir = (tdir + 1) % 8;
			if (tdir == tmp_vec[i].dir) break;
			ty = tmp_vec[i].y + y_mov[tdir];
			tx = tmp_vec[i].x + x_mov[tdir];
		}

		if ((tdir != tmp_vec[i].dir) || (tdir == tmp_vec[i].dir && 
			(ty >= 0 && ty < 4 && tx >= 0 && tx < 4 && tmp_board[ty][tx] != -1))) // 물고기 이동
		{
			tmp_vec[i].dir = tdir;
			if (tmp_board[ty][tx] == 0)
			{
				tmp_board[ty][tx] = i;
				tmp_board[tmp_vec[i].y][tmp_vec[i].x] = 0;
				tmp_vec[i].y = ty;
				tmp_vec[i].x = tx;
			}
			else // 서로 바꾸기
			{
				int a = tmp_board[ty][tx];
				tmp_board[tmp_vec[i].y][tmp_vec[i].x] = a;
				tmp_board[ty][tx] = i;
				tmp_vec[a].y = tmp_vec[i].y;
				tmp_vec[a].x = tmp_vec[i].x;
				tmp_vec[i].y = ty;
				tmp_vec[i].x = tx;
			}
		}
	}
}

int max1 = 0;
void backtracking(int sy, int sx, int sdir, vector<vector<int>> tmp_board, int tmp_score, vector<fish> tmp_vec)
{
	// 물고기 이동
	movFish(tmp_board, tmp_vec);

	// 상어 이동
	int flag = -1;
	int ty = sy;
	int tx = sx;
	int tidx;
	int tdir;
	for (int i = 0; i < 3; i++)
	{
		ty = ty + y_mov[sdir];
		tx = tx + x_mov[sdir];
		if (ty < 0 || ty >= 4 || tx < 0 || tx >= 4 || tmp_board[ty][tx] == 0) continue;
		flag = 1;

		// 물고기 먹기
		tidx = tmp_board[ty][tx];
		tmp_score += tidx;
		tdir = tmp_vec[tmp_board[ty][tx]].dir;
		tmp_vec[tmp_board[ty][tx]].dir = -1;

		tmp_board[sy][sx] = 0;
		tmp_board[ty][tx] = -1;

		backtracking(ty, tx, tdir, tmp_board, tmp_score, tmp_vec);

		tmp_board[ty][tx] = tidx;
		tmp_board[sy][sx] = -1;
		tmp_vec[tmp_board[ty][tx]].dir = tdir;
		tmp_score -= tidx;
	}

	if (flag == -1) // 만약 이동할 수 없다면, return
	{
		if (max1 < tmp_score) max1 = tmp_score;
		return;
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int a, b;
	board.resize(4);
	vector<fish> tmp_vec(17); // backtracking 동안 이동

	for (int i = 0; i < 4; i++)
	{
		board[i].resize(4);
		for (int j = 0; j < 4; j++)
		{
			cin >> a >> b;
			board[i][j] = a;
			tmp_vec[a].idx = a;
			tmp_vec[a].dir = b - 1;
			tmp_vec[a].y = i;
			tmp_vec[a].x = j;
		}
	}

	int sidx = board[0][0];
	int sdir = tmp_vec[board[0][0]].dir;
	tmp_vec[board[0][0]].dir = -1;
	board[0][0] = -1;

	backtracking(0, 0, sdir, board, sidx, tmp_vec);

	cout << max1;

	return 0;
}
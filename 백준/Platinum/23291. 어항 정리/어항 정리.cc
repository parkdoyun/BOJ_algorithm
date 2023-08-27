#include <iostream>

using namespace std;

int n, k;
int board[101][101];
int tmp_board[101][101];
int tmp_board2[101][101];
int chk[101][101]; // 물고기 수 조절 시 체크 배열
int y_mov[] = { -1, 1, 0, 0 };
int x_mov[] = { 0, 0, -1, 1 };

void rotate1()
{
	// 물고기 수 가장 적은 어항에 한마리씩 넣기
	int min1 = board[0][0];
	for (int i = 1; i < n; i++)
	{
		if (min1 > board[0][i]) min1 = board[0][i];
	}
	for (int i = 0; i < n; i++)
	{
		if (min1 == board[0][i]) board[0][i]++;
	}

	board[1][1] = board[0][0];
	board[0][0] = 0;

	// 회전
	int sy = 0; // 시작점
	int sx = 1;
	int now_row = 1; // 옮겨야 하는 행수
	int now_col = 1; // 옮겨야 하는 열수
	// now_row * now_col만큼 옮겨야 함
	for (int count = 1; count <= n; count++) // i줄만큼 이동
	{
		// 못 옮기면 나가기 (공간 부족해서)
		if (count % 2 == 1) now_row++;
		else now_col++;

		// 못 옮기면 나가기 (공간 부족해서)
		if (n - sx - now_col < now_row) break;

		sy = 0;

		// 옮기기
		for (int i = 0; i < now_row; i++)
		{
			for (int j = 0; j < now_col; j++)
			{
				tmp_board[i][j] = board[sy + i][sx + j];
				board[sy + i][sx + j] = 0; // 비우기
			}
		}

		// 90도 회전
		for (int i = 0; i < now_col; i++)
		{
			for (int j = 0; j < now_row; j++)
			{
				tmp_board2[i][j] = tmp_board[now_row - j - 1][i];
			}
		}

		sx += now_col;
		sy = 1;

		// 위에 쌓기
		int idx = now_col - 1;
		int idx2 = now_row - 1;
		for (int i = 0; i < now_col; i++)
		{
			idx2 = now_row - 1;
			for (int j = 0; j < now_row; j++)
			{
				board[sy + i][sx + j] = tmp_board2[idx][idx2];
				idx2--;
			}
			idx--;
		}
	}
}

void chkClr()
{
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++) chk[i][j] = 0;
	}
}

void controlFish()
{
	chkClr();
	int ty, tx;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == 0) continue;
			for (int k = 0; k < 4; k++)
			{
				ty = i + y_mov[k];
				tx = j + x_mov[k];
				if (ty >= 0 && ty < n && tx >= 0 && tx < n && board[ty][tx] != 0 && board[i][j] > board[ty][tx])
				{
					int d = (board[i][j] - board[ty][tx]) / 5;
					if (d > 0)
					{
						chk[i][j] -= d;
						chk[ty][tx] += d;
					}
				}
			}
		}
	}

	// chk 배열 적용
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (chk[i][j] == 0) continue;
			board[i][j] += chk[i][j];
		}
	}
}

void makeOne()
{
	int idx = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[j][i] == 0) continue;
			tmp_board[0][idx] = board[j][i];
			board[j][i] = 0;
			idx++;
		}
	}

	for (int i = 0; i < n; i++)
	{
		board[0][i] = tmp_board[0][i];
	}
}

void rotate2()
{
	int sy = 0;
	int sx = 0;
	int now_row = 1; // 옮겨야 하는 행수
	int now_col = n / 2; // 옮겨야 하는 열수
	// now_row * now_col만큼 옮겨야 함
	for (int count = 0; count < 2; count++)
	{
		sy = 0;

		// 옮기기
		for (int i = 0; i < now_row; i++)
		{
			for (int j = 0; j < now_col; j++)
			{
				tmp_board[i][j] = board[sy + i][sx + j];
				board[sy + i][sx + j] = 0; // 비우기
			}
		}

		// 180도 회전
		int idx;
		for (int i = 0; i < now_row; i++)
		{
			idx = now_col - 1;
			for (int j = 0; j < now_col; j++)
			{
				tmp_board2[i][j] = tmp_board[i][idx];
				idx--;
			}
		}

		sx += now_col;
		sy += now_row;

		// 위에 쌓기
		idx = now_row - 1;
		for (int i = 0; i < now_row; i++)
		{
			for (int j = 0; j < now_col; j++)
			{
				board[sy + i][sx + j] = tmp_board2[idx][j];
			}
			idx--;
		}

		now_col /= 2;
		now_row++;
	}
}

int solve()
{
	// 회전
	rotate1();

	// 물고기 수 조절
	controlFish();

	// 다시 일렬로 놓기
	makeOne();

	// 회전2
	rotate2();
	controlFish();

	// 다시 일렬로 놓기
	makeOne();

	int max1 = board[0][0];
	int min1 = board[0][0];
	for (int i = 1; i < n; i++)
	{
		if (max1 < board[0][i]) max1 = board[0][i];
		if (min1 > board[0][i]) min1 = board[0][i];
	}
	return max1 - min1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;

	for (int i = 0; i < n; i++)	cin >> board[0][i];
	
	int cnt = 1;
	while (solve() > k)
	{
		cnt++;
	}

	cout << cnt;

	return 0;
}
#include <iostream>

using namespace std;

// 백준 20061 - 모노미노도미노 2

int n;
int blue[4][6];
int green[6][4];
int total_score = 0;

void print()
{
	cout << "[BLUE]\n";
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 6; j++) cout << blue[i][j] << ' ';
		cout << '\n';
	}
	cout << "[GREEN]\n";
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 4; j++) cout << green[i][j] << ' ';
		cout << '\n';
	}
}

void movBlock(int t, int y, int x, int num)
{
	// block 놓기
	int tmp;
	if (t == 1)
	{
		tmp = 0;
		for (int i = 0; i < 6; i++)
		{
			if (blue[y][i] != 0) break;
			tmp = i;
		}
		blue[y][tmp] = num;
		tmp = 0;
		for (int i = 0; i < 6; i++)
		{
			if (green[i][x] != 0) break;
			tmp = i;
		}
		green[tmp][x] = num;
	}
	else if (t == 2)
	{
		tmp = 0;
		for (int i = 0; i < 6; i++)
		{
			if (blue[y][i] != 0) break;
			tmp = i;
		}
		blue[y][tmp] = num;
		blue[y][tmp - 1] = num;
		tmp = 0;
		for (int i = 0; i < 6; i++)
		{
			if (green[i][x] != 0 || green[i][x + 1] != 0) break;
			tmp = i;
		}
		green[tmp][x] = num;
		green[tmp][x + 1] = num;
	}
	else // t == 3
	{
		tmp = 0;
		for (int i = 0; i < 6; i++)
		{
			if (blue[y][i] != 0 || blue[y + 1][i] != 0) break;
			tmp = i;
		}
		blue[y][tmp] = num;
		blue[y + 1][tmp] = num;
		tmp = 0;
		for (int i = 0; i < 6; i++)
		{
			if (green[i][x] != 0) break;
			tmp = i;
		}
		green[tmp][x] = num;
		green[tmp - 1][x] = num;
	}
}

void delBlock(int flag, int row) // flag 1 : blue, 2 : green
{
	// 아래로 한칸씩만 내려오도록 (언제까지 내려와야 하는지 체크 X)
	if (flag == 1) // blue
	{
		for (int i = row; i >= 1; i--)
		{
			for (int j = 0; j < 4; j++) blue[j][i] = blue[j][i - 1];
		}
		for (int j = 0; j < 4; j++) blue[j][0] = 0;
	}
	else // 2, green
	{
		for (int i = row; i >= 1; i--)
		{
			for (int j = 0; j < 4; j++) green[i][j] = green[i - 1][j];
		}
		for (int j = 0; j < 4; j++) green[0][j] = 0;
	}
}

void block(int t, int y, int x, int num)
{
	movBlock(t, y, x, num); // block 놓기

	//print();

	// 한줄 삭제하기
	// 한줄 다 채운 경우
	// 어차피 한줄만 땡겨서 위부터 하면 됨
	int flag;
	// blue
	for (int i = 0; i < 6; i++)
	{
		flag = -1;
		for (int j = 0; j < 4; j++)
		{
			if (blue[j][i] == 0) flag = 1;
		}
		if (flag == -1) // 다 찼으면
		{
			total_score++;
			delBlock(1, i); // 한줄 삭제
		}
	}

	// green
	for (int i = 0; i < 6; i++)
	{
		flag = -1;
		for (int j = 0; j < 4; j++)
		{
			if (green[i][j] == 0) flag = 1;
		}
		if (flag == -1) // 다 찼으면
		{
			total_score++;
			delBlock(2, i); // 한줄 삭제
		}
	}

	// 0, 1줄에 블록 있는 경우 (한줄 점수 전부 먹은 후 연한 칸 확인)
	// blue
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (blue[j][i] != 0)
			{
				delBlock(1, 5);
				break;
			}
		}
	}

	// green
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (green[i][j] != 0)
			{
				delBlock(2, 5);
				break;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	int t, x, y;
	for (int i = 1; i <= n; i++)
	{
		cin >> t >> x >> y;
		block(t, x, y, i);
	}

	int cnt = 0;

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (blue[j][i] != 0) cnt++;
			if (green[i][j] != 0) cnt++;
		}
	}

	cout << total_score << '\n' << cnt;

	return 0;
}
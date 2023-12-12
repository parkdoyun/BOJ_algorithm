#include <iostream>
#include <queue>

using namespace std;

int m, n, h;
int arr[101][101][101]; // arr[z/h][y/n][x/m]
int visit[101][101][101];
int total_cnt = 0;
int cnt = 0;
int total_time = -1;

int y_mov[] = { -1, 1, 0, 0, 0, 0 };
int x_mov[] = { 0, 0, -1, 1, 0, 0 };
int z_mov[] = { 0, 0, 0, 0, -1, 1 };

struct tomato
{
	int y;
	int x;
	int z;
	int time;
};

queue<tomato> q;

void BFS()
{
	int ty, tx, tz;
	while (!q.empty())
	{
		tomato tmp = q.front();
		q.pop();

		if (visit[tmp.z][tmp.y][tmp.x] == 1) continue;
		visit[tmp.z][tmp.y][tmp.x] = 1;
		cnt++;

		if (cnt == total_cnt)
		{
			total_time = tmp.time;
			return;
		}

		for (int i = 0; i < 6; i++)
		{
			ty = tmp.y + y_mov[i];
			tx = tmp.x + x_mov[i];
			tz = tmp.z + z_mov[i];
			if (ty >= 0 && ty < n && tx >= 0 && tx < m && tz >= 0 && tz < h && visit[tz][ty][tx] == 0 && arr[tz][ty][tx] == 0)
			{
				q.push({ ty, tx, tz, tmp.time + 1 });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> m >> n >> h;

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				cin >> arr[i][j][k];
				if (arr[i][j][k] == -1) continue;
				total_cnt++;
				if (arr[i][j][k] == 1)
				{
					q.push({ j, k, i, 0 });
				}
			}
		}
	}

	BFS();

	cout << total_time;

	return 0;
}
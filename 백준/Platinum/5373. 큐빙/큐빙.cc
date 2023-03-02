#include <iostream>

using namespace std;

// 면도 시계 / 반시계 방향으로 돌려야 함

int n;
char colors[6] = { 'w', 'y', 'r', 'o', 'g', 'b' }; // 초기화용 배열
char cube[6][3][3] = 
{
	{{'w', 'w', 'w'}, {'w', 'w', 'w'}, {'w', 'w', 'w'}}, // 윗면, 흰색
	{{'y', 'y', 'y'}, {'y', 'y', 'y'}, {'y', 'y', 'y'}}, // 아랫면, 노란색
	{{'r', 'r', 'r'}, {'r', 'r', 'r'}, {'r', 'r', 'r'}}, // 앞면, 빨간색
	{{'o', 'o', 'o'}, {'o', 'o', 'o'}, {'o', 'o', 'o'}}, // 뒷면, 오렌지색
	{{'g', 'g', 'g'}, {'g', 'g', 'g'}, {'g', 'g', 'g'}}, // 왼쪽면, 초록색
	{{'b', 'b', 'b'}, {'b', 'b', 'b'}, {'b', 'b', 'b'}} // 오른쪽면, 파란색
};
char tmp_arr[3];

void faceRotate(int face, char dir)
{
	for (int i = 0; i < 3; i++) tmp_arr[i] = cube[face][0][i];
	if (dir == '+') // 시계 방향
	{
		for (int i = 0; i < 3; i++) cube[face][0][2 - i] = cube[face][i][0];
		for (int i = 0; i < 3; i++) cube[face][i][0] = cube[face][2][i];
		for (int i = 0; i < 3; i++) cube[face][2][i] = cube[face][2 - i][2];
		for (int i = 1; i < 3; i++) cube[face][i][2] = tmp_arr[i];
	}
	else // 반시계
	{
		for (int i = 0; i < 3; i++) cube[face][0][i] = cube[face][i][2];
		for (int i = 0; i < 3; i++) cube[face][i][2] = cube[face][2][2 - i];
		for (int i = 0; i < 3; i++) cube[face][2][2 - i] = cube[face][2 - i][0];
		for (int i = 1; i < 3; i++) cube[face][i][0] = tmp_arr[2 - i];
	}
}

void rotate(char face, char dir)
{
	if (face == 'U')
	{
		faceRotate(0, dir);
		if (dir == '+') // 시계 방향 (왼 -> 뒷 -> 오 -> 앞)
		{
			for (int i = 0; i < 3; i++) tmp_arr[i] = cube[2][0][i]; // 앞
			// 옮기기
			for (int i = 0; i < 3; i++) cube[2][0][i] = cube[5][0][i]; // 오 -> 앞
			for (int i = 0; i < 3; i++) cube[5][0][i] = cube[3][0][i]; // 뒷 -> 오
			for (int i = 0; i < 3; i++) cube[3][0][i] = cube[4][0][i]; // 왼 -> 뒷
			for (int i = 0; i < 3; i++) cube[4][0][i] = tmp_arr[i]; // 앞 -> 왼
		}
		else // 반시계 (앞 -> 오 -> 뒷 -> 왼)
		{
			for (int i = 0; i < 3; i++) tmp_arr[i] = cube[4][0][i]; // 왼
			// 옮기기
			for (int i = 0; i < 3; i++) cube[4][0][i] = cube[3][0][i]; // 뒷 -> 왼
			for (int i = 0; i < 3; i++) cube[3][0][i] = cube[5][0][i]; // 오 -> 뒷
			for (int i = 0; i < 3; i++) cube[5][0][i] = cube[2][0][i]; // 앞 -> 오
			for (int i = 0; i < 3; i++) cube[2][0][i] = tmp_arr[i]; // 왼 -> 앞
		}
	}
	else if (face == 'D')
	{
		faceRotate(1, dir);
		if (dir == '-') // 반시계 방향 (왼 -> 뒷 -> 오 -> 앞)
		{
			for (int i = 0; i < 3; i++) tmp_arr[i] = cube[2][2][i]; // 앞
			// 옮기기
			for (int i = 0; i < 3; i++) cube[2][2][i] = cube[5][2][i]; // 오 -> 앞
			for (int i = 0; i < 3; i++) cube[5][2][i] = cube[3][2][i]; // 뒷 -> 오
			for (int i = 0; i < 3; i++) cube[3][2][i] = cube[4][2][i]; // 왼 -> 뒷
			for (int i = 0; i < 3; i++) cube[4][2][i] = tmp_arr[i]; // 앞 -> 왼
		}
		else // 시계 (앞 -> 오 -> 뒷 -> 왼)
		{
			for (int i = 0; i < 3; i++) tmp_arr[i] = cube[4][2][i];
			// 옮기기
			for (int i = 0; i < 3; i++) cube[4][2][i] = cube[3][2][i]; // 뒷 -> 왼
			for (int i = 0; i < 3; i++) cube[3][2][i] = cube[5][2][i]; // 오 -> 뒷
			for (int i = 0; i < 3; i++) cube[5][2][i] = cube[2][2][i]; // 앞 -> 오
			for (int i = 0; i < 3; i++) cube[2][2][i] = tmp_arr[i]; // 왼 -> 앞
		}
	}
	else if (face == 'F')
	{
		faceRotate(2, dir);
		if (dir == '+') // 시계 (윗 -> 오 -> 아 -> 왼)
		{
			for (int i = 0; i < 3; i++) tmp_arr[i] = cube[4][i][2]; // 왼
			// 옮기기
			for (int i = 0; i < 3; i++) cube[4][i][2] = cube[1][2][2 - i]; // 아 -> 왼
			for (int i = 0; i < 3; i++) cube[1][2][i] = cube[5][i][0]; // 오 -> 아
			for (int i = 0; i < 3; i++) cube[5][i][0] = cube[0][2][i]; // 윗 -> 오
			for (int i = 0; i < 3; i++) cube[0][2][2 - i] = tmp_arr[i]; // 왼 -> 윗
		}
		else // 반시계 (왼 -> 아 -> 오 -> 윗)
		{
			for (int i = 0; i < 3; i++) tmp_arr[i] = cube[0][2][i]; // 윗
			// 옮기기
			for (int i = 0; i < 3; i++) cube[0][2][i] = cube[5][i][0]; // 오 -> 윗
			for (int i = 0; i < 3; i++) cube[5][i][0] = cube[1][2][i]; // 아 -> 오
			for (int i = 0; i < 3; i++) cube[1][2][i] = cube[4][2 - i][2]; // 왼 -> 아
			for (int i = 0; i < 3; i++) cube[4][2 - i][2] = tmp_arr[i]; // 윗 -> 왼
		}
	}
	else if (face == 'B')
	{
		faceRotate(3, dir);
		if (dir == '-') // 반시계 (윗 -> 오 -> 아 -> 왼)
		{
			for (int i = 0; i < 3; i++) tmp_arr[i] = cube[4][i][0]; // 왼
			// 옮기기
			for (int i = 0; i < 3; i++) cube[4][i][0] = cube[1][0][2 - i]; // 아 -> 왼
			for (int i = 0; i < 3; i++) cube[1][0][i] = cube[5][i][2]; // 오 -> 아
			for (int i = 0; i < 3; i++) cube[5][i][2] = cube[0][0][i]; // 윗 -> 오
			for (int i = 0; i < 3; i++) cube[0][0][2 - i] = tmp_arr[i]; // 왼 -> 윗
		}
		else // 시계 (왼 -> 아 -> 오 -> 윗)
		{
			for (int i = 0; i < 3; i++) tmp_arr[i] = cube[0][0][i]; // 윗
			// 옮기기
			for (int i = 0; i < 3; i++) cube[0][0][i] = cube[5][i][2]; // 오 -> 윗
			for (int i = 0; i < 3; i++) cube[5][i][2] = cube[1][0][i]; // 아 -> 오
			for (int i = 0; i < 3; i++) cube[1][0][i] = cube[4][2 - i][0]; // 왼 -> 아
			for (int i = 0; i < 3; i++) cube[4][2 - i][0] = tmp_arr[i]; // 윗 -> 왼
		}
	}
	else if (face == 'L') // 왼쪽
	{
		faceRotate(4, dir);
		if (dir == '+') // 시계 (앞 -> 아 -> 뒷 -> 윗)
		{
			for (int i = 0; i < 3; i++) tmp_arr[i] = cube[0][i][0]; // 윗
			// 옮기기
			for (int i = 0; i < 3; i++) cube[0][i][0] = cube[3][2 - i][2]; // 뒷 -> 윗
			for (int i = 0; i < 3; i++) cube[3][i][2] = cube[1][i][2]; // 아 -> 뒷
			for (int i = 0; i < 3; i++) cube[1][i][2] = cube[2][2 - i][0]; // 앞 -> 아
			for (int i = 0; i < 3; i++) cube[2][i][0] = tmp_arr[i]; // 윗 -> 앞
		}
		else // 반시계 (윗 -> 뒷 -> 아 -> 앞)
		{
			for (int i = 0; i < 3; i++) tmp_arr[i] = cube[2][i][0]; // 앞
			// 옮기기
			for (int i = 0; i < 3; i++) cube[2][i][0] = cube[1][2 - i][2]; // 아 -> 앞
			for (int i = 0; i < 3; i++) cube[1][i][2] = cube[3][i][2]; // 뒷 -> 아
			for (int i = 0; i < 3; i++) cube[3][i][2] = cube[0][2 - i][0]; // 윗 -> 뒷
			for (int i = 0; i < 3; i++) cube[0][i][0] = tmp_arr[i]; // 앞 -> 윗
		}
	}
	else // R
	{
		faceRotate(5, dir);
		if (dir == '-') // 반시계 (앞 -> 아 -> 뒷 -> 윗)
		{
			for (int i = 0; i < 3; i++) tmp_arr[i] = cube[0][i][2]; // 윗
			// 옮기기
			for (int i = 0; i < 3; i++) cube[0][i][2] = cube[3][2 - i][0]; // 뒷 -> 윗
			for (int i = 0; i < 3; i++) cube[3][i][0] = cube[1][i][0]; // 아 -> 뒷
			for (int i = 0; i < 3; i++) cube[1][i][0] = cube[2][2 - i][2]; // 앞 -> 아
			for (int i = 0; i < 3; i++) cube[2][i][2] = tmp_arr[i]; // 윗 -> 앞
		}
		else // 시계 (윗 -> 뒷 -> 아 -> 앞)
		{
			for (int i = 0; i < 3; i++) tmp_arr[i] = cube[2][i][2]; // 앞
			// 옮기기
			for (int i = 0; i < 3; i++) cube[2][i][2] = cube[1][2 - i][0]; // 아 -> 앞
			for (int i = 0; i < 3; i++) cube[1][i][0] = cube[3][i][0]; // 뒷 -> 아
			for (int i = 0; i < 3; i++) cube[3][i][0] = cube[0][2 - i][2]; // 윗 -> 뒷
			for (int i = 0; i < 3; i++) cube[0][i][2] = tmp_arr[i]; // 앞 -> 윗
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	char face, dir; // 면, 돌린 방향
	for (int tc = 1; tc <= T; tc++)
	{
		// 큐브 초기화
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				for (int r = 0; r < 3; r++) cube[i][j][r] = colors[i];
			}
		}

		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> face >> dir;

			rotate(face, dir);

		}
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << cube[0][i][j];
			}
			cout << '\n';
		}
	}

	return 0;
}
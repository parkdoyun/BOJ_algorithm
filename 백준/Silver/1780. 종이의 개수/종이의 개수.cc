#include <iostream>
#include <cmath>

using namespace std;

int arr[2188][2188];
int total_m = 0;
int total_z = 0;
int total_o = 0;

int traversal(int y, int x, int n, int &minus, int &zeros, int &ones) // 2 : 다 다름, 같다면 -1, 0, 1 중 return
{
	minus = 0;
	zeros = 0;
	ones = 0;
	if(n == 1)
	{
		if(arr[y][x] == -1) minus = 1;
		else if(arr[y][x] == 0) zeros = 1;
		else ones = 1;
		return arr[y][x];
	}

	int cmp, tmp, m, z, o;
	bool flag = true;
	bool reset = false; // 1. 밑에 애들 이미 2 return -> 포함하면 X
	for(int i = y; i < y + n; i += n / 3)
	{
		for(int j = x; j < x + n; j += n / 3)
		{
			if(i == y && j == x)
			{
				cmp = traversal(i, j, n / 3, m, z, o);
				if(cmp == 2)
				{
					flag = false;
					//total_m += m;
					//total_z += z;
					//total_o = o;
				}
				else
				{
					if(cmp == 1) ones++;
					else if(cmp == 0) zeros++;
					else minus++;
				}
			}
			else
			{
				tmp = traversal(i, j, n / 3, m, z, o);
				if(tmp == 2)
				{
					if(flag)
					{
						total_m += minus;
						total_z += zeros;
						total_o += ones;
					}
					flag = false;
				}
				else
				{
					if(flag) // 비교
					{
						if(cmp != tmp)
						{
							flag = false;
							total_m += minus + m;
							total_z += zeros + z;
							total_o += ones + o;
						}
						else
						{
							if(tmp == 1) ones++;
							else if(tmp == 0) zeros++;
							else minus++;
						}
					}
					else
					{
						total_m += m;
						total_z += z;
						total_o += o;
					}
				}
			}

		}
	}

	if(flag)
	{
		minus = 0;
		zeros = 0;
		ones = 0;
		if(cmp == -1) minus = 1;
		else if(cmp == 0) zeros = 1;
		else ones = 1;
		return cmp;
	}
	else return 2;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++) cin >> arr[i][j];
	}

	int m, z, o;
	int res = traversal(0, 0, n, m, z, o);
	if(res == 2)
	{
		cout << total_m << '\n' << total_z << '\n' << total_o;
	}
	else
	{
		if(res == -1) cout << "1\n0\n0";
		else if(res == 0) cout << "0\n1\n0";
		else cout << "0\n0\n1";
	}


	return 0;
}
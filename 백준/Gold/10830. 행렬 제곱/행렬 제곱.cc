#include <iostream>
#include <vector>

using namespace std;

int a;
long long int arr[5][5];

vector<vector<long long int> > mult(long long int n)
{
	vector<vector<long long int> > tmp_vec;
	tmp_vec.resize(a);

	if(n == 1)
	{
		for(int i = 0; i < a; i++)
		{
			for(int j = 0; j < a; j++)
			{
				tmp_vec[i].push_back(arr[i][j] % 1000);
			}
		}	
		return tmp_vec;
	}

	if(n % 2 == 0)
	{
		vector<vector<long long int> > tmp_vec1 = mult(n / 2);
		for(int i = 0; i < a; i++)
		{
			tmp_vec[i].resize(a);
			for(int j = 0; j < a; j++)
			{
				tmp_vec[i][j] = 0;
				for(int r = 0; r < a; r++)
				{
					tmp_vec[i][j] = (tmp_vec[i][j] + (tmp_vec1[i][r] * tmp_vec1[r][j]) % (long long int)1000) % (long long int)1000;
				}
			}
		}
	}
	else
	{
		vector<vector<long long int> > tmp_vec1 = mult((n - 1) / 2);
		vector<vector<long long int> > tmp_vec2;
		tmp_vec2.resize(a);
		for(int i = 0; i < a; i++)
		{
			tmp_vec2[i].resize(a);
			for(int j = 0; j < a; j++)
			{
				tmp_vec2[i][j] = 0;
				for(int r = 0; r < a; r++)
				{
					tmp_vec2[i][j] = (tmp_vec2[i][j] + (tmp_vec1[i][r] * tmp_vec1[r][j]) % (long long int)1000) % (long long int)1000;
				}
			}
		}
		for(int i = 0; i < a; i++)
		{
			tmp_vec[i].resize(a);
			for(int j = 0; j < a; j++)
			{
				for(int r = 0; r < a; r++)
				{
					tmp_vec[i][j] = (tmp_vec[i][j] + (tmp_vec2[i][r] * arr[r][j]) % (long long int)1000) % (long long int)1000;
				}
			}
		}
	}

	return tmp_vec;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long int b;
	cin >> a >> b;
	
	for(int i = 0; i < a; i++)
	{
		for(int j = 0; j < a; j++) cin >> arr[i][j];
	}

	vector<vector<long long int> > res = mult(b);

	for(int i = 0; i < a; i++)
	{
		for(int j = 0; j < a; j++) cout << res[i][j] << ' ';
		cout << '\n';
	}

	return 0;
}
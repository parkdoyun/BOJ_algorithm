#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// 용액 크기대로 정렬
// 두 용액 쌍에 대하여 이분탐색으로 가장 그 사이에서 적절한 수를 찾기???
// N * N * log(N)

vector<long long int> vec;
bool cmp(long long int a, long long int b)
{
	return a < b;
}

long long int binary_search(int start, int end, long long int &mid_val)
{
	long long int now = vec[start - 1] + vec[end + 1];
	int left = start;
	int right = end;
	int mid;
	long long int tmp;
	long long int tmp_min = 3000000001;

	while(left <= right)
	{
		mid = (left + right) / 2;
		tmp = now + vec[mid];
		if(tmp == 0)
		{
			mid_val = vec[mid];
			return 0;
		}
		else if(abs(tmp) < tmp_min)
		{
			mid_val = vec[mid];
			tmp_min = abs(tmp);
		}
		if(tmp > 0)
		{
			right = mid - 1;
		}
		else // tmp > 0
		{
			left = mid + 1;
		}
	}
	return tmp_min;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	long long int a;
	for(int i = 0; i < n; i++)
	{
		cin >> a;
		vec.push_back(a);
	}

	sort(vec.begin(), vec.end(), cmp);
	long long int b, c, tmp_res, tmp_mid;
	long long int total_min = 3000000001;
	for(int i = 0; i < n; i++)
	{
		for(int j = i + 2; j < n; j++)
		{
			tmp_res = binary_search(i + 1, j - 1, tmp_mid);
			if(tmp_res < total_min)
			{
				total_min = tmp_res;
				a = vec[i];
				b = tmp_mid;
				c = vec[j];
			}
		}
	}

	cout << a << ' ' << b << ' ' << c;

	return 0;
}
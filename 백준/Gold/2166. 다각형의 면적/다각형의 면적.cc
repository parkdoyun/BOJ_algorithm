#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// 삼각형 넓이 -> 벡터의 외적 공식으로 구할 수 있다
// 다각형을 삼각형들로 쪼개서 구한 후 더하면 됨
// 기준점을 하나로 잡고 (아무거나 괜찮음, 어차피 넘어가면 빼므로)
// 나머지 점들에 대하여 벡터의 외적으로 삼각형 계산 후 더함

struct pos
{
	long double y;
	long double x;
};

long double calTriangle(pos p1, pos p2, pos p3) // 벡터의 외적 공식
{
	return ((p1.x - p3.x) * (p2.y - p3.y) - (p1.y - p3.y) * (p2.x - p3.x)) / 2.0;
}

vector<pos> vec;

int main()
{
	int n;
	cin >> n;

	long double x, y;
	for(int i = 0; i < n; i++)
	{
		cin >> x >> y;
		vec.push_back({y, x});
	}

	// calculate
	long double res = 0.0;

	for(int i = 0; i < n - 1; i++)
	{
		res += calTriangle(vec[0], vec[i], vec[i + 1]);
	}

	if(res < 0) res *= -1;

	// 이렇게 하면 자동 소수점 두자리에서 반올림
	cout << fixed;
	cout.precision(1);
	cout << res;
	/*

	res *= 10.0;
	res = round(res);
	res /= 10.0;

	//cout.precision(1);
	printf("%.llf", res);
	*/

	return 0;
}
#include <iostream>

using namespace std;

// 선분 교차 판단 알고리즘 (CCW)
// 두 선분에 대하여 모두 검증해야 함(한 선분과 다른 선분의 양 끝점에 대하여 ccw 다른 방향이어야 함)
// 두 선분이 일직선 상에 있는지도 검사해야 함

struct pos
{
	long long int y;
	long long int x;
};
bool operator==(pos p1, pos p2)
{
	return (p1.y == p2.y) && (p1.x == p2.x);
}
int ccw(pos p1, pos p2, pos p3)
{
	long long int res = ((p1.y * p2.x) + (p2.y * p3.x) + (p3.y * p1.x)) - ((p1.x * p2.y) + (p2.x * p3.y) + (p3.x * p1.y));
	if(res > 0) return 1; // p1, p2, p3 반시계
	else if(res == 0) return 0; // 일직선
	else return -1; // 시계
}
bool greater1(pos p1, pos p2)
{
	if(p1.y == p2.y) return p1.x >= p2.x;
	return p1.y >= p2.y;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long int y1, x1, y2, x2;
	cin >> x1 >> y1 >> x2 >> y2;
	pos p1, p2, p3, p4;
	p1.y = y1;
	p1.x = x1;
	p2.y = y2;
	p2.x = x2;

	cin >> x1 >> y1 >> x2 >> y2;
	p3.y = y1;
	p3.x = x1;
	p4.y = y2;
	p4.x = x2;
	
	/*
	if((p1 == p3) || (p1 == p4) || (p2 == p3) || (p2 == p4)) // 점 겹침
	{
		cout << 1;
		return 0;
	}
	*/

	int a = ccw(p1, p2, p3) * ccw(p1, p2, p4);
	int b = ccw(p3, p4, p1) * ccw(p3, p4, p2);

	pos tmp_p;	
	if(a <= 0 && b <= 0)
	{
		if(a == 0 && b == 0) // 일직선
		{
			// 일직선이어도 겹칠 수 있음
			if(greater1(p1, p2))
			{
				tmp_p.y = p1.y;
				tmp_p.x = p1.x;
				p1.y = p2.y;
				p1.x = p2.x;
				p2.y = tmp_p.y;
				p2.x = tmp_p.x;
			}
			if(greater1(p3, p4))
			{
				tmp_p.y = p3.y;
				tmp_p.x = p3.x;
				p3.y = p4.y;
				p3.x = p4.x;
				p4.y = tmp_p.y;
				p4.x = tmp_p.x;
			}
			if(greater1(p4, p1) && greater1(p2, p3)) cout << 1;
			else cout << 0;
		}
		else cout << 1; // 교차
	}
	else cout << 0; // 교차 X

	return 0;
}

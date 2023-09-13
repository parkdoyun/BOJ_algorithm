#include <iostream>
#include <string>

using namespace std;

int n;
char arr[65][65];

string search(int y1, int x1, int y2, int x2, int gap)
{
	string tmp_str = "";
	if((y1 == y2) && (x1 == x2))
	{
		tmp_str += arr[y1][x1];
		return tmp_str;
	}

	string tmp_arr[4];
	bool flag = true;

	tmp_arr[0] = search(y1, x1, y1 + gap, x1 + gap, gap / 2);
	string tmp_c = tmp_arr[0];

	tmp_arr[1] = search(y1, x1 + gap, y1 + gap, x1 + gap * 2, gap / 2);
	if(tmp_c != tmp_arr[1]) flag = false;

	tmp_arr[2] = search(y1 + gap, x1, y1 + gap * 2, x1 + gap, gap / 2);
	if(tmp_c != tmp_arr[2]) flag = false;

	tmp_arr[3] = search(y1 + gap, x1 + gap, y1 + gap * 2, x1 + gap * 2, gap / 2);
	if(tmp_c != tmp_arr[3]) flag = false;



	if(flag && tmp_c.size() == 1) // 전부 같다
	{
		//cout << y1 << ' ' << x1 << ' ' << y2 << ' ' << x2 << ' ' << tmp_c << '\n';
		return tmp_c;
	}
	else{
		tmp_str += "(";
		for(int i = 0; i < 4; i++)
		{
			tmp_str += tmp_arr[i];
		}
		tmp_str += ")";
	}

	//cout << y1 << ' ' << x1 << ' ' << y2 << ' ' << x2 << ' ' << tmp_str << '\n';
	return tmp_str;	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++) cin >> arr[i][j];
	}

	cout << search(0, 0, n - 1, n - 1, n / 2);


	return 0;
}
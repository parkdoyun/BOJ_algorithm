#include <iostream>
#include <string>

using namespace std;

// DFS
int n, m;
string s;
int s_len;
char board[101][101];

int mov_x[8] = {0, 0, -1, 1, -1, 1, -1, 1};
int mov_y[8] = {-1, 1, 0, 0, -1, 1, 1, -1};

int search(int ty, int tx)
{
    int res;
    int tmp_y, tmp_x;
    for(int i = 0; i < 8; i++)
    {
        res = 1;
        tmp_y = ty + mov_y[i];
        tmp_x = tx + mov_x[i];

        for(int j = 0; j < s_len - 1; j++)
        {
            if(tmp_y < 0 || tmp_y >= n || tmp_x < 0 || tmp_x >= m)
            {
                res = 0;
                break;
            }
            else if(board[tmp_y][tmp_x] == s[j + 1]) ;
            else
            {
                res = 0;
                break;
            }
            tmp_y += mov_y[i];
            tmp_x += mov_x[i];
        }
        if(res == 1) return res;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> s >> n >> m;

    s_len = s.length();

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }

    int res = 0;

    for(int i = 0; i < n; i++)
    {
        if(res == 1) break;
        for(int j = 0; j < m; j++)
        {
            if(board[i][j] == s[0])
            {
                res = search(i, j);
            }
            if(res == 1) break;
        }
    }

    cout << res;

    return 0;
}
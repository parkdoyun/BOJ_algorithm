#include <iostream>

using namespace std;

int n, k, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> k >> m;

    int tmp;
    for(int i = 1; i <= n; i++)
    {
        cin >> tmp;
    }

    int cmd;
    for(int i = 0; i < m; i++)
    {
        cin >> cmd;
        
        if(cmd > 0)
        {
            if(k <= cmd)
            {
                k = cmd - k + 1;
            }
        }
        else // cmd < 0
        {
            if(k >= n + cmd + 1)
            {
                int gap = k - (n + cmd + 1);
                k = n - gap;
            }
        }
    }

    cout << k;

    return 0;
}
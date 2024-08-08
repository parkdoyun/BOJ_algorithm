#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec;
bool cmp(int a, int b)
{
    return a < b;
}

struct dice{
    int num;  
};
bool operator<(dice d1, dice d2)
{
    return d1.num > d2.num;
}
priority_queue<dice> pq;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, a;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> a;
        vec.push_back(a);
    }

    sort(vec.begin(), vec.end(), cmp);

    pq.push({1});

    for(int i = 1; i < n; i++)
    {
        a = pq.top().num;
        pq.pop();
        if(a <= vec[i])
        {
            pq.push({a + 1});
        }
        else
        {
            pq.push({a});
            pq.push({1});
        }
    }
    
    cout << pq.size();

    return 0;
}
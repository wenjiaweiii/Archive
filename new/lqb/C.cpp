#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
void solve()
{
    int n;
    cin >> n;
    vector<int> num;
    for(int i=1;i<100;i++)
    {
        if((i&1)&&!((i/10)&1))
            num.push_back(i);
    }
    int ans=0;
    queue<int> qu;
    for(int i=1;i<=min(n,99ll);i+=2)
    {
        if((i&1)&&!((i/10)&1))
        {
            qu.push(i);
            ans++;
        }
    }
    while(!qu.empty())
    {
        int tmp=qu.front();
        qu.pop();
        for(auto i:num)
        {
            int cnt=i+tmp*100;
            if(cnt<=n)
            {
                qu.push(cnt);
                ans++;
            }
        }
    }
    cout << ans << endl;
    return;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    // int o;
    // cin >> o;
    // while(o--)
    solve();

    return 0;
}
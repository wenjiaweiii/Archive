#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
void solve()
{
    int n,a,b;
    cin >> n >> a >> b;
    priority_queue<int> pq;
    for(int i=0;i<n;i++)
    {
        int num;
        cin >> num;
        pq.push(num);
    }
    while(a--)
    {
        int tmp=pq.top();
        pq.pop();
        pq.push((int)(sqrt(tmp)));
    }
    while(b--)
    {
        int tmp=pq.top();
        pq.pop();
        pq.push(tmp>>1);
    }
    int ans=0;
    while(!pq.empty())
    {
        ans+=pq.top();
        pq.pop();
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
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
const int mod=1e12;
void solve()
{
    int n;
    cin >> n;
    vector<int> num(n+1),sum(n+1);
    for(int i=1;i<=n;i++)
    {
        cin >> num[i];
        sum[i]=sum[i-1]+num[i];
    }
    multiset<int> st;
    // for(int i=1;i<=n;i++)
    // {
    //     cout << sum[i] << " ";
    // }
    // cout << endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            st.insert(sum[j]-sum[i-1]);
        }
    }
    int ans=mod;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<n;j++)
        {
            st.erase(st.find(sum[j]-sum[i-1]));
        }
        for(int j=i;j<n;j++)
        {
            int cnt=sum[j]-sum[i-1];
            auto tmp=st.lower_bound(cnt);
            if(tmp!=st.end())
                ans=min(ans,abs(*tmp-cnt));
            if(tmp!=st.begin())
                ans=min(ans,abs(*(--tmp)-cnt));

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
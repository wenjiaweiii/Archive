#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int res;
    for(int i=s.size()-1,j=0;i>=0;i--,j++)
    {
        if(s[i]=='.')
        {
            res=j;
            break;
        }
    }
    vector<int> ans(N);
    int cnt=s.size();
    for(int i=0,j=0;i<s.size();i++)
    {
        if(s[cnt-1-i]!='.')
            ans[j++]=s[cnt-1-i]-'0';
    }
    int tmp=0;
    while(n>=10)
    {
        for(int i=0;i<N;i++)
        {
            ans[i]=ans[i]*1024+tmp;
            tmp=ans[i]/10;
            ans[i]%=10;
        }
        n-=10;
    }
    while(n--)
    {
        for(int i=0;i<N;i++)
        {
            ans[i]<<=1;
            ans[i]+=tmp;
            tmp=ans[i]/10;
            ans[i]%=10;
        }
    }
    // cout << res << endl;
    for(int i=0;i<res;i++)
    {
        if(ans[i]>=5)
        {
            ans[i+1]++;
        }
    }
    bool v=false;
    for(int i=N-1;i>=res;i--)
    {
        if(ans[i])
            v=true;
        if(v)
        {
            cout << ans[i];
        }
    }
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
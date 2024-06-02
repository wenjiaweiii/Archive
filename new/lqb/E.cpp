#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
void solve()
{
    int n;
    cin >> n;
    vector<int> num(n);
    map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        cin >> num[i];
        for(int j=1;j*j<=num[i];j++)
        {
            if(num[i]%j==0)
            {
                if(j^num[i]/j)
                {
                    mp[num[i]/j]++;
                    mp[j]++;
                }else mp[j]++;
            }
        }
    }
    int cnt=0;
    for(auto i:mp)
    {
        if(i.first>=cnt&&i.second>=3)
        {
            cnt=i.first;
        }
        // cout << i.first << " " << i.second << endl;
    }
    // cout << cnt << endl;
    vector<int> ans;
    for(int i=0;i<n;i++)
    {
        if(num[i]%cnt==0)
        {
            ans.push_back(num[i]);
        }  
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<3;i++)
    {
        cout << ans[i]<< " ";
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
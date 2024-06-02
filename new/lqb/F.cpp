#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=10;
int n,k;
int num[N][N];
bool v[N][N];
int len[N][N];
int dx[8]={-1,-1,0,1,1,1,0,-1};
int dy[8]={0,1,1,1,0,-1,-1,-1};
vector<int> ans;
int res=0;
void dfs(int x,int y,int cnt)
{
    if(x==n-1&&y==n-1)
    {
        bool vis=true;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!v[i][j])
                {
                    vis=false;
                }
            }
        }
        if(vis)
        {
            for(int i=0;i<ans.size();i++)
            {
                cout << ans[i];
            }
            exit(0);
        }
    }
    for(int i=0;i<8;i++)
    {
        int tmpx=x+dx[i];
        int tmpy=y+dy[i];
        if(tmpx>=0&&tmpy>=0&&tmpx<n&&tmpy<n&&!v[tmpx][tmpy]&&num[tmpx][tmpy]==(cnt+1)%k)
        {
            bool vis=true;
            if(i==1)
            {
                if(len[x-1][y]==len[x][y+1]&&len[x-1][y])
                {
                    vis=false;
                }
            }
            if(i==3)
            {
                if(len[x+1][y]==len[x][y+1]&&len[x+1][y])
                {
                    vis=false;
                }
            }
            if(i==5)
            {
                if(len[x+1][y]==len[x][y-1]&&len[x+1][y])
                {
                    vis=false;
                }
            }
            if(i==7)
            {
                if(len[x-1][y]==len[x][y-1]&&len[x-1][y])
                {
                    vis=false;
                }
            }
            if(!vis)
                continue;
            ans.push_back(i);
            v[tmpx][tmpy]=true;
            if(i&1)
            {
                len[x][y]=++res;
                len[tmpx][tmpy]=res;
            }
            dfs(tmpx,tmpy,cnt+1);
            v[tmpx][tmpy]=false;
            ans.pop_back();
        }
    }
    return;
}
void solve()
{
    cin >> n >> k;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> num[i][j];
        }
    }
    v[0][0]=true;
    dfs(0,0,0);
    cout << -1;
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
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;
#define nl "\n"
#define dbg(x) cout << #x << " = " << x << nl

bool dfs(ll node, ll parent, vector<ll>& vis, vector<vector<ll>>& adj)
{
    vis[node] = 1;
    for(auto&x : adj[node])
    {
        if(!vis[x])
        {
            if(dfs(x,node,vis,adj) == true) return true;
        }
        else if(x!=parent) return true;
    }
    return false;
}

void solve()
{
    ll n, m; // n nodes, m edges, 0 based indexing
    cin>>n>>m;
    vector<vector<ll>> adj(n);
    for(ll i=0;i<m;i++)
    {
    ll u, v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    }
    vector<ll> vis(n,0);
    for(ll i=0;i<n;i++)
    {
        if(!vis[i])
        {
            if(dfs(i,-1,vis,adj) == true)
            {
                cout<<"Cycle Exists"<<nl;
                return;
            }
        }
    }
    cout<<"No cycle"<<nl;
     
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll testcases = 1;
    // cin >> testcases;
    for (ll testcase = 1; testcase <= testcases; testcase++)
    {
        // cout << "Case #" << testcase << ": ";
        solve();
    }
    return 0;
}
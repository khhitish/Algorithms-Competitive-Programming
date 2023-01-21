#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;
#define nl "\n"
#define dbg(x) cout << #x << " = " << x << nl

bool dfs(ll node, vector<ll>& vis, vector<ll>& currvis, vector<vector<ll>>& adj)
{
    vis[node] = 1;
    currvis[node] = 1;
    for(auto&x : adj[node])
    {
        if(!vis[x])
        {
            if(dfs(x,vis,currvis,adj) == true) return true;
        }
        else if(currvis[x] == 1) return true;
    }
    currvis[node] = 0;
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
    }
    vector<ll> vis(n,0), currvis(n,0);
    for(ll i=0;i<n;i++)
    {
        if(!vis[i])
        {
            if(dfs(i,vis,currvis,adj) == true)
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
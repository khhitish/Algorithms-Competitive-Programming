#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;
#define nl "\n"
#define dbg(x) cout << #x << " = " << x << nl

void BFS(ll node, vector<ll>& bfs, vector<ll>& vis, vector<vector<ll>>& adj)
{
    queue<ll> q;
    q.push(node);
    vis[node] = 1;
    while(!q.empty())
    {
        ll curr = q.front();
        q.pop();
        bfs.push_back(curr);
        for(auto&x : adj[node])
        {
            if(!vis[x])
            {
                vis[x] = 1;
                q.push(x);
            }
        }
    }
    
}

void DFS(ll node, vector<ll>& dfs, vector<ll>& vis, vector<vector<ll>>& adj)
{
    vis[node] = 1;
    dfs.push_back(node);
    for(auto&x : adj[node])
    {
        if(!vis[x])
        {
            DFS(x,dfs,vis,adj);
        }
    }
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
     vector<ll> vis(n);
     vector<ll> bfs;
     
     for(ll i=0;i<n;i++)
     {
        if(!vis[i])
        {
            BFS(i,bfs,vis,adj);
        }
     }
     for(auto&x : bfs)
     {
        cout<<x<<" ";
     }
     cout<<nl;
     
     vector<ll> dfs;
     for(ll i=0;i<n;i++)
     {
        if(!vis[i])
        {
            DFS(i,dfs,vis,adj);
        }
     }
     for(auto&x : dfs)
     {
        cout<<x<<" ";
     }
     cout<<nl;
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
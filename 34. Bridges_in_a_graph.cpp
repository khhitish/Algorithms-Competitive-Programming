#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;
#define nl "\n"
#define dbg(x) cout << #x << " = " << x << nl


// code for printing bridges in a graph given by adjacency list starts
void dfs(ll currnode, ll parent, ll &timer, vector<ll> &vis, vector<ll> &tin, vector<ll> &low, vector<vector<ll>> &ans, vector<vector<ll>> &graph)
{
    vis[currnode] = 1;
    tin[currnode] = low[currnode] = timer++;
    for (auto &adjnode : graph[currnode])
    {
        if (!vis[adjnode])
        {
            dfs(adjnode, currnode, timer, vis, tin, low, ans, graph);
            if (low[adjnode] > tin[currnode])
            {
                ans.push_back({currnode, adjnode});
            }
            low[currnode] = min(low[currnode], low[adjnode]);
        }
        else if (adjnode != parent)
        {
            low[currnode] = min(low[currnode], tin[adjnode]);
        }
    }
}
vector<vector<ll>> get_bridges(vector<vector<ll>> &adj)
{
    ll n = adj.size();
    vector<ll> vis(n, 0);
    vector<ll> tin(n, -1);
    vector<ll> low(n, -1);
    vector<vector<ll>> ans;
    ll timer = 0;
    for (ll i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, -1, timer, vis, tin, low, ans, adj);
        }
    }
    return ans;
}
// code for printing bridges in a graph given by adjacency list ends

void solve()
{
    ll n,m;
    cin>>n>>m;
    // n nodes, m edges, 0 based indexing;
    vector<vector<ll>> adj(n);
    for(ll i=0;i<m;i++)
    {
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<ll>> ans = get_bridges(adj);
    for(auto&x : ans)
    {
        cout<<x[0]<<" "<<x[1]<<nl;
    }
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
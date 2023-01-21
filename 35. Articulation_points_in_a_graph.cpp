#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;
#define nl "\n"
#define dbg(x) cout << #x << " = " << x << nl


// code for printing articulation points in a graph given by adjacency list starts
void dfs(ll curr, ll par, ll &timer, vector<ll> &disc, vector<ll> &low,
         vector<ll> &vis, vector<bool> &ans, vector<vector<ll>>& adj)
{
    vis[curr] = 1;
    disc[curr] = low[curr] = timer++;
    ll countcalls = 0;
    for (auto &x : adj[curr])
    {
        if (x == par)
            continue;
        if (!vis[x])
        {
            dfs(x, curr, timer, disc, low, vis, ans, adj);
            low[curr] = min(low[curr], low[x]);
            if (low[x] >= disc[curr] && par != -1)
            {
                ans[curr] = true;
            }
            countcalls++;
        }
        else
        {
            low[curr] = min(low[curr], disc[x]);
        }
    }
    if (countcalls > 1 && par == -1)
    {
        ans[curr] = true;
    }
}
vector<ll> get_articulation_points(vector<vector<ll>>& adj)
{
    ll n = adj.size();
    vector<ll> disc(n, -1);
    vector<ll> low(n, -1);
    vector<ll> vis(n, 0);
    vector<bool> ans(n, false);
    ll timer = 0;
    for (ll i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, -1, timer, disc, low, vis, ans, adj);
        }
    }
    vector<ll> res;
    for (ll i = 0; i < n; i++)
    {
        if (ans[i] == true)
            res.push_back(i);
    }
    if (res.size() == 0)
        return {-1};
    return res;
}
// code for printing articulation points in a graph given by adjacency list ends

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
    vector<ll> ans = get_articulation_points(adj);
    for(auto&x : ans)
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
    cin >> testcases;
    for (ll testcase = 1; testcase <= testcases; testcase++)
    {
        // cout << "Case #" << testcase << ": ";
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;
#define nl "\n"
#define dbg(x) cout << #x << " = " << x << nl

void dfs(ll node, vector<ll>& vis, stack<ll>& st, vector<vector<ll>>& adj)
{
    vis[node] = 1;
    for(auto&x : adj[node])
    {
        if(!vis[x])
        {
            dfs(x,vis,st,adj);
        }
    }
    st.push(node);
}

void solve()
{
    // only for directed acyclic graph with single component
    ll n, m; // n nodes, m edges, 0 based indexing
    cin>>n>>m;
    vector<vector<ll>> adj(n);
    for(ll i=0;i<m;i++)
    {
        ll u, v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    stack<ll> st;
    vector<ll> vis(n);
    for(ll i=0;i<n;i++)
    {
        if(!vis[i]) dfs(i,vis,st,adj);
    }
    vector<ll> topo;
    while(!st.empty()){
        topo.push_back(st.top());
        st.pop();
    }
    for(auto&x : topo)cout<<x<<" ";
    
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
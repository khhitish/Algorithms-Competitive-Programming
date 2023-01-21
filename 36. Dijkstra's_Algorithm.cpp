#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;
#define nl "\n"
#define dbg(x) cout << #x << " = " << x << nl

// does not work on a graph that contains edges with negative weight
vector<ll> dijkstra(vector<vector<pair<ll,ll>>> adj, ll source)
{
    ll n = adj.size();
    vector<ll> dist(n, LLONG_MAX);
    dist[source] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, source});
    while (!pq.empty())
    {
        ll currdist = pq.top().first;
        ll currnode = pq.top().second;
        pq.pop();
        for (auto &nextnode : adj[currnode])
        {
            ll newdist = currdist + nextnode.second;
            if (newdist < dist[nextnode.first])
            {
                dist[nextnode.first] = newdist;
                pq.push({newdist, nextnode.first});
            }
        }
    }
    return dist;
}

void solve()
{
    ll n,m;
    cin>>n>>m;
    // n nodes, m edges, 0 based indexing;
    vector<vector<pair<ll,ll>>> adj(n);
    for(ll i=0;i<m;i++)
    {
        ll u,v,w;
        cin>>u>>v;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<ll> dist = dijkstra(adj,0);
    
    
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
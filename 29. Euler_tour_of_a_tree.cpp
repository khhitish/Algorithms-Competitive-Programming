#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;
#define nl "\n"
#define dbg(x) cout << #x << " = " << x << nl

void getEuler(ll curr, ll prev, vector<vector<ll>> &adj, ll &timer, vector<ll> &euler, vector<pair<ll, ll>> &index)
{
    euler.push_back(curr);
    index[curr].first = euler.size() - 1;
    timer++;
    for (auto &x : adj[curr])
    {
        if (x != prev)
        {
            getEuler(x, curr, adj, timer, euler, index);
            euler.push_back(curr);
        }
    }
    index[curr].second = euler.size() - 1;
}

void solve()
{
    ll n;
    cin >> n;
    vector<vector<ll>> adj(n);
    // 0 based indexing for nodes and taking edges as input
    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<ll> euler;              // euler tour
    vector<pair<ll, ll>> index(n); // starting and ending index of every node in the euler tour array
    ll timer = 0;
    
    getEuler(0,-1,adj,timer,euler,index);
    
    
    for (auto &x : euler)
        cout << x << " ";
    cout << nl;
    for (ll i = 0; i < n; i++)
    {
        cout << index[i].first << " " << index[i].second << nl;
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
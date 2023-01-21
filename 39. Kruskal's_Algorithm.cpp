#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;
#define nl "\n"
#define dbg(x) cout << #x << " = " << x << nl

class DSU {
    private:
        vector<ll> par,rank,size;
    public:
        DSU(ll n)
        {
            par.resize(n);
            rank.resize(n,0);
            size.resize(n,1);
            for(ll i=0;i<n;i++)
            {
                par[i] = i;
            }
        }
        ll findparent(ll n)
        {
            if (n == par[n])
                return n;
            return par[n] = findparent(par[n]);
        }
        void unionbyrank(ll a, ll b)
        {
            a = findparent(a);
            b = findparent(b);
            if (a != b) {
                if (rank[a] < rank[b])
                    swap(a, b);
                par[b] = a;
                if (rank[a] == rank[b])
                    rank[a]++;
            }
        }
        void unionbysize(ll a, ll b)
        {
            a = findparent(a);
            b = findparent(b);
            if (a != b) {
                if (size[a] < size[b])
                    swap(a, b);
                par[b] = a;
                size[a] += size[b];
            }
        }
    
};

void solve()
{
    // to find the minimum spanning tree of a given graph using DSU
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> edges(m);
    for(ll i=0;i<m;i++)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        edges[i] = {w,u,v};
    }
    sort(edges.begin(), edges.end());
    ll sum = 0;
    vector<vector<pair<ll,ll>>> mst(n);
    DSU ds(n);
    for(auto&x : edges)
    {
        ll u = x[1], v = x[2], w = x[0];
        if(ds.findparent(u)!=ds.findparent(v))
        {
            ds.unionbyrank(u,v);
            sum+=w;
            mst[u].push_back({v,w});
            mst[v].push_back({u,w});
        } 
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
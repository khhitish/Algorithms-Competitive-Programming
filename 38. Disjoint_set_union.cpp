#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;
#define nl "\n"
#define dbg(x) cout << #x << " = " << x << nl

// 0 based indexing DSU
// if nodes are in 1 based indexing create dsu with n = n+1
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
    ll n;
    cin>>n;
    DSU ds(n);
    ll m;
    cin>>m;
    for(ll i=0;i<m;i++)
    {
        ll a,b;
        cin>>a>>b;
        ds.unionbyrank(a,b);
    }
    for(ll i=0;i<n;i++)
    {
        cout<<ds.findparent(i)<<nl;;
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
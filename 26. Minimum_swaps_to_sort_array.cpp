#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;
#define nl "\n"
#define dbg(x) cout << #x << " = " << x << nl

ll minSwaps(vector<ll>& v)
{
    ll n=v.size();
    vector<pair<ll,ll>> vs(n);
    for(ll i=0;i<n;i++)
    {
        vs[i] = {v[i],i};
    }
    sort(vs.begin(), vs.end());
    vector<ll> adj(n);
    for(ll i=0;i<n;i++)
    {
        ll ogi = vs[i].second;
        ll sortedi = i;
        adj[ogi]=sortedi;
    }
    ll c = 0;
    vector<ll> comp(n);
    vector<ll> vis(n);
    for(ll i=0;i<n;i++)
    {
        if(!vis[i])
        {
            c++;
            ll curr = i;
            vis[curr] = 1;
            comp[curr] = c;
            while(vis[adj[curr]] == 0)
            {
                curr = adj[curr];
                vis[curr] = 1;
                comp[curr] = c;
            }
            
        }
    }
    // every component will form a cycle and to put the members of the component we need cycle length -1 steps. So for every cycle len-1. Final ans = len1 - 1 + len2 - 1 ..... == n - c
    return n-c;
}

void solve()
{
    ll n;cin>>n;
    vector<ll> v(n);
    for(auto&x : v)cin>>x;
    cout<<minSwaps(v)<<nl;
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
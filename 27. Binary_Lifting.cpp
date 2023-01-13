#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;
#define nl "\n"
#define dbg(x) cout << #x << " = " << x << nl


// we want to calculate the 1st, 2nd, 4th, 8th, 16th... parent of every node in the given tree
// since number of nodes is generally 2*10^5, calculating upto 2^17  th parent will suffice

void dfs(ll curr, ll prev, vector<vector<ll>>& adj, vector<vector<ll>>& parent)
{
    parent[curr][0] = prev;
    for(ll i=1;i<18;i++)
    {
        ll temp = parent[curr][i-1];
        if(temp == -1) break;
        temp = parent[temp][i-1];
        if(temp == -1) break;
        parent[curr][i] = temp;
        // 2^(i-1)th parent of 2^(i-1)th parent of curr node is the ith parent of current node. If any of them dont exist break the loop since no higher parents will be present
        // since we are doing dfs, all the parents of the current node would have been already calculated/visited 
    }
    for(auto&x : adj[curr])
    {
        if(x!=prev)
        {
            dfs(x,curr,adj,parent);
        }
    }
}
void solve()
{
    ll n;
    cin>>n;
    // edge list as input and 0 based indexing for nodes
    vector<vector<ll>> adj(n);
    for(ll i=0;i<n-1;i++)
    {
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<ll>> parent(n, vector<ll> (18,-1));
    dfs(0,-1,adj,parent);
    for(auto&x : parent)
    {
        for(auto&y : x)
        {
            cout<<y<<" ";
        }
        cout<<nl;
    }
    
    // // if we want to find the kth ancestor after precomputing the binary lifting array in logk time
    // ll node,k;
    // cin>>node>>k;
    // if(log2(k)>=18) // not possible to have that many parents with given constraints
    // {
    //     cout<<-1<<nl;
    //     return;
    // }
    // ll cnt = 0;
    // while(k>0 && node!=-1)
    // {
    //     if(k&1)
    //     {
    //         node = parent[node][cnt];
    //     }
    //     k>>=1;
    //     cnt++;
    // }
    // cout<<node<<nl;
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
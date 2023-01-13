#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;
#define nl "\n"
#define dbg(x) cout << #x << " = " << x << nl

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto &x : v)
        cin >> n;
    ll num = (1 << n);
    vector<vector<ll>> ans;
    for (ll i = 0; i < num; i++)
    {
        vector<ll> temp;
        for (ll j = 0; j < n; j++)
        {
            if ((i & (1 << j)) != 0)
            {
                temp.push_back(v[j]);
            }
        }
        ans.push_back(temp);
    }
    // ans contains all possible subsequences of the given vector
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
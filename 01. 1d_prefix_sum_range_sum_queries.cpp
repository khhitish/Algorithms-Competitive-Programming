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
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<ll> pref(n);
    for (ll i = 0; i < n; i++)
    {
        pref[i] = v[i];
        if (i - 1 >= 0)
        {
            pref[i] += pref[i - 1];
        }
    }
    ll queries;
    cin >> queries;
    for (ll i = 0; i < queries; i++)
    {
        ll l, r;
        cin >> l >> r;
        ll ans = pref[r];
        if (l - 1 >= 0)
        {
            ans -= pref[l - 1];
        }
        cout << ans << nl;
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
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
    vector<ll> add(n + 1, 0);
    ll queries;
    cin >> queries;
    for (ll i = 0; i < queries; i++)
    {
        ll l, r, x;
        cin >> l >> r >> x;
        add[l] += x;
        add[r + 1] -= x;
    }

    ll carry = 0;
    for (ll i = 0; i < n; i++)
    {
        carry += add[i];
        cout << v[i] + carry << " ";
    }
    cout << nl;
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
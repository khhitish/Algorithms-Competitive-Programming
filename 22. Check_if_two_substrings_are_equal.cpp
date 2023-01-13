#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;
#define nl "\n"
#define dbg(x) cout << #x << " = " << x << nl

ll modpow(ll base, ll power, ll modulo)
{
    ll ans = 1;
    while (power != 0)
    {
        if (power % 2 == 1)
        {
            ans = (ans * base) % modulo;
            power--;
        }
        else
        {
            base = (base * base) % modulo;
            power /= 2;
        }
    }
    return ans;
}

void solve()
{
    string s;
    cin >> s;
    ll n = s.size();
    ll hash = 0, power = 1;
    vector<ll> prefhash(n);
    for (ll i = 0; i < n; i++)
    {
        hash = (hash + ((s[i] - 'a' + 1) * power) % mod) % mod;
        power = (power * 31) % mod;
        prefhash[i] = hash;
    }
    ll q;
    cin >> q;
    while (q--)
    {
        ll i1, j1, i2, j2;
        cin >> i1 >> j1 >> i2 >> j2;
        ll t;
        ll x = modpow(31, i1, mod);
        if (i1 > 0)
        {
            t = prefhash[i1 - 1];
        }
        else
            t = 0;
        ll p1 = ((prefhash[j1] - t + mod) % mod * modpow(x, mod - 2, mod)) % mod;
        x = modpow(31, i2, mod);
        if (i2 > 0)
        {
            t = prefhash[i2 - 1];
        }
        else
            t = 0;
        ll p2 = ((prefhash[j2] - t + mod) % mod * modpow(x, mod - 2, mod)) % mod;
        if (p1 == p2)
        {
            cout << "SAME" << nl;
        }
        else
        {
            cout << "DIFF" << nl;
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
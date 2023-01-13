#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;
#define nl "\n"
#define dbg(x) cout << #x << " = " << x << nl

vector<ll> fact(1e5 + 1), power(1e5 + 1);

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
    ll n, r;
    cin >> n >> r;
    // ll x = modpow(fact[r], mod - 2, mod);
    // ll y = modpow(fact[n - r], mod - 2, mod);
    // ll ans = (fact[n] * (x * y) % mod) % mod;

    ll ans = (fact[n] * (power[r] * power[n - r]) % mod) % mod;
    cout << ans << nl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll testcases = 1;
    // cin >> testcases;
    fact[0] = 1;
    power[0] = 1;
    for (ll i = 1; i <= 1e5; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
        power[i] = modpow(fact[i], mod - 2, mod); // precomputing power so that nCr is O(1)
    }
    for (ll testcase = 1; testcase <= testcases; testcase++)
    {
        // cout << "Case #" << testcase << ": ";
        solve();
    }
    return 0;
}
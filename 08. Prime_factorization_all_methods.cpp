#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;
#define nl "\n"
#define dbg(x) cout << #x << " = " << x << nl

vector<ll> spf(1e6 + 1);

void solve()
{
    ll n;
    cin >> n;

    // Worst case TC: O(n)
    for (ll i = 2; i <= n; i++)
    {
        while (n % i == 0)
        {
            cout << i << " ";
            n /= i;
        }
    }

    // Worst case TC: O(sqrt(n))
    for (ll i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            cout << i << " ";
            n /= i;
        }
    }
    if (n > 1)
        cout << n << " ";

    // Worst case TC: O(log2(n))
    // Precompute smallest prime facotrs using sieve, TC: O(nlog(log(n)))
    while (n > 1)
    {
        cout << spf[n] << " ";
        n /= spf[n];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll testcases = 1;
    // cin >> testcases;
    for (ll i = 2; i <= 1e6; i++)
    {
        spf[i] = i; // marking such that we can identify if this has already been marked by a smaller prime factor or not. Also works since spf[prime] = the number itself
    }
    for (ll i = 2; i * i <= 1e6; i++)
    {
        for (ll j = i * i; j <= 1e6; j += i)
        {
            if (spf[j] == j) // we visisted this j means not prime hence should not have spf[j] = j
            {
                spf[j] = i;
            }
        }
    }
    for (ll testcase = 1; testcase <= testcases; testcase++)
    {
        // cout << "Case #" << testcase << ": ";
        solve();
    }
    return 0;
}
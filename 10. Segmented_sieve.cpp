#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;
#define nl "\n"
#define dbg(x) cout << #x << " = " << x << nl

vector<bool> sieve(1e6 + 1, true);

void solve()
{
    ll l, r;
    cin >> l >> r;
    vector<ll> primes;
    for (ll i = 2; i * i <= r; i++)
    {
        if (sieve[i] == true)
            primes.push_back(i);
    }
    vector<bool> isPrime(r - l + 1, true);
    for (auto &x : primes)
    {
        ll firstmultiple;
        if (l % x == 0)
            firstmultiple = l;
        else
            firstmultiple = l + (x - l % x);

        for (ll i = max(firstmultiple, x * x); i <= r; i += x)
        {
            isPrime[i - l] = false;
        }
    }
    for (ll i = 0; i < isPrime.size(); i++)
    {
        if (isPrime[i] == true)
        {
            cout << i + l << " ";
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

    // creating sieve
    sieve[0] = false;
    sieve[1] = false;
    for (ll i = 2; i * i <= 1e6; i++)
    {
        if (sieve[i] == true)
        {
            for (ll j = i * i; j <= 1e6; j += i)
            {
                sieve[j] = false;
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
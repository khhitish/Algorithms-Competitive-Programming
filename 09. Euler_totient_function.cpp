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
    // first perform prime factorization by any method then just apply theorems or formulae
    map<ll, ll> mp;
    while (n > 1)
    {
        mp[spf[n]]++;
        n /= spf[n];
    }

    // using theorem and multiplication property
    ll ans = 1;
    for (auto &it : mp)
    {
        ans = ans * (pow(it.first, it.second) - pow(it.first, it.second - 1));
    }

    // using formula (n * mult(1 - 1/p)): dont need the frequency of prime factors
    ll ans = n;
    ll den = 1;
    for (auto &it : mp)
    {
        ans = ans * (it.first - 1);
        den *= it.first;
    }
    ans = ans / den;
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
            if (spf[j] == j) // we visited this j means not prime hence should not have spf[j] = j
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
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
    vector<bool> v(n + 1, true);
    v[0] = false;
    v[1] = false;
    for (ll i = 2; i * i <= n; i++)
    {
        if (v[i] == true)
        {
            for (ll j = i * i; j <= n; j += i)
            {
                v[j] = false;
            }
        }
    }
    // all index values which are true are prime numbers
    for (ll i = 0; i <= n; i++)
    {
        if (v[i] == true)
        {
            cout << i << " ";
        }
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
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;
#define nl "\n"
#define dbg(x) cout << #x << " = " << x << nl

void solve()
{
    string s;
    cin >> s;
    ll hash = 0;
    ll power = 1;
    for (ll i = 0; i < s.size(); i++)
    {
        hash = (hash + ((s[i] - 'a' + 1) * power) % mod) % mod;
        power = (power * 31) % mod;
    }
    cout << hash << nl;
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
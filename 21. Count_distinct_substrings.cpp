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
    set<ll> st;
    for (ll i = 0; i < s.size(); i++)
    {
        ll hash = 0;
        ll power = 1;
        for (ll j = i; j < s.size(); j++)
        {
            char c = s[j];
            hash = (hash + ((c - 'a' + 1) * power) % mod) % mod;
            power = (power * 31) % mod;
            st.insert(hash);
        }
    }
    cout << st.size() << nl;
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
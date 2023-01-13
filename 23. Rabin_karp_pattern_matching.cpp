#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;
#define nl "\n"
#define dbg(x) cout << #x << " = " << x << nl

ll computeHash(string s)
{
    ll hash = 0, power = 1, n = s.size();
    for (ll i = 0; i < n; i++)
    {
        hash = (hash + ((s[i] - 'a' + 1) * power) % mod) % mod;
        power = (power * 31) % mod;
    }
    return hash;
}

void solve()
{
    string s, pattern;
    cin >> s >> pattern;
    ll pathash = computeHash(pattern);
    ll m = pattern.size(), n = s.size();
    ll currhash = 0, power = 1;
    for (ll i = 0; i < m; i++)
    {
        currhash = (currhash + ((s[i] - 'a' + 1) * power) % mod) % mod;
        power = (power * 31) % mod;
    }
    vector<ll> ans;
    if (currhash == pathash)
    {
        ans.push_back(0);
    }
    ll left = 0, right = m, lpower = 1;
    // current substring under consideration is from left to right-1 inclusive
    // then we slide our window
    while (right < n)
    {
        currhash = (currhash + ((s[right] - 'a' + 1) * power) % mod) % mod;
        currhash = (currhash - ((s[left] - 'a' + 1) * lpower) % mod + mod) % mod;
        lpower = (lpower * 31) % mod;
        power = (power * 31) % mod;
        pathash = (pathash * 31) % mod;
        left++;
        right++;
        if (pathash == currhash)
        {
            ans.push_back(left);
        }
    }
    for (auto &x : ans)
    {
        cout << x << " ";
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
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;
#define nl "\n"
#define dbg(x) cout << #x << " = " << x << nl

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    ll ans = LLONG_MIN;
    ll sum = 0;
    ll left = 0, right = 0;
    while (right < k)
    {
        sum += v[right];
        right++;
    }
    // sum is in the range [left,right)
    ans = max(ans, sum);
    while (right < n)
    {
        sum += v[right];
        sum -= v[left];
        left++;
        right++;
        ans = max(ans, sum);
    }
    cout << ans << nl;
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
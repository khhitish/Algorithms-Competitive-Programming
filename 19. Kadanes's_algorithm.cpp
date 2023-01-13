#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;
#define nl "\n"
#define dbg(x) cout << #x << " = " << x << nl

void solve()
{
    // max subarray sum with start and end indices
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto &x : v)
    {
        cin >> x;
    }
    ll sum = 0, maxi = v[0], start = 0, end = 0, tempstart;
    for (ll i = 0; i < n; i++)
    {
        if (sum == 0)
        {
            tempstart = i;
        }
        sum += v[i];
        if (sum > maxi)
        {
            maxi = sum;
            start = tempstart;
            end = i;
        }
        if (sum < 0)
            sum = 0;
    }
    cout << maxi << nl;
    cout << start << " " << end << nl;
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
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;
#define nl "\n"
#define dbg(x) cout << #x << " = " << x << nl

void solve()
{
    // count subsets with given sum

    ll n, reqsum;
    cin >> n >> reqsum;
    vector<ll> arr(n);
    for (auto &x : arr)
        cin >> x;

    vector<ll> arr1, arr2;
    for (ll i = 0; i < n / 2; i++)
    {
        arr1.push_back(arr[i]);
    }
    for (ll i = n / 2; i < n; i++)
    {
        arr2.push_back(arr[i]);
    }
    ll n1 = arr1.size(), n2 = arr2.size();

    vector<ll> sum1;
    vector<ll> sum2;

    ll m1 = (1 << n1);
    for (ll i = 0; i < m1; i++)
    {
        ll sum = 0;
        for (ll j = 0; j < n1; j++)
        {
            if (((1 << j) & i) != 0)
            {
                sum += arr1[j];
            }
        }
        sum1.push_back(sum);
    }

    ll m2 = (1 << n2);
    for (ll i = 0; i < m2; i++)
    {
        ll sum = 0;
        for (ll j = 0; j < n2; j++)
        {
            if (((1 << j) & i) != 0)
            {
                sum += arr2[j];
            }
        }
        sum2.push_back(sum);
    }
    sort(sum2.begin(), sum2.end());
    ll count = 0;
    for (ll i = 0; i < sum1.size(); i++)
    {
        ll ind = upper_bound(sum2.begin(), sum2.end(), reqsum - sum1[i]) - sum2.begin();
        count += ind;
    }
    cout << count << nl; // includes null subset
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
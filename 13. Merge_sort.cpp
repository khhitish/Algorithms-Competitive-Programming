#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;
#define nl "\n"
#define dbg(x) cout << #x << " = " << x << nl

void merge(ll low, ll mid, ll high, vector<ll> &arr)
{
    ll left = low, right = mid + 1;
    vector<ll> temp;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left++]);
        }
        else
        {
            temp.push_back(arr[right++]);
        }
    }
    while (left <= mid)
    {
        temp.push_back(arr[left++]);
    }
    while (right <= high)
    {
        temp.push_back(arr[right++]);
    }
    for (ll i = 0; i < temp.size(); i++)
    {
        arr[low + i] = temp[i];
    }
}

void mergesort(ll low, ll high, vector<ll> &arr)
{
    if (low == high)
        return;
    ll mid = low + (high - low) / 2;
    mergesort(low, mid, arr);
    mergesort(mid + 1, high, arr);
    merge(low, mid, high, arr);
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (auto &x : arr)
        cin >> x;
    mergesort(0, n - 1, arr);
    for (auto &x : arr)
        cout << x << " ";
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
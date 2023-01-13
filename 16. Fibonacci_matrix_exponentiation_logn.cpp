#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;
#define nl "\n"
#define dbg(x) cout << #x << " = " << x << nl

ll fib_logn(ll n)
{
    vector<vector<ll>> mat = {{1, 1}, {1, 0}}; // we need mat^(n-1)
    vector<vector<ll>> ans = {{1, 0}, {0, 1}};
    ll power = n - 1;
    while (power > 0)
    {
        if (power % 2 == 1)
        {
            vector<vector<ll>> temp(2, vector<ll>(2)); // ans = ans * mat, power--
            for (ll i = 0; i < 2; i++)
            {
                for (ll j = 0; j < 2; j++)
                {
                    for (ll k = 0; k < 2; k++)
                    {
                        temp[i][j] += ans[i][k] * mat[k][j];
                    }
                }
            }
            power--;
            ans = temp;
        }
        else
        {
            power /= 2;
            vector<vector<ll>> temp(2, vector<ll>(2)); // mat = mat*mat, power/=2;
            for (ll i = 0; i < 2; i++)
            {
                for (ll j = 0; j < 2; j++)
                {
                    for (ll k = 0; k < 2; k++)
                    {
                        temp[i][j] += mat[i][k] * mat[k][j];
                    }
                }
            }
            mat = temp;
        }
    }
    return ans[0][0];
}

void solve()
{
    ll n;
    cin >> n;
    if (n == 0)
    {
        cout << 0 << nl;
        return;
    }
    cout << fib_logn(n) << nl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll testcases = 1;
    cin >> testcases;
    for (ll testcase = 1; testcase <= testcases; testcase++)
    {
        // cout << "Case #" << testcase << ": ";
        solve();
    }
    return 0;
}
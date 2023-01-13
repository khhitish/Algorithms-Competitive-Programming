#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;
#define nl "\n"
#define dbg(x) cout << #x << " = " << x << nl

vector<vector<ll>> mat_expo(vector<vector<ll>> &mat, ll power)
{
    ll n = mat.size();
    vector<vector<ll>> ans(n, vector<ll>(n));
    for (ll i = 0; i < n; i++) // setting identity matrix
        ans[i][i] = 1;

    while (power > 0)
    {
        if (power % 2 == 1)
        {
            vector<vector<ll>> temp(n, vector<ll>(n)); // ans = ans * mat, power--
            for (ll i = 0; i < n; i++)
            {
                for (ll j = 0; j < n; j++)
                {
                    for (ll k = 0; k < n; k++)
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
            vector<vector<ll>> temp(n, vector<ll>(n)); // mat = mat*mat, power/=2;
            for (ll i = 0; i < n; i++)
            {
                for (ll j = 0; j < n; j++)
                {
                    for (ll k = 0; k < n; k++)
                    {
                        temp[i][j] += mat[i][k] * mat[k][j];
                    }
                }
            }
            mat = temp;
        }
    }
    return ans;
}

void solve()
{
    ll power;
    cin >> power;
    ll sz;
    cin >> sz; // only square matrix can have powers sz*sz matrix
    vector<vector<ll>> mat(sz, vector<ll>(sz));
    for (auto &x : mat)
    {
        for (auto &y : x)
        {
            cin >> y;
        }
    }
    vector<vector<ll>> ans = mat_expo(mat, power);
    for (auto &x : ans)
    {
        for (auto &y : x)
        {
            cout << y << " ";
        }
        cout << nl;
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
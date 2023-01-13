#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;
#define nl "\n"
#define dbg(x) cout << #x << " = " << x << nl

void solve()
{
    ll m, n;
    cin >> m >> n;
    vector<vector<ll>> v(m, vector<ll>(n));
    for (ll i = 0; i < m; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }
    vector<vector<ll>> pref(m, vector<ll>(n));
    for (ll i = 0; i < m; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            pref[i][j] = v[i][j];
            if (i - 1 >= 0)
                pref[i][j] += pref[i - 1][j];
            if (j - 1 >= 0)
                pref[i][j] += pref[i][j - 1];
            if (i - 1 >= 0 && j - 1 >= 0)
                pref[i][j] -= pref[i - 1][j - 1];
        }
    }

    ll queries;
    cin >> queries;
    for (ll i = 0; i < queries; i++)
    {
        ll si, sj, ei, ej; // start i, start j, end i, end j
        cin >> si >> sj >> ei >> ej;
        ll ans = pref[ei][ej];
        if (si - 1 >= 0)
            ans -= pref[si - 1][ej];
        if (sj - 1 >= 0)
            ans -= pref[ei][sj - 1];
        if (si - 1 >= 0 && sj - 1 >= 0)
            ans += pref[si - 1][sj - 1];

        cout << ans << nl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll testcases = 1;
    // cin >> testcases;
    for (int it = 1; it <= testcases; it++)
    {
        // cout << "Case #" << it << ": ";
        solve();
    }
    return 0;
}
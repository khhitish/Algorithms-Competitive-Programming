#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;
#define nl "\n"
#define dbg(x) cout << #x << " = " << x << nl

vector<ll> z_func(string& s)
{
    ll n = s.size();
    vector<ll> z(n);
    for(ll i=0,l=0,r=0;i<n;i++)
    {
        if(i<=r)
        {
            z[i] = min(r-i+1,z[i-l]);
        }
        while(i+z[i] < n && s[z[i]] == s[i+z[i]]){
            z[i]++;
        }
        if(i + z[i] - 1 > r)
        {
            l = i;
            r = i+ z[i] -1;
        }
    }
    return z;
}

void solve()
{
    string s, pat;
    cin>>s>>pat;
    string temp;
    temp+=pat;
    temp+='#';
    temp+=s;
    vector<ll> z = z_func(temp);
    vector<ll> ans;
    ll n = pat.size();
    for(ll i=0;i<z.size();i++)
    {
        if(z[i] == n)
        {
            ans.push_back(i-n-1);
        }
    }
    for(auto&x : ans)
    {
        cout<<x<<" ";
    }
    cout<<nl;
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
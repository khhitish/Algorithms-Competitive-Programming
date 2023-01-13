#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;
#define nl "\n"
#define dbg(x) cout << #x << " = " << x << nl

vector<ll> pref_func(string& s)
{
    ll n = s.size();
    vector<ll> lps(n,0);
    for(ll i=1;i<n;i++)
    {
        ll j = i;
        while(j>0)
        {
            j = lps[j-1];
            if(s[i] == s[j])
            {
                lps[i] = j+1;
                break;
            } 
        }
    }
    return lps;
}

void solve()
{
    string s, pat;
    cin>>s>>pat;
    string temp;
    temp+=pat;
    temp+='#';
    temp+=s;
    vector<ll> lps = pref_func(temp);
    ll n = pat.size();
    vector<ll> ans;
    for(ll i=0;i<lps.size();i++)
    {
        if(lps[i] == n)
        {
            ans.push_back(i-2*n);
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
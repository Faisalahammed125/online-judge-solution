//BISMILLAHIR RAHMANIR RAHEEM
#include<bits/stdc++.h>
#define  MX           100005
#define  ff           first
#define  ss           second
#define  pb           push_back
#define  int          long long
#define  endl         "\n"
#define  PII          pair<int,int>
#define  all(v)       v.begin(),v.end()
#define  pi           acos(-1)
#define  mod          1000000007
#define  rep(i,a,b)   for(int i = a; i <= b; i++)
#define  irep(i,b,a)  for(int i = b; i >= a; i--)
using namespace std;
const int N = 5e5 + 5;

int power(int x, int k) {
    int res = 1;
    while (k) {
        if (k & 1)res = (res * x) % mod;
        x = (x * x) % mod;
        k >>= 1;
    }
    return res % mod;
}
int geo_sum(int x, int k) {
    int nr = (power(x, k + 1) - 1 + mod) % mod;
    int dr = power(x - 1, mod - 2);
    return (nr * dr) % mod;
}
void solve(int t) {
    int npd; cin >> npd;
    vector<int>prime, exp;
    int n = 1, ndiv = 1, pdiv = 1, sdiv = 1, nd = 1;
    bool odd = false;
    while (npd--) {
        int pd, f; cin >> pd >> f;
        prime.pb(pd); exp.pb(f);
        if (!odd && (f & 1)) {
            odd = true;
            nd = (nd * (f + 1) / 2) % (mod - 1);
        }
        else nd = (nd * (f + 1)) % (mod - 1);
        ndiv = (ndiv * (f + 1)) % mod;
        sdiv = (sdiv * geo_sum(pd, f)) % mod;
        n *= power(pd, f) % mod;
    }
    if (odd) {
        for (int i = 0; i < prime.size(); i++) {
            pdiv = (pdiv * power(prime[i], (exp[i] * nd) % (mod - 1))) % mod;
        }
    }
    else {
        for (int i = 0; i < prime.size(); i++) {
            pdiv = (pdiv * power(prime[i], ((exp[i] / 2) * nd) % (mod - 1))) % mod;
        }
    }
    cout << ndiv << " " << sdiv << " " << pdiv << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin>>T;
    for (int t = 1; t <= T; t++) {
        solve(t);
    }

    return 0;
}
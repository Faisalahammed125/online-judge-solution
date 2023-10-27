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
const int N = 1e5 + 5;
const int inf = 1e17 + 7;

vector<PII>adj[N], rev[N];
int dis[N];

void _init(int n) {
   rep(i, 1, n)dis[i] = inf;
}

void dijstra(int src) {
   set<PII>st;
   st.insert({0, src});
   dis[src] = 0;
   while (!st.empty()) {
      auto node = *st.begin();
      st.erase(node);
      int x = node.ss;
      for (auto it : adj[x]) {
         int y = it.ff;
         int wt = it.ss;
         if (dis[y] > dis[x] + wt) {
            st.erase({dis[y], y});
            dis[y] = dis[x] + wt;
            st.insert({dis[y], y});
         }
      }
   }
}

void solve(int t) {
   int n, m; cin >> n >> m;
   _init(n);
   map<PII, int>edge;
   while (m--) {
      int x, y, p; cin >> x >> y >> p;
      adj[x].pb({y, p});
      rev[y].pb({x, p});
      edge[ {x, y}] = p;
   }
   dijstra(1);
   vector<int>from1(n + 1);
   for (int i = 1; i <= n; i++) {
      from1[i] = dis[i];
      adj[i].clear();
      adj[i] = rev[i];
   }
   _init(n);
   dijstra(n);
   int ans = inf;
   for (auto it : edge) {
      int x = it.ff.ff; int y = it.ff.ss;
      int wt = it.ss;
      ans = min(ans, from1[x] + wt / 2 + dis[y]);
   }
   cout << ans << endl;
}

signed main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   int T = 1;
   // cin>>T;
   for (int t = 1; t <= T; t++) {
      solve(t);
   }

   return 0;
}


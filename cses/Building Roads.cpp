#include <bits/stdc++.h>
using namespace std;

vector<int>adj[100005];
bool vis[100005];
vector<pair<int,int>>res;

void dfs(int node){
	vis[node]=true;
	for(int child : adj[node]){
		if(!vis[child])dfs(child);
	}
}

int main() {
	int cities,roads;
	cin>>cities>>roads;
	while(roads--){
		int road1,road2;
		cin>>road1>>road2;
		adj[road1].push_back(road2);
		adj[road2].push_back(road1);
	}
	bool ok=false;
	for(int i=1;i<=cities;i++){
		if(!vis[i]){
			if(ok)res.push_back(make_pair(i-1,i));
			ok=true;
			dfs(i);
		}
	}
	cout<<res.size()<<endl;
	for(auto newroad : res)cout<<newroad.first<<" "<<newroad.second<<endl;
	return 0;
}

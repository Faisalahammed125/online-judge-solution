#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100];
int visited[100];
bool bfs(int s, int n)
{
    for(int i=0; i<n; i++)
        visited[i]=0;
    queue<int>q;
    q.push(s);
    visited[s]=1;
    while(!q.empty())
    {
        int u=q.front();
        int v;
        q.pop();
        for(int i=0; i<adj[u].size(); i++)
        {
            v=adj[u][i];
            if(visited[adj[u][i]]==0)
            {
                if(visited[u]==1)
                    visited[v]=2;
                else
                    visited[v]=1;
                q.push(v);
            }
            if(visited[u]==visited[v])
                return false;
        }
    }
    return true;
}
int main()
{
    int numNodes, numEdges;
    while(1)
    {
        scanf("%d", &numNodes);
        if(numNodes==0)return 0;
        scanf("%d", &numEdges);
    int x, y;
    scanf("%d%d", & x, & y);
    adj[x].push_back(y);
    adj[y].push_back(x);
    int s=x;
    for (int i = 2; i <= numEdges; i++)
    {
        int x, y;
        scanf("%d%d", & x, & y);
        adj[x].push_back(y);
        adj[y].push_back(x);

    }
    bool res=bfs(s,numNodes);
    if(res==true)
        cout<<"BICOLORABLE."<<endl;
    else
        cout<<"NOT BICOLORABLE."<<endl;
    }
}

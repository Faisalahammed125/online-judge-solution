#include <bits/stdc++.h>
using namespace std;

const int dx[] = {+1,-1,+0,+0};
const int dy[] = {+0,+0,+1,-1};

int row,col,sx,sy,tx,ty;
char input[1002][1002];
int vis[1002][1002];
int dis[1002][1002];
char path[1002][1002];

bool isvalid(int x,int y)
{
    if(x>=0&&x<row&&y>=0&&y<col&&!vis[x][y]&&(input[x][y]=='.'||input[x][y]=='B'))return true;
    else return false;
}

void bfs(){
	queue<pair<int,int>>q;
	q.push(make_pair(sx,sy));
	vis[sx][sy]=1;
	path[sx][sy]='$';
	while(!q.empty()){
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		//cout<<x<<" "<<y<<endl;
		for(int i=0;i<4;i++){
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(isvalid(xx,yy)){
				vis[xx][yy]=1;
				dis[xx][yy]=dis[x][y]+1;
				q.push(make_pair(xx,yy));
				if(i==0)path[xx][yy]='U';
				else if(i==1)path[xx][yy]='D';
				else if(i==2)path[xx][yy]='L';
				else if(i==3)path[xx][yy]='R';
			}
		}
	}
}

int main() {
	cin>>row>>col;
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cin>>input[i][j];
			if(input[i][j]=='A')sx=i,sy=j;
			if(input[i][j]=='B')tx=i,ty=j;
		}
	}
	bfs();
	if(!vis[tx][ty]){
		cout<<"NO"<<endl;
		return 0;
	}
	string ans;
	cout<<"YES"<<endl<<dis[tx][ty]<<endl;
	while(path[tx][ty]!='$'){
		//cout<<tx<<" "<<ty<<" "<<path[tx][ty]<<endl;
		if(path[tx][ty]=='D'){
			tx+=1;
			ans+='U';
		}
		else if(path[tx][ty]=='U'){
			tx-=1;
			ans+='D';
		}
		else if(path[tx][ty]=='L'){
			ty-=1;
			ans+='R';
		}
		else if(path[tx][ty]=='R'){
			ty+=1;
			ans+='L';
		}
	}
	reverse(ans.begin(),ans.end());
	cout<<ans<<endl;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,x,y,p,q,difx,dify;
    while(1)
    {
        cin>>t;
        if(t==0)return 0;
        cin>>x>>y;
        while(t--)
        {
          cin>>p>>q;
          difx=p-x;
          dify=q-y;
          if(difx==0||dify==0) cout<<"divisa"<<endl;
          else if(difx>0&&dify>0)cout<<"NE"<<endl;
          else if(difx<0&&dify<0)cout<<"SO"<<endl;
          else if(difx>0&&dify<0)cout<<"SE"<<endl;
          else if(difx<0&&dify>0)cout<<"NO"<<endl;
        }
    }
}

#include<bits/stdc++.h>
using namespace std;
#define ll   long long
#define pb   push_back
#define w(x) while(x--)
#define rep(i,a,b) for(int i=a:i<=b;i++)

int t;
string s;
int main()
{
    cin>>t;
    w(t)
    {
        int n,k;
        cin>>n>>k;
        cin>>s;
        int i=0,j=n-1;
        bool ok=true;
        for(;i<k;i++,j--){
            if(s[i]!=s[j]){
                ok=false;
                break;
            }
            if(i+1==k)break;
        }
        if(j-i<2&&k)ok=false;
        if(ok)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}

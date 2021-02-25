#include<bits/stdc++.h>
using namespace std;

#define minv(v) *min_element(v.begin(),v.end())
#define maxv(v) *max_element(v.begin(),v.end())
#define unq(v) sort(v.begin(),v.end()),v.erase(unique(v.begin(),v.end()),v.end())
#define ll long long
#define pb push_back
#define fill(arr) memset(arr,0,sizeof(arr))
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define _ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main()
{
    _ios;
    ll t,n,k;
    cin>>t;
    for(ll tt=1;tt<=t;tt++)
    {
        string s;
        cin>>n>>k;
        char ch='A';
        for(ll i=0;i<n;i++)
        {
            s+=ch;
            ch++;
        }
        ll cnt=0;
        cout<<"Case "<<tt<<":"<<endl;
        do
        {
            cout<<s<<endl;
            cnt++;
            if(cnt>=k)break;
        }while(next_permutation(s.begin(),s.end()));
    }
    return 0;
}


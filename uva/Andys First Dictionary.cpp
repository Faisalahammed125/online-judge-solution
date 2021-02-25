#include<bits/stdc++.h>
using namespace std;

#define   minv(v)    *min_element(v.begin(),v.end())
#define   maxv(v)    *max_element(v.begin(),v.end())
#define   unq(v)     sort(v.begin(),v.end()),v.erase(unique(v.begin(),v.end()),v.end())
#define   tt(x)      scanf("%d",&x);while(x--)
#define   rep(i,a,b) for(i=a;i<=b;i++)
#define   ll         long long
#define   pb         push_back
#define   fill(arr)  memset(arr,0,sizeof(arr))
#define   gcd(a,b)   __gcd(a,b)
#define   lcm(a,b)  (a*(b/gcd(a,b)))
#define   pi         acos(-1.00)
#define _ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    _ios;
    set<string>st;
    set<string>:: iterator it;
    char s[205];
    while(gets(s))
    {
        ll l=strlen(s);
        for(ll i=0; i<l; i++)
        {
            if(s[i]>='A'&&s[i]<='Z')
                s[i]=s[i]-'A'+'a';
            else if(s[i]<'a'||s[i]>'z')
                s[i]=' ';
        }
        string s1;
        istringstream is(s);
        while(is>>s1)
            st.insert(s1);
    }
    for( it=st.begin(); it!=st.end(); it++)
        cout<<*it<<endl;
    return 0;
}


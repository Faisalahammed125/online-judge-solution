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

vector<int>createTempArray(string pattern)
{
    vector<int>lps(pattern.length());
    int index=0;
    for(int i=1;i<pattern.length();)
    {
        if(pattern[index]==pattern[i])
        {
            lps[i]=index+1;
            index++;
            i++;
        }
        else
        {
            if(index)index=lps[index-1];
            else
            {
                lps[i]=index;
                i++;
            }
        }
    }
    return lps;
}
int kmp(string text,string pattern)
{
    vector<int>lps=createTempArray(pattern);
    int i=0,j=0;
    int cnt=0;
    while(i<text.length())
    {
        if(text[i]==pattern[j])
        {
            i++;
            j++;
        }
        else
        {
            if(j)j=lps[j-1];
            else i++;
        }
        if(j==pattern.length())
        {
            cnt++;
            j=lps[j-1];
        }
    }
    return cnt;
}
int main()
{
    _ios;
    string s,s1;
    ll t,i;
    cin>>t;
    rep(i,1,t)
    {
        cin>>s;
        cin>>s1;
        int ans=kmp(s,s1);
        cout<<"Case "<<i<<": "<<ans<<endl;
    }
    return 0;
}


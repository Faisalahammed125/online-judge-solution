//KMP ALGORITHM
//Pattern Matching (Substring search)
#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int>createTempArray(string pattern)
{
    vector<int>lps(pattern.length());
    int index=0;
    for(int i=1; i<pattern.length();)
    {
        if(pattern[index]==pattern[i])
        {
            lps[i]=index+1;
            index++;
            i++;
        }
        else
        {
            if(index)
                index=lps[index-1];
            else
            {
                lps[i]=index;
                i++;
            }
        }
    }
    return lps;
}
void kmp(string text,string pattern)
{
    vector<int>lps=createTempArray(pattern);
    int i=0,j=0;
    bool found =false;
    while(i<text.length())
    {
        if(text[i]==pattern[j])
        {
            i++;
            j++;
        }
        else
        {
            if(j)
                j=lps[j-1];
            else
                i++;
        }
        if(j==pattern.length())
        {
            cout<<i-pattern.length()<<endl;
            j=lps[j-1];
            found=true;
        }
    }
    if(!found)cout<<endl;
}
int main()
{
    ll n;
    while(cin>>n)
    {
        string s,s1;
        cin>>s;
        cin>>s1;
        kmp(s1,s);
    }
}

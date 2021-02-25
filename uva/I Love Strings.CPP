#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k,q;
    char s[1000005],s1[1000005];
    cin>>k;
    getchar();
    while(k--)
    {
        gets(s);
        cin>>q;
        char *p;
        getchar();
        while(q--)
        {
            gets(s1);
            p=strstr(s,s1);
            if(p)
                cout<<"y"<<endl;
            else cout<<"n"<<endl;
        }
    }

}

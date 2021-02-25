#include<bits/stdc++.h>

using namespace std;

#define m 1000

int d[m];

void find_div()

{

    int i,j;

    for(i = 1; i <= m; i++)

    {

        for(j = i; j <= m; j+=i)

            d[j]++;

    }

}
bool comp(int a,int b)
{
    bool s;
    int p,q;
    p=d[a];
    q=d[b];
    if(p<q)s=1;
    else if(p==q && a>b)s=1;
    else s=0;
    return s;
}

int main()

{

    find_div();
    int arr[10005];
    for(int i=0; i<=1005; i++)arr[i]=i;
    sort(arr+1,arr+1001,comp);
    int t,n;
    cin>>t;
     for(int i=1; i<=t; i++)
    {
        cin>>n;
        printf("Case %d: %d\n",i,arr[n]);
    }
}

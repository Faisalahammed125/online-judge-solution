#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t,n,i;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>n;
        long long int sq=ceil(sqrt(1.0*n));
        cout<<sq<<endl;
    }
}

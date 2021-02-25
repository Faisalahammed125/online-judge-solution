#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll arr[15];
        for(ll i=0;i<=10;i++)arr[i]=0;
        for(ll i=1;i<=n;i++)
        {
            ll j=i;
            while(j)
            {
                ll k=j%10;
                arr[k]++;
                j/=10;
            }
        }

        for(ll i=0;i<9;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<arr[9];
        cout<<endl;
    }
}

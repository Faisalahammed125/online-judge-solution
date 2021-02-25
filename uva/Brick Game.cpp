#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n;
    cin>>t;
    for(int tt=1;tt<=t;tt++)
    {
        cin>>n;
        int arr[n+2];
        for(int i=0;i<n;i++)cin>>arr[i];
        sort(arr,arr+n);
        int k=n/2;
        cout<<"Case "<<tt<<": "<<arr[k]<<endl;
    }
}

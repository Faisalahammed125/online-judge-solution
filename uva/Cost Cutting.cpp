#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,arr[5];
    cin>>t;
    for(int tt=1;tt<=t;tt++)
    {
        for(int i=0;i<3;i++)cin>>arr[i];
        sort(arr,arr+3);
        cout<<"Case "<<tt<<": "<<arr[1]<<endl;
    }
}

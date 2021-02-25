#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        int arr[10000],dif[10000];
         bool flag=true;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int i=0;i<n-1;i++)
            dif[i]=abs(arr[i+1]-arr[i]);
        sort(dif,dif+n-1);
        for(int i=0;i<n-1;i++)
        {
            if(dif[i]!=i+1)
                flag=false;
        }
        if(flag==false)
            printf("Not jolly\n");
        else
            printf("Jolly\n");
    }
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int x=2,y;
    switch(x)
    {
    case 2:
        x=1;
        y=x+1;
    case 1:
        x=0;
        break;
    default:
        cout<<"C";
    }
    cout<<x<<" "<<y;

}

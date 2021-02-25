#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
   ll t,l,h;
   scanf("%lld",&t);
   while(t--)
   {
       scanf("%lld %lld",&l,&h);
       ll num,n=0;
       for(ll i=l;i<=h;i++)
       {
           ll c=0;
           for(ll j=1;j<=sqrt(i);j++)
           {
               if(i%j==0)
               {
                   c++;
               }
           }
           ll temp=sqrt(i);
           if(temp*temp==i)
            c=c*2-1;
           else c=c*2;
           if(c>n)
           {
               num=i;
               n=c;
           }
       }
       printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",l,h,num,n);

   }
}

#include<bits/stdc++.h>
using namespace std;
#define i64 long long int
i64 mnx,mny;

i64 ex_euclid(i64 a,i64 b, i64 &X, i64 &Y)
{
    if (b == 0)
    {
        X = 1;
        Y = 0;
        return a;
    }

    i64 xx, yy,sm;

    i64 g = ex_euclid(b, a%b, xx, yy);
    X = yy;
    Y = xx-yy*(a/b);

    return g;
}

int main()
{
    i64 a,b,x,y,t;
    cin>>t;
   while(t--)
   {
    cin>>a>>b;
    i64 gcd = ex_euclid(a/b,ceil(1.0*a/b),x,y);
    cout << x*(a/gcd) << " " << y*(a/gcd) << endl;
   }
}


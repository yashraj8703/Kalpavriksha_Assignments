#include <stdio.h>
long long modular_exp(int b,int n,int m)
{
    long long res = 1;
    while(n>0)
    {
        if(n%2!=0)
        {
            res=((res%m)*(b%m))%m;
            n=n-1;
        }
        else{
        b=((b%m)*(b%m))%m;
        n=n/2;
        }
    }
    return res;
}
int main() {
    long long b,n,m;
    printf("Enter the base: ");
    scanf("%lld",&b);
    printf("Enter the power: ");
    scanf("%lld",&n);
    printf("Enter the Modulus: ");
    scanf("%lld",&m);
    long long ans=modular_exp(b,n,m);
    printf("%lld\n",ans);
}


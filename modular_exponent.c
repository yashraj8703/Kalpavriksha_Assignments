#include <stdio.h>
long long modular_exp(long long base,long long power,long long modulus)
{
    long long result = 1;
    while(power>0)
    {
        if(power%2!=0)
        {
            result=((result%modulus)*(base%modulus))%modulus;
            power=power-1;
        }
        else{
        base=((base%modulus)*(base%modulus))%modulus;
        power=power/2;
        }
    }
    return result;
}
int main() {
    long long base,power,modulus;
    printf("Enter the base: ");
    scanf("%lld",&base);
    printf("Enter the power: ");
    scanf("%lld",&power);
    printf("Enter the Modulus: ");
    scanf("%lld",&modulus);
    long long ans=modular_exp(base,power,modulus);
    printf("%lld\n",ans);
}


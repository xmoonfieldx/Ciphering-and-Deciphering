#include<stdio.h>
#include<math.h>
int power(int a, int b, int q)
{
    if(b==1)
        return a;
    else
        return computepower(a,b)%q;
        
}
int computepower(int a, int b)
{
    if(b==0)
        return 1;
    return a*computepower(a,b-1);
}
int main()
{
    int Ya, Yb, Ka, Kb, A, q, a, b;
    printf("Primitive root(A): ");
    scanf("%d",&A);
    printf("Prime number(q): ");
    scanf("%d",&q);
    printf("A's private key: ");
    scanf("%d",&a);
    printf("B's private key: ");
    scanf("%d",&b);
    
    printf("\n\n A's public Key: ");
    Ya=power(A,a,q);
    printf("%d",Ya);
    
    printf("\nB's public key: ");
    Yb=power(A,b,q);
    printf("%d",Yb);
    
    printf("\nShared Keys\n");
    Ka=power(Ya,b,q);
    Kb=power(Yb,a,q);
    printf("Ka: %d, Kb: %d",Ka,Kb);
    
}

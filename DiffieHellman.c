#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int power(int a, int b, int q)
{
    if(b==1)
        return a;
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
    int A, q, a, b, Ya, Yb, Ka, Kb;
    printf("Primite Root(A): ");
    scanf("%d",&A);
    printf("Prime number(q): ");
    scanf("%d",&q);
    printf("Alice's private key: ");
    scanf("%d",&a);
    printf("Bob's private key: ");
    scanf("%d",&b);
    Ya=power(A,a,q);
    Yb=power(A,b,q);
    printf("Public Keys\nAlice: %d Bob: %d\n",Ya,Yb);
    Ka=power(Yb,a,q);
    Kb=power(Ya,b,q);
    printf("Shared Keys\nAlice: %d Bob:%d\n",Ka,Kb);
}

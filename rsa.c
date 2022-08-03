#include<stdio.h>
#include<math.h>
int gcdExtended(int a, int b, int *x, int *y)
{
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }
    int x1, y1; 
    int gcd = gcdExtended(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;
    return *x;
}

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
  
// Code to demonstrate RSA algorithm
int main()
{
    int m,d,e,c,p,q,n,t;
    int x, y;
    printf("M: ");
    scanf("%d",&m);
    printf("p: ");
    scanf("%d",&p);
    printf("q: ");
    scanf("%d",&q);
    printf("e: ");
    scanf("%d",&e);
    n=p*q;
    t=(p-1)*(q-1);
    d=gcdExtended(e,t,&x,&y);
    if(d<0)
        d+=26;
    printf("M:%d n:%d t:%d e:%d d:%d\n",m,n,t,e,d);
    //Computing ciphertext
    //M^emodn
    int C=power(m,e,n);
    //C^dmodn
    int M=power(C,d,n);
    printf("C: %d M: %d",C,M);
    
}

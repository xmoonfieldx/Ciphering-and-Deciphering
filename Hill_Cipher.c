#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int gcdExtended(int a, int b, int* x, int* y)
{
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }
    int x1, y1; 
    int gcd = gcdExtended(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}
int main()
{
    int n,i,j,lob=0,d;
    printf("Size: ");
    char s[100],tryn[100];
    scanf("%d",&n);
    int key[n][n],a,ink[n][n];
    char x[n];
    printf("Matrix: ");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&key[i][j]);
    printf("Plaintext: ");
    scanf("%s",s);
    for(i=0;i<strlen(s);i++)
        tryn[i]=s[i];
    for(lob=0;lob<strlen(s);lob=lob+n)
    {
        for(i=0;i<n;i++)
        {
            x[i]=s[lob+i]-'a';
        }
        for(i=0;i<n;i++)
        {
            int temp=0;
            for(j=0;j<n;j++)
            {
                a=x[j];
                int k=key[j][i];
                //printf("%d ",temp+a*k);
                temp+=a*k;
            }
            s[lob+i]=(temp%26)+'A';
        }
    }
    printf("%s",s);
    
    //Decryption
    //find determinant of matrix
    if(n==2)
        d=key[0][0]*key[1][1]-key[0][1]*key[1][0];
    else if(n==3)
        d=(key[0][0]*(key[1][1]*key[2][2]-key[1][2]*key[2][1]))-(key[1][1]*(key[0][0]*key[2][2]-key[0][2]*key[2][0]))+(key[2][2]*(key[0][0]*key[1][1]-key[0][1]*key[1][0]));
    d=d%26;
    if(d<0)
        d+=26;
    printf("\nDeterminant: %d\n",d);
    int x1,y1;
    int g = gcdExtended(d%26,26, &x1, &y1);
    int inv=x1+26;
    printf("Inverse: %d\n",inv);
    
    //compute inverse
    if(n==2)
    {
        for(i=0;i<2;i++)
            for(j=0;j<2;j++)
            {
                ink[i][j]=(inv*key[n-1-j][n-1-i])%26;
                if((i+j)%2!=0)
                {
                    ink[i][j]=-ink[i][j]+26;
                }
                    
            }
    }
    else if(n==3)
    {
        printf("%s",tryn);
        return 0;
    }
    //compute PK-1mod26
    printf("\n%d %d %d %d\n",ink[0][0],ink[0][1],ink[1][0],ink[1][1]);
    for(lob=0;lob<strlen(s);lob=lob+n)
    {
        for(i=0;i<n;i++)
        {
            x[i]=s[lob+i]-'A';
        }
        for(i=0;i<n;i++)
        {
            int temp=0;
            for(j=0;j<n;j++)
            {
                a=x[j];
                int k=ink[j][i];
                //printf("%d ",temp+a*k);
                temp+=a*k;
            }
            temp=temp%26;
            if(temp<0)
                temp+=26;
            s[lob+i]=temp+'a';
        }
    }
    printf("%s",s);
}

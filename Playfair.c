#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main() {
    // Write C code here
    int i=0, j=0, count=0,l=0,x=0,q=0,t=0;
    int check[26]={0},e,f,g,h;
    check[9]=-1;
    char k[]="newzealandnavy",play[5][5];
    char s[]="meetmeafterthetogaparty",decr[100],a,b;
    int length=strlen(k);
    //Creating matrix
    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
        {
            if(--length<0)
            {
                while(1)
                {
                    if(check[count]==0)
                    {
                        check[count]=-1;
                        play[i][j]=65+count;
                        break;
                    }
                    count++;
                }
            }
            else
            {
                x=k[l]-'a';
                if(check[x]==-1)
                {
                    l++;
                    j--;
                }
                else
                {
                    if(k[l]=='a')
                    {
                        check[0]=-1;
                    }
                    check[x]=-1;
                    play[i][j]=x+65;
                    l++;
              }
            }
        }
        for(i=0;i<5;i++)
        {
            for(j=0;j<5;j++)
                printf("%c ",play[i][j]);
            printf("\n");
        }
        printf("\n");
        for(count=0;count<strlen(s);count=count+2)
        {
            a=toupper(s[count]);
            b=toupper(s[count+1]);
            if(a==b || b=='\0')
            {
                b='X';
                count--;
            }
            //printf("%c%c\n",a,b);
            //finding pairs in matrix
            for(i=0;i<5;i++)
                for(j=0;j<5;j++)
                {
                    if(a==play[i][j])
                    {
                        e=i;
                        f=j;
                    }
                    else if(b==play[i][j])
                    {
                        g=i;
                        h=j;
                    }
                }
            //column
            if(f==h)
            {
                a=play[(e+1)%5][f];
                b=play[(g+1)%5][h];
            }
            //row
            else if(e==g)
            {
                a=play[e][(f+1)%5];
                b=play[g][(h+1)%5];
            }
            //rectangle
            else
            {
                a=play[e][h];
                b=play[g][f];
            }
            decr[q++]=a;
            decr[q++]=b;
            printf("%c%c\n",decr[q-2],decr[q-1]);
            t+=2;
        }
        printf("\n");
        
        
        
        //Decryption
        for(count=0;count<t;count=count+2)
        {
            a=toupper(decr[count]);
            b=toupper(decr[count+1]);
            //printf("%c%c\n",a,b);
            //finding pairs in matrix
            for(i=0;i<5;i++)
                for(j=0;j<5;j++)
                {
                    if(a==play[i][j])
                    {
                        e=i;
                        f=j;
                    }
                    else if(b==play[i][j])
                    {
                        g=i;
                        h=j;
                    }
                }
            //column
            if(f==h)
            {
                a=play[(e-1)%5][f];
                b=play[(g-1)%5][h];
            }
            //row
            else if(e==g)
            {
                a=play[e][(f-1)%5];
                b=play[g][(h-1)%5];
            }
            //rectangle
            else
            {
                a=play[e][h];
                b=play[g][f];
            }
            printf("%c%c\n",a,b);
        }
    return 0;
}

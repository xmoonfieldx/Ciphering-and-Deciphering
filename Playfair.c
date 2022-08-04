#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int main()
{
    int check[26]={0},i,j,k=0,l=0,na=0,x,y;
    check[9]=1;
    char s[100],key[100],lim[100],play[5][5],decr[100];
    printf("Plaintext: ");
    scanf("%s",s);
    printf("Key: ");
    scanf("%s",key);
    int length=strlen(key);
    //matrix
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            if(length==0)
            {
                while(check[l]!=0)
                    l++;
                play[i][j]=l+'A';
                check[l]=1;
            }
            else
            {
                length--;
                if(check[key[k]-'a']==0)
                {
                    play[i][j]=toupper(key[k]);
                    check[key[k]-'a']=1;
                }
                else 
                    j--;
                k++;
            }
        }
    }
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
            printf("%c ",play[i][j]);
        printf("\n");
    }
    
    int mark=0,a,b,c,d;
    
    //Encryption
    printf("Encryption: ");
    for(i=0;i<strlen(s);i=i+2)
    {
        x=toupper(s[i]);
        y=toupper(s[i+1]);
        if(x==y || y=='\0')
            y='X';
        for(j=0;j<5;j++)
            for(k=0;k<5;k++)
            {
                if(play[j][k]==x)
                {
                    a=j;
                    b=k;
                }
                if(play[j][k]==y)
                {
                    c=j;
                    d=k;
                }
            }
        //row
        if(a==c)
        {
            lim[na++]=play[a][(b+1)%5];
            lim[na++]=play[c][(d+1)%5];
        }
        //column
        else if(b==d)
        {
            lim[na++]=play[(a+1)%5][b];
            lim[na++]=play[(c+1)%5][d];
        }
        //rectangle
        else
        {
            lim[na++]=play[a][d];
            lim[na++]=play[c][b];
        }
        printf("%c%c",lim[na-2],lim[na-1]);
    }
    
    //Decryption
    na=0;
    printf("\nDecryption: ");
    for(i=0;i<strlen(lim);i=i+2)
    {
        x=toupper(lim[i]);
        y=toupper(lim[i+1]);
        if(x==y || y=='\0')
            y='X';
        for(j=0;j<5;j++)
            for(k=0;k<5;k++)
            {
                if(play[j][k]==x)
                {
                    a=j;
                    b=k;
                }
                if(play[j][k]==y)
                {
                    c=j;
                    d=k;
                }
            }
        //row
        if(a==c)
        {
            decr[na++]=play[a][(b-1+5)%5];
            decr[na++]=play[c][(d-1+5)%5];
        }
        //column
        else if(b==d)
        {
            decr[na++]=play[(a-1+5)%5][b];
            decr[na++]=play[(c-1+5)%5][d];
        }
        //rectangle
        else
        {
            decr[na++]=play[a][d];
            decr[na++]=play[c][b];
        }
        if(decr[na-1]=='X')
            decr[na-1]=decr[na-2];
        decr[na-2]=tolower(decr[na-2]);
        decr[na-1]=tolower(decr[na-1]);
    }
    decr[strlen(s)]='\0';
    printf("%s",decr);
}

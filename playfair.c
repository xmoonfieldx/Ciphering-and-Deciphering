#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main()
{
    char str[200], ciph[200], key[8], alphabet[25]="ABCDEFGHIKLMNOPQRSTUVWXYZ";
    printf("Enter the plaintext: ");
    scanf("%[^\n]%*c", str);
    printf("Enter the keyword: ");
    scanf("%[^\n]%*c",key);
    int n=0;
    printf("Plaintext: %s Key: %s\n", str, key);
    int i = 0, j = 0;
	while (i<200)
	{
		if (str[i] != ' ')
          str[j++] = toupper(str[i]);
		i++;
	}
	str[j] = '\0';

    //Create a matrix
    int k=0,l=0;
    char matrix[5][5];
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            if(key[k]!='\0')
            {
                matrix[i][j]=key[k];
                k++;
            }
            else
            {
                if(strchr(key, alphabet[l]) != NULL)
                {
                    printf("%c\n",alphabet[l]);
                    j--;
                    l++;
                }
                else
                {
                    matrix[i][j]=alphabet[l];
                    l++;
                }
            }
        }
    }
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
            printf("%c ",matrix[i][j]);
        printf("\n");
    }
    char x,y;
    int m,z=0,counter=0;
    int in,ji,mi,ni;
    printf("%s\n",str);
    //Pairing two letters and creating Cipher text 
    while(str[z]!='\0')
    {
        x=str[z];
        y=str[z+1];
        if(x==y)
        {
            y='X';
            z-=1;
        }
        else if(y=='\0')
        {
            y='X';
        }
        //printf("%c %c \n",x,y);
        //Find position of x in matrix
        for(in=0; in<5; in++)
            for(ji=0;ji<5;ji++)
            {
                //printf("%c %c\n",matrix[in][ji], x);
                if(matrix[in][ji]==x)
                {
                    i=in;
                    j=ji;
                }
            }
        //Find position of y in matrix
        for(mi=0; mi<5; mi++)
            for(ni=0;ni<5;ni++)
            {
                if(matrix[mi][ni]==y)
                {
                    m=mi;
                    n=ni;
                }
            }
        printf("%d %d %d %d \n",i,j,m,n);
        //same row
        if(i==m)
        {
            x=matrix[i][(j+1)%5];
            y=matrix[m][(n+1)%5];
        }
        //same column
        else if(j==n)
        {
            printf("%d %d\n\n", x, y);
            x=matrix[(i+1)%5][j];
            y=matrix[(m+1)%5][n];
            printf("%d %d\n\n", x, y);
        }
        //rectangle
        else
        {
            x=matrix[i][n];
            y=matrix[m][j];
        }
        ciph[counter++]=x;
        ciph[counter++]=y;
        z+=2;
    }
    printf("\n");
    i=0;
    while(ciph[i+1]!='\0')
        printf("%c",ciph[i++]);
}

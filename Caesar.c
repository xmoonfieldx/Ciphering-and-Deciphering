#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    // Write C code here
    int key=3,i=0;
    char s[200],x=' ';
    scanf("%[^\n]s",s);
    printf("After encryption: ");
    while(s[i]!=0)
    {
        if(s[i]==' ')
            printf("%c",s[i++]);
        else
        {
            s[i]=(s[i]-'a'+key)%26;
            printf("%c",s[i]+'A');
            i++;
        }
    }
    printf("\n");
    i=0;
    printf("After decryption: ");
    while(s[i]!=0)
    {
        if(s[i]==' ')
            printf("%c",s[i++]);
        else
        {
            s[i]=(s[i]-key)%26;
            if(s[i]<0)
                s[i]+=26;
            printf("%c",s[i]+'a');
            i++;
        }
    }
    
}

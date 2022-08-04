#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    // Write C code here
    char s[100];
    int i, n;
    printf("Enter the message to be encrypted: ");
    scanf("%[^\n]s",s);
    printf("Enter the key: ");
    scanf("%d",&n);
    printf("Ciphertext: ");
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]==' ')
        {
            printf("%c",s[i]);
        }
        else{
            s[i]=(s[i]-'a'+n)%26;
            s[i]+='A';
            printf("%c",s[i]);
        }
    }
    printf("\nPlaintext: ");
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]==' ')
            printf("%c",s[i]);
        else{
            s[i]=(s[i]-'A'-n)%26;
            if(s[i]<0)
                s[i]+=26;
            s[i]+='a';
            printf("%c",s[i]);
        }
    }
    return 0;
}

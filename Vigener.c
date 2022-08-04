#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int i;
    char s[100],key[20];
    printf("Plaintext: ");
    scanf("%s",s);
    printf("Key: ");
    scanf("%s",key);
    int m=strlen(key);
    for(i=0;i<strlen(s);i++)
        s[i]=((s[i]-'a')+(key[i%m]-'a'))%26+'A';
    printf("\nEncryption: %s",s);
    for(i=0;i<strlen(s);i++)
        s[i]=((s[i]-'A')-(key[i%m]-'a')+26)%26+'a';
    printf("\nEncryption: %s",s);
}

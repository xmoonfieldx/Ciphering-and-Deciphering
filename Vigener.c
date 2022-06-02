int main() {
    // Write C code here
    char x[]="paymoremoneys";
    char key[]="cashnotneeded";
    char a,b,c;
    int i,j;
    for(i=0;i<strlen(x);i++)
    {
        a=x[i]-'a';
        b=key[i%strlen(key)]-'a';
        x[i]=(a+b)%26+'A';
    }
    printf("After encryption: ");
    printf("%s",x);
    for(i=0;i<strlen(x);i++)
    {
        a=x[i]-'A';
        b=key[i%strlen(key)]-'a';
        c=(a-b)%26;
        if(c<0)
            c+=26;
        x[i]=c+'a';
    }
    printf("\n\nAfter Decryption: ");
    printf("%s",x);
    return 0;
}

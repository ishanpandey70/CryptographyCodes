#include <stdio.h>
int main(){
    char plaintext[20];
    char encrypt[20];
    char decrypt[20];
    printf("Enter the string: \n");
    char*ptr = plaintext;
    scanf("%s",&plaintext);
    printf(" plain-text is : %s\n",plaintext);
    int a=0;
    printf("Enter the key: \n");
    scanf("%d", &a);
    a= a%26;
    printf(" key is %d\n",a );

    // Encrypt
    int l =0;
    while (plaintext[l]!='\0')
    {   
        //Debug 
        // printf("char is %c \n",plaintext[l]);

        char ch = plaintext[l]-65;

        //Debug 
        // printf("value of char is %d \n",ch);

        ch= (ch+a)%26;
        ch = ch+65;
        // Debug 
        printf("value of char(encrypt) is %d \n",ch);
        printf("%c",ch);

        encrypt[l]= ch;
        
       l++;
    }
     encrypt[l] ='\0';
    printf("\n the encrypted text  is : %s",encrypt);
    
    //Decrypt

 int m =0;
    while (encrypt[m]!='\0')
    {   
        //Debug 
        // printf("char is %c \n",plaintext[l]);

        char ch = encrypt[m]-65;
        //Debug
        // printf("value of char is %d \n",ch);

        ch= (ch-a+26)%26;
        ch = ch+65;
        //Debug
        // printf("value of char(encrypt) is %d \n",ch);
        // printf("%c",ch);

        decrypt[m]= ch;
        
       m++;
    }
     decrypt[l] ='\0';
    printf("\n the encrypted text  is : %s",decrypt);
   

return 0;
}
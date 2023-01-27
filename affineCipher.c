#include <stdio.h>
int gcd(int a , int b);
int gcd(int a , int b){
    if(a==0)
    {
        return b;
    }
    return gcd(b%a,a);
}

int main(){
    char plaintext[20];
    char encrypt[20];
    char decrypt[20];
    printf("Enter the string: \n");
    char*ptr = plaintext;
    scanf("%s",&plaintext);
    printf(" plain-text is : %s\n",plaintext);
    int a=0;
    printf("Enter the a: \n");
    scanf("%d", &a);
    while (gcd(a,26)!=1)
    { 
        printf("gcd of a and 26 is not 1 \n");
        printf("Enter a again: \n");
        scanf("%d", &a);
    }
    int b =0;
    printf("Enter the b: \n");
    scanf("%d", &b);
    while (b>25 || b<0)
    { 
        printf("b should be between 0 to 25 \n");
        printf("Enter b again: \n");
        scanf("%d", &b);
    }


    // Encrypt
    int l =0;
    while (plaintext[l]!='\0')
    {   
        //Debug 
        // printf("char is %c \n",plaintext[l]);

        char ch = plaintext[l]-65;

        //Debug 
        // printf("value of char is %d \n",ch);

        ch= (ch*a)%26;
        ch = (ch+b)%26;
        ch = ch+65;
        // Debug 
        printf("value of char(encrypt) is %d \n",ch);
        printf("%c\n",ch);

        encrypt[l]= ch;
        
       l++;
    }
     encrypt[l] ='\0';
    printf("\n the encrypted text  is : %s",encrypt);


    //calculating Inverse
    int ainv =0;
    for(int i =0 ; i<26 ; i++){
        if((a*i)%26 == 1)
        { 
            ainv=i;
            break;
        }
    }




    //Decrypt
 int m =0;
    while (encrypt[m]!='\0')
    {   
        //Debug 
        // printf("char is %c \n",plaintext[l]);

        char ch = encrypt[m]-65;
        //Debug
        // printf("value of char is %d \n",ch);

        ch= (ch-b+26)%26;
        ch= (ch*ainv)%26;
        ch = ch+65;
        //Debug
        // printf("value of char(encrypt) is %d \n",ch);
        // printf("%c",ch);

        decrypt[m]= ch;
        
       m++;
    }
     decrypt[l] ='\0';
    printf("\n the decrypted text  is : %s",decrypt);
   

return 0;
}
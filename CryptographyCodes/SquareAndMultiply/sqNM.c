#include <stdio.h>
int  getLength(double x)
{
    int length =1;
    while(x!=1)
    {
        x =(int)(x /2);
        length++;
    }
    return length;
}
int squareAndMultiply(int x,int y){
    int Z = 1;
    for(int i= getLength(y);i>=0 ; i++)
    {
        Z = Z*Z;
        if(y>>i ==1)
        {
            Z= Z*x;
        }
    }
    return Z;
}
int main(){
     int a =0;
     
     printf("Enter the number \n:");
     scanf("%d", &a);
     int b = 0;
     printf("Enter the power \n:");
    scanf("%d", &b);
     printf(squareAndMultiply(a,b));
return 0;
}

// int squareAndMultiply(int x,int y){
//     int Z = 1;
//     for(int i= getLength(y);i>=0 ; i--)
//     {
//         Z = Z*Z;
//         if(y>>i ==1)
//         {
//             Z= Z*x;
//         }
//     }
//     return Z;
// }
#include <stdio.h>
unsigned char s[4][4] = {{247,212,88,77},
                        {134,10,38,212},
                        {212,34,49,212},
                        {31,92,76,213},
                        };
unsigned char snew[4][4];

unsigned char xs(unsigned char s){
    unsigned char t;
    t = s<<1;
    if(s>>7 ==1)
    {
        t = t^27;
    }
    // printf("for %d  we get %d \n",s,t);
        return t;
}

int main(){
   
    for(int j =0 ; j< 4 ; j++)
    {
        for(int i =0 ; i < 4; i++)
        {
            snew[i][j] = xs(s[i][j]) ^ xs(s[(i+1)%4][j]) ^ s[(i+1)%4][j] ^s[(i+2)%4][j] ^s[(i+3)%4][j];
        }
    }
    for(int k =0 ; k< 4; k++)
    {
        for (int l = 0 ; l<4; l++)
        {
            printf("%d, ", snew[k][l]);
        }
        printf("\n");
    }
     
return 0;
}


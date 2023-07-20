
#include <stdio.h>
unsigned char s[4][4] = {{219,242,45,212},
                        {19,10,38,212},
                        {83,34,49,212},
                        {69,92,76,213},
                        };
unsigned char snew[4][4];

unsigned char xs(unsigned char s)
{
    unsigned char t;
    t = s << 1;
    // if there is overflow , take mod with g(x)
    if (s >> 7 == 1)
    {
        t = t ^ 27;
    }
    return t;
}
void mixCols(unsigned char x[4][4])
{
    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < 4; i++)
        {
            snew[i][j] = x[i][j] ^ xs(xs(x[(i + 1) % 4][j])) ^ xs(xs(x[(i + 2) % 4][j])) ^ xs(xs(x[(i + 3) % 4][j])) ^ x[(i + 3) % 4][j];
        }
    }
}
int main(){
    for(int i = 0 ; i<4; i++)
    {
        for(int j = 0 ;j<4;j++)
        {
            printf("%x ",s[i][j]);
        }
    printf("\n");
    }
    mixCols(s);
    printf("\n");
    for(int i = 0 ; i<4; i++)
    {
        for(int j = 0 ;j<4;j++)
        {
            printf("%x ",snew[i][j]);
        }
    printf("\n");
    }
return 0;
}
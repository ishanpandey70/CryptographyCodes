/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
unsigned int paddedMessage[16]={0};
unsigned int paddedMessage2[32]={0};
int k [] ={  0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
   0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
   0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
   0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
   0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
   0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
   0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
   0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};
int* internal(int h0,int h1,int h2,int h3,int h4,int h5,int h6,int h7,int message[]);
int rightRotate(int n, unsigned int d);
void sha256(int plaintext[] );
int padding(int length,int plaintext[]);

int main(){
     
    int plaintext[2] = {0x00000001,0x00000002};
    sha256(plaintext);
    printf("\n");
    //  plaintext[2] = {0x00000001,0x00000002};
    sha256(plaintext);
    return 0;
}


int* internal(int h0,int h1,int h2,int h3,int h4,int h5,int h6,int h7,int message[]){
    int w[64];
    for(int i = 0 ; i<15; i++)
    {
        w[i] = message[i];

    }
    for (int i = 16; i<64; i++)
    {
        int s0 = rightRotate(w[i-15],7) ^ rightRotate(w[i-15],18) ^ (w[i-15] >> 3);
        int s1 = rightRotate(w[i-2],17) ^ rightRotate(w[i-2],19) ^ (w[i-2] >> 10);
        w[i] = w[i-16] + s0 + w[i-7] + s1;

    }
    int a = h0;
    int b = h1;
    int c = h2;
    int d = h3;
    int e = h4;
    int f = h5;
    int g = h6;
    int h = h7;
    
    //compression function
    for (int i = 0 ; i < 64; i++){
        int S1 = rightRotate(e,6) ^ rightRotate(e,11) ^ rightRotate(e,25);
        int ch = (e & f) ^ ((~e) & g);
        int temp1 = h + S1 + ch + k[i] + w[i];
        int S0 = rightRotate(a,2) ^ rightRotate(a,13) ^ rightRotate(a,22);
        int maj = (a & b) ^ (a & c) ^ (b & c);
        int temp2 = S0 + maj;

        h = g;
        g = f;
        f = e;
        e = d + temp1;
        d= c;
        c= b;
        b= a;
        a = temp1 + temp2;
    }
    //store a,b,c,d,e,f,g,h in arr 
    h0 = h0 + a;
    h1 = h1 + b;
    h2 = h2 + c;
    h3 = h3 + d;
    h4 = h4 + e;
    h5 = h5 + f;
    h6 = h6 + g;
    h7 = h7 + h;

    static int arr[8];
    arr[0] = h0;
    arr[1] = h1;
    arr[2] = h2;
    arr[3] = h3;
    arr[4] = h4;
    arr[5] = h5;
    arr[6] = h6;
    arr[7] = h7;
    return arr;
}
int rightRotate(int n, unsigned int d)
{
    return (n >> d)|(n << (32 - d));
}


void sha256(int plaintext[] ){
    int h0 = 0x6a09e667;
    int h1 = 0xbb67ae85;
    int h2 = 0x3c6ef372;
    int h3 = 0xa54ff53a;
    int h4 = 0x510e527f;
    int h5 = 0x9b05688c;
    int h6 = 0x1f83d9ab;
    int h7 = 0x5be0cd19;
    
    if (padding(2,plaintext)==1){

        int *p = internal(h0,h1,h2,h3,h4,h5,h6,h7,paddedMessage);
    for(int i = 0 ; i<8;i++){
        printf("%x",*(p + i));
    }
        
    }
    else{

        for(int i = 0 ; i<2;i++){
        int *p = internal(h0,h1,h2,h3,h4,h5,h6,h7,paddedMessage);
        for(int i = 0 ; i<8;i++){
        printf("%x",*(p + i));
        }
        printf("\n")   ;
        }
         
    }
}
    




int padding(int length,int plaintext[]){
    // plaintext[0]=1;

    printf("\n length is  = %d \n", length);
     
   
    
    //if length is less than 448 bits
    if (length*32 +1+64 <= 512 )
    {
        int i ;
        for(i = 0 ; i<length;i++){
            paddedMessage[i] = plaintext[i];
        }
        paddedMessage[i]=1<<31;
       //store length in last 64 bits 
         paddedMessage[15]=length*32;
          return 1;

    }
    else {

        //store length in last 64 bits of paddedMessage2    
        paddedMessage2[31]=length*32;
        //copy plaintext to paddedMessage2
        int i ;
        for(i = 0 ; i<length;i++){
            paddedMessage2[i] = plaintext[i];
        }
        paddedMessage2[i]=1<<31;
        return 2 ;
    }
  


}

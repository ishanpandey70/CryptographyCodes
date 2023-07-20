
//Name - IShan Pandey
//ROll number - 202051089
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#define P 173
#define X_theta 0
#define Y_theta 0

uint32_t X[186] = {0};
uint32_t Y[186] = {0};

uint32_t x3 = 0;
uint32_t y3 = 0;

uint32_t findAdditiveInverse(uint32_t a)
{
    return P - a;
}


uint32_t s = 0;
uint32_t t = 0;

uint32_t ExtendedEuclideanAlgorithm(uint32_t a, uint32_t b)
{
   
    uint32_t q = 0;
    uint32_t r = 1;
    uint32_t s1 = 1;
    uint32_t s2 = 0;
    uint32_t s3 = 1;
    uint32_t t1 = 0;
    uint32_t t2 = 1;
    uint32_t t3 = 0;

   
    while (r > 0)
    {
        // The calculations
        q = a / b;
        r = a - q * b;
        s3 = s1 - q * s2;
        t3 = t1 - q * t2;

        
        if (r > 0)
        {
            a = b;
            b = r;
            s1 = s2;
            s2 = s3;
            t1 = t2;
            t2 = t3;
        }
    }
    s = s2;
    t = t2;
    return (s + P) % P;
}


 unsigned char a = 0x01;
    unsigned int words[60];
    unsigned char key[32] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,};
    unsigned char RoundKeys[4][4][15];
    unsigned char snew[4][4];
    unsigned char snewd[4][4];

    unsigned char ciphertext1[4][4];
    unsigned char ciphertext2[4][4];
    unsigned char ciphertext_2[4][4];
    static unsigned int arr[8];
    unsigned char p[4][4] =
        {
            {0xb7, 0xfd, 0x93, 0x26},
            {0x07, 0x0d, 0x03, 0x06},
            {0x17, 0x1d, 0x13, 0x16},
            {0x27, 0x2d, 0x23, 0x26}

    };
    unsigned char sub[16][16] =
        {
            {0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76},
            {0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0},
            {0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15},
            {0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75},
            {0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84},
            {0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf},
            {0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8},
            {0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2},
            {0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73},
            {0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb},
            {0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79},
            {0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08},
            {0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a},
            {0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e},
            {0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf},
            {0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16}};
    void copy(unsigned char x[4][4], unsigned char y[4][4]);
    unsigned char subBytes(unsigned char t);
    unsigned int rotWord(unsigned int word);
    void DecryptAES(unsigned char iv1[16]);
    unsigned int subWord(unsigned int word);
    unsigned char invSubBytes(unsigned char t);
    void mixCols(unsigned char x[4][4]);
    void invMixCols(unsigned char x[4][4]);
    void shiftRow(unsigned char x[4][4]);
    void invShiftRow(unsigned char x[4][4]);
    void subBytesM(unsigned char x[4][4]);
    void KeyschedulingAlgorithm();
    unsigned char timesE(unsigned char x);
    unsigned char timesD(unsigned char x);
    unsigned char times9(unsigned char x);
    unsigned char timesB(unsigned char x);
    void invSubBytesM(unsigned char x[4][4]);
    unsigned char xs(unsigned char s);
    void makeBlock(unsigned char x[32], int start);
    void EncryptAesCbc(unsigned char iv[32], unsigned char x[4][4]);
    void xorWithKey(int keyIndex);
    void KeyStore();
    void copyIV(unsigned char iv[32]);
    void xorWithIV(unsigned char iv[32]);
    void Encryption();
    void DecryptAES( unsigned char iv1[32]);
    void Decryption();
    unsigned char M_A[32] = {0};

void Add(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2)
{
    uint32_t m = 0;
    if(( (x1==0 && y1 == 0) && !(x2==0 && y2==0) ) )
    {
        x3 = x2;
        y3 = y2;
        printf("Theta case");
        return; 
    }
    else if( ((x2==0 && y2==0) &&   !(x1==0 && y1 == 0)  ))
    {
        printf("Theta case");
        x3 = x1;
        y3 = y1;
        return; 
    }


    else if ((x1 == x2) && (y1 == findAdditiveInverse(y2)))
    {
        printf("Theta case");
        x3 = 0;
        y3 = 0;
        return;
    }
    else if ((x1 != x2) && (y1 != y2))
    {
        uint32_t numerator = (y2 + findAdditiveInverse(y1)) % P;
        uint32_t denominator = (x2 + findAdditiveInverse(x1)) % P;
        m = (numerator * ExtendedEuclideanAlgorithm(denominator, P)) % P;
    }
    else
    {
        
        uint32_t m_part1 = (3 * x1 * x1 + 23) % P;
       
        uint32_t m_part2 = ExtendedEuclideanAlgorithm(2 * y1, P) % P;
      
        m = (m_part1 * m_part2) % P;
       
    }
    uint32_t part1_x3 = (m * m) % P;
     
    uint32_t part2_x3 = findAdditiveInverse((x1 + x2) % P);
    
    x3 = (part1_x3 + part2_x3) % P;
    
    
    uint32_t part1_y3 = y1 % P;
  
    
    uint32_t part2_y3 = (m * ((x3 + findAdditiveInverse(x1)) % P)) % P;
    
    
    y3 = (part1_y3 + part2_y3) % P;
 
    y3 = findAdditiveInverse(y3);
}
void CalculatePoints(){
uint32_t number = 0;
    for (uint32_t x = 0; x <= 172; x++)
    {
        for (uint32_t y = 0; y <= 172; y++)
        {
            uint32_t temp = (y * y) % P;
            uint32_t temp1 = (x * x * x + 23 * x + 11) % P;
            if (temp == temp1)
            {
                X[number] = x;
                Y[number] = y;
                number++;
            }
        }
    }
}

int paddedMessage[16]={0};
int paddedMessage2[32]={0};
int k [] ={  0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
   0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
   0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
   0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
   0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
   0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
   0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
   0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};
int* internal(unsigned int h0,unsigned int h1,unsigned int h2,unsigned int h3,unsigned int h4,unsigned int h5,unsigned int h6,unsigned int h7,  unsigned int* message);

int rightRotate(int n, unsigned int d);
void sha256(int length,int plaintext[] );
int padding(int length,int plaintext[]);

int main(void)
{
    CalculatePoints();
    // Select a point alpha which lies on the curve
    srand(time(0));
    int index = rand()%186;
    int x_alpha  =X[index] ;
    int y_alpha  = Y[index];
    // x_alpha = 133;
    // y_alpha = 73;
    
    //This alpha has time dependent seed due to which we have used <time.h> . 
    printf("\n alpha generated is ( %d , %d ) \n ",X[index],Y[index] );
    
    //Asking For Alice's Private Key:
    printf("\n Please Enter Alice's private key : \n");
    int na=0; 
    scanf("%d",&na);
    while (!(na<=150 && na>=1))
    {
        printf("\n Enter the key again in the range of 1 to 150 included: \n ");
        scanf("%d",&na);

    }
    printf("\n Alice 's secret Key is :%d \n",na);
    
     //Asking For Bob's Private Key:
    printf("\n Please Enter Bob's private key : \n");
    int nb=0; 
    scanf("%d",&nb);
    while (!(nb<=150 && nb>=1))
    {
        printf("\n Enter the key again in the range of 1 to 150 included: \n ");
        scanf("%d",&nb);

    }
    printf("\n Bob's secret Key is :%d \n",nb);

    //Performing ECDH
    //I have na and nb which are secret keys of Alice and Bob . To get Public Key of Alice , I should do  na times alpha to get public key of alice
    //Similarly nb times alpha for public key of Bob


    
    //Calculation of Public Key of Alice
    
    
    //naAlpha = alpha + (na-1)alpha
    //Bottom up approach 
    // start with  alpha
    // 2 alpha = alpha +alpha
    // 3 alpha = alpha + 2 alpha
    //nP = alpha + (n-1)P
    x3 = x_alpha;
    y3= y_alpha;
    for(int i = 0 ; i<na-1 ;i++)
    {
        Add(x_alpha,y_alpha,x3,y3);  
        
    }
    int x_a_publicKey = x3;
    int y_a_publicKey = y3;
    printf("\n Public key of Alice is (%d,%d) \n", x_a_publicKey,y_a_publicKey);

    //The Public key of alice is sent to Bob . Bob will multiply do nb times public key of alice. This should return shared secret key. 
    x3 = x_a_publicKey;
    y3= y_a_publicKey;
    for(int i = 0 ; i<nb-1 ;i++)
    {
        Add(x_a_publicKey,y_a_publicKey,x3,y3);  
        
    }
    int x_a_sharedKey = x3;
    int y_a_sharedKey = y3;
    printf("\n Shared key from Alice 's public Key is (%d,%d) \n", x_a_sharedKey,y_a_sharedKey);

    //Calculation of Public Key of Bob
    x3 = x_alpha;
    y3= y_alpha;
    for(int i = 0 ; i<(nb-1) ;i++)
    {
        Add(x_alpha,y_alpha,x3,y3);  
        
    }
    int x_b_publicKey = x3;
    int y_b_publicKey = y3;

    printf("\n Public key of Bob is (%d,%d) \n", x_b_publicKey,y_b_publicKey);
    //The Public key of alice is sent to Bob . Bob will multiply do nb times public key of alice. This should return shared secret key. 
    x3 = x_b_publicKey;
    y3= y_b_publicKey;
    for(int i = 0 ; i<na-1 ;i++)
    {
        Add(x_b_publicKey,y_b_publicKey,x3,y3);  
        
    }
    int x_b_sharedKey = x3;
    int y_b_sharedKey = y3;
    printf("\n Shared key from Bob 's public Key is (%d,%d) \n The shared Key from  Alice's public key and Bob's Public key should be same. \n", x_b_sharedKey,y_b_sharedKey);
    
    int a[]= {x_a_sharedKey,y_a_sharedKey};
    int b[]= {x_b_sharedKey,y_b_sharedKey};


    //Caculation of SHA of KA and KB
    printf("\n SHA of KA is : \n");
    sha256(2,a);
    printf("\n SHA of KB is : \n");
    sha256(2,b);
    
        // Encryption

        Encryption();
       
        printf("\n\n CA : ");
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                printf("%02x ", ciphertext1[j][i]);
            }
        }
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                printf("%02x ", ciphertext2[j][i]);
            }
        }
        printf("\n");


        // Decryption

        //********************************************************************************
        
        copy(p,ciphertext1);
       
        printf("\n\n");
        printf("MB is  given below and should be same as MA:");
        Decryption();

        //MAC calculation

        
        unsigned char inputKAx1[32];
        

        printf(" \n Enter 256-bit  KA which you got in hexadecimal format (32 bytes): \n");
        for (int i = 0; i < 32; i++) {
            scanf("%2hhx", &inputKAx1[i]);
        }
        unsigned char inputKAx2[32];
        for(int i = 0 ; i < 32 ; i++)
        {
            inputKAx2[i] = inputKAx1[i];
        }
        inputKAx2[31]= inputKAx2[31] ^2;


        inputKAx1[31]= inputKAx1[31] ^1;
        unsigned char concat[64];
        for(int i = 0 ; i<32; i++)
        {
            concat[i] = inputKAx2[i];
        }
        for(int i = 32 ; i<64; i++)
        {
            concat[i] = M_A[i];
        }
        sha256(64,concat);
        printf("\n Enter hash  : \n");
        unsigned char hash[32];
        for(int i = 0 ; i<32 ; i++)
        {
            scanf("%2hhx",&hash[i]);
        }
        unsigned char concat2[64];
        for(int i = 0 ; i<32; i++)
        {
            concat2[i] = inputKAx1[i];
        }
        for(int i = 32 ; i<64; i++)
        {
            concat2[i] = hash[i];
        }
        printf("\n MAC A is : \n");
        sha256(64,concat2);

        //MAC B calculation
         unsigned char inputKBx1[32];
      

        printf(" \n Enter 256-bit  KB which you got in hexadecimal format (32 bytes): \n");
        for (int i = 0; i < 32; i++) {
            scanf("%2hhx", &inputKBx1[i]);
        }
        unsigned char inputKBx2[32];
        for(int i = 0 ; i < 32 ; i++)
        {
            inputKBx2[i] = inputKBx1[i];
        }
        inputKBx2[31]= inputKBx2[31] ^2;


        inputKBx1[31]= inputKBx1[31] ^1;
        unsigned char concatB[64];
        for(int i = 0 ; i<32; i++)
        {
            concatB[i] = inputKBx2[i];
        }
        for(int i = 32 ; i<64; i++)
        concatB[i] = M_A[i];
        sha256(64,concatB);
        printf("\n Enter hash  : \n");
        unsigned char hashB[32];
        for(int i = 0 ; i<32 ; i++)
        {
            scanf("%2hhx",&hashB[i]);
        }
        unsigned char concat2B[64];
        for(int i = 0 ; i<32; i++)
        {
            concat2B[i] = inputKBx1[i];
        }
        for(int i = 32 ; i<64; i++)
        {
            concat2B[i] = hashB[i];
        }
        printf("\n MAC B is : \n");
        sha256(64,concat2B);
       





    
    
   
    
    

}

int* internal(unsigned int h0,unsigned int h1,unsigned int h2,unsigned int h3,unsigned int h4,unsigned int h5,unsigned int h6,unsigned int h7,  unsigned int* message){
    unsigned int w[64];
    for(int i = 0 ; i<=15; i++)
    {
        w[i] = message[i];

    }
    for (int i = 16; i<64; i++)
    {
        unsigned int s0 = rightRotate(w[i-15],7) ^ rightRotate(w[i-15],18) ^ (w[i-15] >> 3);
        unsigned int s1 = rightRotate(w[i-2],17) ^ rightRotate(w[i-2],19) ^ (w[i-2] >> 10);
        w[i] = w[i-16] + s0 + w[i-7] + s1;

    }
    unsigned int a = h0;
    unsigned int b = h1;
    unsigned int c = h2;
    unsigned int d = h3;
    unsigned int e = h4;
    unsigned int f = h5;
    unsigned int g = h6;
    unsigned int h = h7;
    
    //compression function
    for (int i = 0 ; i < 64; i++){
        unsigned int S1 = rightRotate(e,6) ^ rightRotate(e,11) ^ rightRotate(e,25);
        unsigned int ch = (e & f) ^ ((~e) & g);
        unsigned int temp1 = h + S1 + ch + k[i] + w[i];
        unsigned int S0 = rightRotate(a,2) ^ rightRotate(a,13) ^ rightRotate(a,22);
        unsigned int maj = (a & b) ^ (a & c) ^ (b & c);
        unsigned int temp2 = S0 + maj;

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


void sha256(int length,int plaintext[] ){
    int h0 = 0x6a09e667;
    int h1 = 0xbb67ae85;
    int h2 = 0x3c6ef372;
    int h3 = 0xa54ff53a;
    int h4 = 0x510e527f;
    int h5 = 0x9b05688c;
    int h6 = 0x1f83d9ab;
    int h7 = 0x5be0cd19;
    
    if (padding(length,plaintext)==1){
    
        int *p = internal(h0,h1,h2,h3,h4,h5,h6,h7,paddedMessage);
        for(int i = 0 ; i<8;i++){
        printf("%x",*(p + i));
    }
    
    }
    else{
        
        for(int i = 0 ; i<2;i++){
        
        int *p = internal(arr[0],arr[1],arr[2],arr[3],arr[4],arr[5],arr[6],arr[7],paddedMessage);
       
  
        for(int i = 0 ; i<8;i++){
        printf("%x",*(p + i));
        }
        printf("\n")   ;
        }
         
    }
}
    




int padding(int length,int plaintext[]){
    // plaintext[0]=1;
    

     
   
    
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









    void DecryptAES(unsigned char iv1[16]){
        

        xorWithKey(14);
        invShiftRow(p);
        invSubBytesM(p);
        
        for (int i = 13; i > 0; i--)
        {
            xorWithKey(i);
            invMixCols(p);
            copy(p, snewd);
            invShiftRow(p);
            invSubBytesM(p);
        }

        xorWithKey(0);
        
        
        xorWithIV(iv1);

        
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                printf("%02x ", p[j][i]);
            }
        }

    }
    
    
        
        
    void Decryption(){
        unsigned char iv[16] = {0};
        
        DecryptAES(iv);
       
        int ivIndex = 0;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                iv[ivIndex] = ciphertext1[j][i];
                ivIndex++;
            }
        }
       
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                p[j][i]=ciphertext2[j][i];
            }
        }
        DecryptAES(iv);
        
    }
    
    void Encryption()
    {
        printf("\n Enter the 256 bit key KA which is shown on your screen: \n");
        for (int i = 0; i < 32; i++)
        {
            scanf("%2hhx", &key[i]);
        }
        KeyschedulingAlgorithm();
        KeyStore();

        // Key set with KA

        unsigned char iv[32] = {0};
        // take 256 bit input and store in unsigned char array
        
        printf("Enter the 256 bit input : ");
        for (int i = 0; i < 32; i++)
        {
            scanf("%2hhx", &M_A[i]);
        }

        printf("M_A is : ");
        for (int i = 0; i < 32; i++)
        {
            printf("%2x ", M_A[i]);
        }
        // Encryption

        // AES takes in 128 bit block as input so we need to divide the input into 128 bit blocks
        // First Block
        makeBlock(M_A, 0);
       
        EncryptAesCbc(iv, ciphertext1);
        copyIV(iv);
        
        
        // Second Block
        makeBlock(M_A, 16);
        printf("\n\n");
        
        EncryptAesCbc(iv, ciphertext2);
    }

    void copyIV(unsigned char iv[32])
    {

        int ivIndex = 0;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                iv[ivIndex] = p[j][i];
                ivIndex++;
            }
            
        }
    }

    void KeyStore()
    {
        int wordidx = 0;
        for (int k = 0; k < 15; k++)
        {
            for (int j = 0; j < 4; j++)
            {
                RoundKeys[0][j][k] = words[wordidx] >> 24;          // extract first byte
                RoundKeys[1][j][k] = (words[wordidx] >> 16) & 0xFF; // extract the second byte
                RoundKeys[2][j][k] = (words[wordidx] >> 8) & 0xFF;  // extract the third byte
                RoundKeys[3][j][k] = words[wordidx] & 0xFF;         // extract the fourth byte (least significant)
                wordidx++;
            }
        }
    }
    void xorWithIV(unsigned char iv[16])
    {
        int ivIndex = 0;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                p[j][i] = p[j][i] ^ iv[ivIndex];
                ivIndex++;
            }
        }
    }
    void EncryptAesCbc(unsigned char iv[32], unsigned char x[4][4])
    {

        // outputs 128 bits of ciphertext which is stored in p[4][4](where the plain text was stored)
        xorWithIV(iv);
        xorWithKey(0);
        for (int i = 0; i < 13; i++)
        {
            subBytesM(p);
            shiftRow(p);
            mixCols(p);
            copy(p, snew);

           
            xorWithKey(i + 1);
        }
        subBytesM(p);
        shiftRow(p);
        xorWithKey(14);
        copy(x, p);
       
        
    }
    void xorWithKey(int keyIndex)
    {

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                p[i][j] = p[i][j] ^ RoundKeys[i][j][keyIndex];
            }
        }
    }
    void makeBlock(unsigned char x[32], int start)
    {
        int index = start;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                p[j][i] = x[index];
                index++;
            }
        }
        
    }

    void subBytesM(unsigned char x[4][4])
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                x[i][j] = subBytes(x[i][j]);
            }
        }
    }

    unsigned char subBytes(unsigned char t)
    {
        int t1, t2;
        t1 = t & 15;
        t2 = t >> 4;
        return sub[t2][t1];
    }
    void invSubBytesM(unsigned char x[4][4])
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                x[i][j] = invSubBytes(x[i][j]);
            }
        }
    }
    unsigned char invSubBytes(unsigned char t)
    {

        unsigned char x;
        for (int i = 0; i < 16; i++)
        {
            for (int j = 0; j < 16; j++)
            {
                if (sub[i][j] == t)
                {

                    x = i;
                    x = x << 4;
                    x = x | j;
                    break;
                }
            }
        }
        return x;
    }

    void shiftRow(unsigned char x[4][4])
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < i; j++)
            {
                unsigned char temp = x[i][0];
                x[i][0] = x[i][1];
                x[i][1] = x[i][2];
                x[i][2] = x[i][3];
                x[i][3] = temp;
            }
        }
    }
    void invShiftRow(unsigned char x[4][4])
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < i; j++)
            {

                unsigned char temp = x[i][3];
                x[i][3] = x[i][2];
                x[i][2] = x[i][1];
                x[i][1] = x[i][0];
                x[i][0] = temp;
            }
        }
    }

    unsigned char xs(unsigned char s)
    {
        unsigned char t;
        t = s << 1;
        if (s >> 7 == 1)
        {
            t = t ^ 27;
        }
        // printf("for %d  we get %d \n",s,t);
        return t;
    }
    void mixCols(unsigned char x[4][4])
    {
        for (int j = 0; j < 4; j++)
        {
            for (int i = 0; i < 4; i++)
            {
                snew[i][j] = xs(x[i][j]) ^ xs(x[(i + 1) % 4][j]) ^ x[(i + 1) % 4][j] ^ x[(i + 2) % 4][j] ^ x[(i + 3) % 4][j];
            }
        }
    }
    void invMixCols(unsigned char x[4][4])
    {
        // 0E = 00001110 -> x^3+x^2+x
        // 0B = 00001011 = x^3+x+1
        // 0D = 00001101 = x^3+x^2+1
        // 09 = 00001001 = x^3+1
        for (int j = 0; j < 4; j++)
        {
            for (int i = 0; i < 4; i++)
            {

                snewd[i][j] = timesE(x[i][j]) ^ timesB(x[(i + 1) % 4][j]) ^ timesD(x[(i + 2) % 4][j]) ^ times9(x[(i + 3) % 4][j]);
            }
        }
    }
    // method to multiply with polynomial 0E in inverse of mixcolumns
    unsigned char timesE(unsigned char x)
    {
        // The logic is to use distributive multiplication and take care of mod
        // so for the case of (x^2 + x+ 1)(px)  = x^2(px) + x(px) + p(x)  while making sure each unit is modm
        // 0E = 00001110 -> x^3+x^2+x
        unsigned char x3ans;
        unsigned char x2ans;
        unsigned char x1ans;
        unsigned char ans = x;
        for (int i = 1; i <= 3; i++)
        {
            ans = xs(ans);
            if (i == 2)
            {
                x2ans = ans;
            }
            else if (i == 3)
            {
                x3ans = ans;
            }
            else if (i == 1)
            {
                x1ans = ans;
            }
        }
        return x3ans ^ x2ans ^ x1ans;
    }
    // method to multiply with polynomial 0B in inverse of mixcolumns
    unsigned char timesB(unsigned char x)
    {
        // The logic is to use distributive multiplication and take care of mod
        // so for the case of (x^2 + x+ 1)(px)  = x^2(px) + x(px) + p(x)  while making sure each unit is modm
        // 0B = 00001011 = x^3+x+1
        unsigned char x3ans;
        unsigned char x1ans;
        unsigned char ans = x;
        for (int i = 1; i <= 3; i++)
        {
            ans = xs(ans);
            if (i == 3)
            {
                x3ans = ans;
            }
            else if (i == 1)
            {
                x1ans = ans;
            }
        }
        return x3ans ^ x1ans ^ x;
    }

    // method to multiply with polynomial 0D in inverse of mixcolumns
    unsigned char timesD(unsigned char x)
    {
        // The logic is to use distributive multiplication and take care of mod
        // so for the case of (x^2 + x+ 1)(px)  = x^2(px) + x(px) + p(x)  while making sure each unit is modm
        // 0D = 00001101 = x^3+x^2+1
        unsigned char x3ans;
        unsigned char x2ans;
        unsigned char ans = x;
        for (int i = 1; i <= 3; i++)
        {
            ans = xs(ans);
            if (i == 2)
            {
                x2ans = ans;
            }
            else if (i == 3)
            {
                x3ans = ans;
            }
        }
        return x3ans ^ x2ans ^ x;
    }

    // method to multiply with polynomial 09 in inverse of mixcolumns
    unsigned char times9(unsigned char x)
    {
        // 09 = 00001001 = x^3+1
        //  The logic is to use distributive multiplication and take care of mod
        //  so for the case of (x^2 + x+ 1)(px)  = x^2(px) + x(px) + p(x)  while making sure each unit is modm
        // 0E = 00001110 -> x^3+x^2+x
        unsigned char x3ans;
        // unsigned char x2ans;
        // unsigned char x1ans;
        unsigned char ans = x;
        for (int i = 1; i <= 3; i++)
        {
            ans = xs(ans);
            if (i == 3)
            {
                x3ans = ans;
            }
        }
        return x3ans ^ x;
    }

    void KeyschedulingAlgorithm()
    {
        unsigned int Rcon[10] = {0x01000000, 0x02000000, 0x04000000, 0x08000000, 0x10000000, 0x20000000, 0x40000000, 0x80000000, 0x1B000000, 0x36000000};

        const int Nb = 4;  // Number of columns (32-bit words) in a state.
        const int Nk = 8;  // Number of 32-bit words in the key.
        const int Nr = 14; // Number of rounds in AES-256.

        int i = 0;

        // Copy the key into the first Nk words of the key schedule.
        for (i = 0; i < Nk; i++)
        {
            words[i] = ((unsigned int)key[4 * i] << 24) |
                    ((unsigned int)key[4 * i + 1] << 16) |
                    ((unsigned int)key[4 * i + 2] << 8) |
                    ((unsigned int)key[4 * i + 3]);
        }

        // Generate the rest of the key schedule.
        for (i = Nk; i < Nb * (Nr + 1); i++)
        {
            unsigned int temp = words[i - 1];
            if (i % Nk == 0)
            {
                // Perform the key schedule core.
                temp = subWord(rotWord(temp)) ^ Rcon[i / Nk - 1];
            }
            else if (Nk > 6 && i % Nk == 4)
            {
                // Special case for Nk > 6.
                temp = subWord(temp);
            }
            words[i] = words[i - Nk] ^ temp;
        }
    }

    unsigned int subWord(unsigned int word)
    {
        unsigned char wordsOf1Byte[4];

        wordsOf1Byte[0] = (word >> 24) & 0xFF;
        wordsOf1Byte[1] = (word >> 16) & 0xFF;
        wordsOf1Byte[2] = (word >> 8) & 0xFF;
        wordsOf1Byte[3] = word & 0xFF;

        for (int i = 0; i < 4; i++)
        {
            wordsOf1Byte[i] = subBytes(wordsOf1Byte[i]);
        }

        unsigned int result = 0;
        for (int i = 0; i < 4; i++)
        {
            result = result | wordsOf1Byte[i];
            if (i != 3)
            {
                result = result << 8;
            }
        }

        return result;
    }

    // method to apply left circular shift by 1 byte operation on a word given as input
    unsigned int rotWord(unsigned int word)
    {
        // word as input and return rotation of the word

        unsigned char temp = word >> 24;
        word = word << 8;

        word = word | temp;

        return word;
    }
    // copies y to x
    void copy(unsigned char x[4][4], unsigned char y[4][4])
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                x[i][j] = y[i][j];
            }
        }
    }
#include <stdio.h>
unsigned char subBytes(unsigned char t);
unsigned int rotWord(unsigned int word);
unsigned int subWord(unsigned int word);
unsigned char xs(unsigned char s);
void KeyschedulingAlgorithm();
void shiftRow(unsigned char x[4][4]);

//TO-DO -> Change SubByte function in key scheduling


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
unsigned char key[16]={0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A,0x0A};
//To-Do My notes have numbering in opposite order of index so this may have to change , confirm once
//Store word in unsigned int as it is of 32 bits
unsigned int words[44];
unsigned char snew[4][4];
unsigned char snewd[4][4];
unsigned char times165(unsigned char x);
unsigned char times7(unsigned char x);
unsigned char times115(unsigned char x);
unsigned char times26(unsigned char x);

//Function to multiply by x 

unsigned char subBytes(unsigned char t)
{
    int t1,t2;
    t1 = t&15;
    t2 = t>>4;
    return sub[t2][t1];

}
unsigned char invSubBytes( unsigned char t)
{
    unsigned char x; 
    int flag = 0;
    for(int i =0 ; i <16 ; i++)
    {
        for (int j = 0 ; j<16 ; j++)
        {
            if(sub[i][j]==t)
            {   flag =1;
                x= i ; 
                x = x<<4;
                x = x|j;
                break ;
            }
        }
        if(flag ==1)
        {break;}
    }
    return x;
}
void invShiftRow(unsigned char x[4][4])
{
    for (int i = 0 ; i < 5 ;i++)
    {
        for (int j = 0; j<i; j++)
        {          

            unsigned char temp= x[i][3];
            x[i][3]= x[i][2];
            x[i][2] = x[i][1];
            x[i][1]= x[i][0];
            x[i][0] =temp ;
            
        }
    }

}


unsigned int rotWord(unsigned int word)
{
    // word as input and return rotation of the word
    printf("Input to rotWord: %x \n",word);
    unsigned char temp= word>>24;
    word = word<<8;
  
    word = word | temp;
    printf("Output from Rotword: %x \n",word);
    return word;

}
unsigned int subWord(unsigned int word)
{
    //word as input and return rotation of the word
    
    printf("input to subWord is %x \n ",word);
  unsigned char wordsOf1Byte[4];
    
    wordsOf1Byte[0] = (word >> 24) & 0xFF;
    wordsOf1Byte[1] = (word >> 16) & 0xFF;
    wordsOf1Byte[2] = (word >> 8) & 0xFF;
    wordsOf1Byte[3] = word & 0xFF;
    
   for(int i = 0 ; i < 4; i++)
   {
    wordsOf1Byte[i] = subBytes(wordsOf1Byte[i]);
   }
   

  
   unsigned int result = 0;
   for(int  i=0; i <4; i++)
   {
    
    result = result|wordsOf1Byte[i];
    if(i!=3)
    result = result<<8;
   }
   printf("Output of subWord is %x \n",result);
   return result;

}
unsigned char xs(unsigned char s){
    unsigned char t;
    t = s<<1;
    //if there is overflow , take mod with g(x)
    if(s>>7 ==1)
    {
        t = t^27;
    }
        return t;
}



void KeyschedulingAlgorithm()
{
    //Round constants
    unsigned int Rcon[10]={0x01000000,0x02000000,0x04000000,0x08000000,0x10000000,0x20000000,0x40000000,0x80000000,0x1B000000,0x36000000};
    for(int i =0 ;i<=3;i++)
    {
        words[i]=  ((unsigned int)key[4*i]<< 24) | ((unsigned int)key[4*i+1]<< 16) | ((unsigned int)key[4*i+2] << 8) | (unsigned int)key[4*i+3];

    }
    for(int i = 4; i<=43;i++)
    {
        unsigned int temp = words[i-1];
        if(i%4==0)
        {   
            temp = subWord(rotWord(temp))^Rcon[i/4-1];
        }
         words[i] = words[i-4] ^ temp;

    }
}

void shiftRow(unsigned char x[4][4])
{
    for (int i = 0 ; i < 5 ;i++)
    {
        for (int j = 0; j<i; j++)
        {
            unsigned char temp = x[i][0];
            x[i][0]= x[i][1];
            x[i][1]= x[i][2];
            x[i][2] = x[i][3];
            x[i][3]= temp;
        }
    }

}



void mixCols(unsigned char x [4][4]){
    for(int j =0 ; j< 4 ; j++)
    {
        for(int i =0 ; i < 4; i++)
        {
            snew[i][j] = x[i][j] ^ xs(xs(x[(i+1)%4][j]))  ^ xs(xs(x[(i+2)%4][j])) ^ xs(xs(x[(i+3)%4][j])) ^x[(i+3)%4][j] ;
        }
    }
}
void invMixCols(unsigned char x[4][4])
{
    //165 = 10100101 => x^7+ x^5+x^2+1
    // 7 = 111 => x^2+x+1
    // 26 = 11010 => x^4+ x^3+x
    // 115 =1110011 => x^6 + x^5 + x^4 + x +1


    //Needs to be changed
    for(int j =0 ; j< 4 ; j++)
    {
        for(int i =0 ; i < 4; i++)
        {
            snewd[i][j] = times165(x[i][j]) ^ times7(x[(i+1)%4][j])  ^ times26(x[(i+2)%4][j]) ^ times115(x[(i+3)%4][j])  ;
        }
    }

}

unsigned char times165(unsigned char x){
    //The logic is to use distributive multiplication and take care of mod 
    //165 = 10100101 => x^7+ x^5+x^2+1
    
    unsigned char x7ans;
    unsigned char x5ans;
    unsigned char x2ans;
    unsigned char ans = x;
    for(int i = 1 ;i <=7;i++ )
    {
        ans = xs(ans);
        if(i == 2)
        {
            x2ans = ans;
        }
        else if( i == 5)
        {
            x5ans = ans;
        }
        else if(i == 7)
        {
            x7ans = ans;
        }
    }
    return x7ans ^ x5ans^ x2ans ^ x;




}
unsigned char times7(unsigned char x){
    // 7 = 111 => x^2+x+1
       //The logic is to use distributive multiplication and take care of mod 
       // so (x^2 + x+ 1)(px)  = x^2(px) + x(px) + p(x)  while making sure each unit is modm 
    unsigned char x2ans;
    unsigned char x1ans;
    unsigned char ans = x;
    for(int i = 1 ;i <=2;i++ )
    {
        ans = xs(ans);
        if(i == 1)
        {
            x1ans = ans;
        }
        else if(i == 2)
        {
            x2ans = ans;
        }
        
    }
    return x2ans ^ x1ans^ x; 



    
}
unsigned char times26(unsigned char x){

 // 26 = 11010 => x^4+ x^3+x
    unsigned char x4ans;
    unsigned char x3ans;
    unsigned char x1ans;
    unsigned char ans = x;
    for(int i = 1 ;i <=4;i++ )
    {
        ans = xs(ans);
        if(i == 1)
        {
            x1ans = ans;
        }
        else if(i == 3)
        {
            x3ans = ans;
        }
        else if(i == 4)
        {
            x4ans = ans;
        }
        
    }
    return x4ans ^ x3ans^ x1ans; 



    
}
unsigned char times115(unsigned char x){

 // 115 =1110011 => x^6 + x^5 + x^4 + x +1
    unsigned char x6ans;
    unsigned char x5ans;
    unsigned char x4ans;
    unsigned char x1ans;
    unsigned char ans = x;
    for(int i = 1 ;i <=6;i++ )
    {
        ans = xs(ans);
        if(i == 1)
        {
            x1ans = ans;
        }
        else if(i == 4)
        {
            x4ans = ans;
        }
        else if(i == 5)
        {
            x5ans = ans;
        }
         else if(i == 6)
        {
            x6ans = ans;
        }
        
    }
    return x6ans ^ x5ans^ x4ans ^ x1ans ^x; 

    
}






int main(){
    
 
    //Take plaintext and do xor with round key
    //Then pass through round function
        //For subbytes do multiply by x and add 1 
        //Shiftrow same
        //Mixed column matrix is changed
    //Keep this loop till 10 rounds just change round 10 round function
    //Print the encryption
    //Do reverse for decryption



 



    // //Taking Key as input
    printf("Please enter a 128 bit Key (32 hex characters):");
    for(int i =0 ; i<16; i++)
    {
        scanf("%2hhx", &key[i]); // read in each byte of the hexadecimal number as an unsigned char
    }

    printf(" \n Your Key is : \n");
    for(int i =0 ; i <16 ; i++)
    {
        printf("%d %x ,",i,key[i]);
    }
    printf("\n");
    //Applying KeyScheduling Algorithm to form all the keys and store it in key array 
    KeyschedulingAlgorithm();
    //Print all the words
    // for(int i = 0 ;i<44;i++)
    // {
    //     printf("%x",words[i]);
    // }






    //Taking plain text as input 
  unsigned char hexInput[4][4]; // array to store 128-bit hexadecimal number as unsigned chars
    printf("\n Enter a 128-bit hexadecimal number: \n");
    for (int i = 0; i < 4; i++) {
        for(int j =0 ; j<4; j++)
        {
            scanf("%2hhx", &hexInput[j][i]); // read in each byte of the hexadecimal number as an unsigned char
        }
        
    }
    //copying the input in storedInput array
    unsigned char storedInput[4][4];
    for(int i = 0 ; i<4; i++)
    {
        for(int j = 0 ; j<4; j++)
        {
            storedInput[i][j] = hexInput[i][j];
        }
    }
    printf("\n The input of mixCols is : \n");
    for(int i = 0 ; i<4; i++)
    {
        for(int j = 0 ; j<4; j++)
        {
            printf("%x ",hexInput[i][j]);
        }
        printf("\n");
    }
    mixCols(hexInput);
    
    
   
    invMixCols(snew);
    printf("\n Inverse mix cols is :\n");
     for(int i = 0 ; i<4; i++)
    {
        for(int j = 0 ; j<4; j++)
        {
            printf("%x ",snewd[i][j]);
        }
        printf("\n");
    }















return 0;
}


#include <stdio.h>
unsigned short plaintext; //16 bit plaintext hex
unsigned int key ;//32 bit key hex
unsigned short sBox[]= {0xE,0x4,0xD,0x1,0x2,0xF,0xB,0x8,0x3,0xA,0x6,0xC,0x5,0x9,0x0,0x7 }; //Sbox Array
int PBox[]={1,5,9,13,2,6,10,14,3,7,11,15,4,8,12,16};
unsigned short sBoxinv[] ={0xE,0x3,0x4,0x8,0x1,0xC,0xA,0xF,0x7,0xD,0x9,0x6,0xB,0x2,0x0,0x5}; // Sbox inverse array

unsigned short keyGen(int round);

unsigned short keyGen(int round){
    unsigned int KeyCopy = key;
    int start  = 4*round-3;
    unsigned short roundKey = key>>(17-start);
    return roundKey; //returns 16 bit round key

    
}
int main(){
     
     printf("Enter the plain text : ");
     scanf("%x", &plaintext);
     printf("The plain text is %x\n",plaintext);
     
     printf("Enter the key:");
     scanf("%x",&key);
     printf("The key is %x \n",key);
     

     //Round 1
     printf("The key for round 1 is %x \n",keyGen(1));
     //After XOR with k1
     unsigned short u1 = plaintext ^ keyGen(1); //both 16bit is stored in 16bit u1
     printf("U1 is (hexadecimal) %x \n",u1);
     //substitution box array
    unsigned short v1 =  sBox[(u1& 0xF000)>>12];
    // printf("v1 is %x \n",v1);
    v1= v1<<4;
    // printf("v1 is %x \n",v1);  
    v1 = v1|sBox[(u1& 0x0F00)>>8];
    v1= v1<<4;
    // printf("v1 is %x \n",v1); 
    v1 =  v1|sBox[(u1& 0x00F0)>>4];
    v1= v1<<4;
    // printf("v1 is %x \n",v1); 
    v1 =  v1|sBox[(u1& 0x000F)];
    printf("v1 final is %x \n",v1);
    //substitution done

    //Permutation  
    unsigned short w1=0;
    unsigned short copy = v1;
   
    for(int i =0 ; i<16; i++)
    {
       copy =v1;
       copy= copy>>(16-PBox[i]);    
       copy = copy &1;
       copy = copy<<(16-(i+1));
       w1= w1|copy;
      
       
   
    }
    printf("w1 is %x \n",w1);
//Permutation Done

//Permutation Inverse
unsigned short w1inv=0;
    unsigned short copyinv = w1;
   
    for(int i =0 ; i<16; i++)
    {
       copyinv =w1;
       copyinv= copyinv>>(16-PBox[i]);    
       copyinv = copyinv &1;
       copyinv = copyinv<<(16-(i+1));
       w1inv= w1inv|copyinv;
      
       
   
    }
    printf("w1inv is %x \n",w1inv);
   
     //Reversing Sbox
   
    unsigned short v1inv =  sBoxinv[(w1inv& 0xF000)>>12];
    v1inv= v1inv<<4;
    v1inv = v1inv|sBoxinv[(w1inv& 0x0F00)>>8];
    v1inv= v1inv<<4;
    v1inv =  v1inv|sBoxinv[(w1inv& 0x00F0)>>4];
    v1inv= v1inv<<4;
    v1inv =  v1inv|sBoxinv[(w1inv& 0x000F)];
    printf("v1inv  is %x \n",v1inv);
    // Reversed substitution


return 0;
}

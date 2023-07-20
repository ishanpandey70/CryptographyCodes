
//*************************************************************************************************************************************
                                                            // 202051089 
                                                            // Ishan Pandey
//*************************************************************************************************************************************
#include <stdio.h>
//Global variables and arrays
unsigned short plaintext; //16 bit plaintext hex
unsigned int key ;//32 bit key hex
unsigned short sBox[]= {0xE,0x4,0xD,0x1,0x2,0xF,0xB,0x8,0x3,0xA,0x6,0xC,0x5,0x9,0x0,0x7 }; //Sbox Array
int PBox[]={1,5,9,13,2,6,10,14,3,7,11,15,4,8,12,16};
unsigned short sBoxinv[] ={0xE,0x3,0x4,0x8,0x1,0xC,0xA,0xF,0x7,0xD,0x9,0x6,0xB,0x2,0x0,0x5}; // Sbox inverse array

//Function prototypes
unsigned short keyGen(int round);
unsigned short substitution(unsigned short u);
unsigned short permutationInv(unsigned short w);
unsigned short substitutionInv(unsigned short winv);

//returns 16 bit round key
unsigned short keyGen(int round){
    unsigned int KeyCopy = key;
    int start  = 4*round-3;
    unsigned short roundKey = key>>(17-start);
    return roundKey; 
}
//Function which returns substitution
unsigned short substitution(unsigned short u)
{
    unsigned short v =  sBox[(u& 0xF000)>>12];
    v= v<<4;
    v = v|sBox[(u& 0x0F00)>>8];
    v= v<<4;
    v =  v|sBox[(u& 0x00F0)>>4];
    v= v<<4;
    v =  v|sBox[(u& 0x000F)];
    return v;
}

//Function which returns permutation
unsigned short permutation(unsigned short v)
{
    unsigned short w = 0; 
    unsigned short copy = v;
   
    for(int i =0 ; i<16; i++)
    {
       copy =v;
       copy= copy>>(16-PBox[i]);    
       copy = copy &1;
       copy = copy<<(16-(i+1));
       w= w|copy;

    }
    return w;
}

//Function which returns permutation inverse (Same as permutation function in this case however I have coded a general case where we will need permutation inverse)
unsigned short permutationInv(unsigned short w)
{
    
    unsigned short winv=0;
    unsigned short copyinv = w;
   
    for(int i =0 ; i<16; i++)
    {
       copyinv =w;
       copyinv= copyinv>>(16-PBox[i]);    
       copyinv = copyinv &1;
       copyinv = copyinv<<(16-(i+1));
       winv= winv|copyinv;
    }
    return winv;
}

//Function which returns inverse substitution
unsigned short substitutionInv(unsigned short winv){
    unsigned short vinv =  sBoxinv[(winv& 0xF000)>>12];
    vinv= vinv<<4;
    vinv = vinv|sBoxinv[(winv& 0x0F00)>>8];
    vinv= vinv<<4;
    vinv =  vinv|sBoxinv[(winv& 0x00F0)>>4];
    vinv= vinv<<4;
    vinv =  vinv|sBoxinv[(winv& 0x000F)];
    return vinv;
}
int main(){
     
     printf("Enter the plain text : ");
     scanf("%x", &plaintext);
     printf("The plain text is %x\n",plaintext);
     
     printf("Enter the key:");
     scanf("%x",&key);
     printf("The key is %x \n",key);

     //Encryption Begins
     
// **********************************************************************
    //Round 1
    //Generating round 1 key
    printf("The key for round 1 is %x \n",keyGen(1));
    //After XOR with k1
    unsigned short u1 = plaintext ^ keyGen(1); 
    //substitution round 1
    unsigned short v1 = substitution(u1);
    //Permutation  round 1
    unsigned short w1=permutation(v1); 
    
// **********************************************************************
    //Round 2
    //Generating round 2 key
    printf("The key for round 2 is %x \n",keyGen(2));
    //After XOR with k2
    unsigned short u2 = w1 ^ keyGen(2); 
    //substitution round 2
    unsigned short v2 = substitution(u2);
    //Permutation  round 2
    unsigned short w2=permutation(v2); 


// **********************************************************************
    //Round 3
    //Generating round 3 key
     printf("The key for round 3 is %x \n",keyGen(3));
    //After XOR with k3
    unsigned short u3 = w2 ^ keyGen(3); 
    //substitution round 3
    unsigned short v3 = substitution(u3);
    //Permutation  round 3
    unsigned short w3=permutation(v3); 

// **********************************************************************
    //Round 4
    //Generating round 4 key
    printf("The key for round 4 is %x \n",keyGen(4));
    //After XOR with k4
    unsigned short u4 = w3 ^ keyGen(4); 
    //substitution round 4
    unsigned short v4 = substitution(u4);

    // **********************************************************************
    //Round 5
    //Generating round 5 key
    printf("The key for round 5 is %x \n",keyGen(5));
    //After XOR with k5
    unsigned short y = v4 ^ keyGen(5); 
    printf("*****************************************************************************\n");
    printf("Final encryption is %x \n",y);
    printf("*****************************************************************************\n");

    //Encryption Ends
// **************************************************************************************************************



    //Decryption Begins
// *****************************************************************************************************
    //Decrypting Round 5
    unsigned short yinv = y^ keyGen(5);
// *****************************************************************************************************
    //Decrypting Round 4
    unsigned short v4inv = substitutionInv(yinv);
    unsigned short u4inv = v4inv ^ keyGen(4);

// *****************************************************************************************************
    //Decrypting Round 3
    unsigned short w3inv = permutationInv(u4inv);
    unsigned short v3inv = substitutionInv(w3inv);
    unsigned short u3inv = v3inv^keyGen(3);
// *****************************************************************************************************
    //Decrypting Round 2
    unsigned short w2inv = permutationInv(u3inv);
    unsigned short v2inv = substitutionInv(w2inv);
    unsigned short u2inv = v2inv ^ keyGen(2);
// *****************************************************************************************************
    //Decrypting Round 1
    unsigned short w1inv = permutationInv(u2inv);
    unsigned short v1inv = substitutionInv(w1inv);
    unsigned short u1inv = v1inv ^ keyGen(1);
    printf("*****************************************************************************\n");
    printf("Final Plaintext recieved after decryption %x \n",u1inv);
    printf("Should match  plaintext %x \n",plaintext);
    printf("*****************************************************************************\n");

    //Decryption Ends
// **************************************************************************************************************

return 0;
}

// 202051089 
// Ishan Pandey


#include <stdio.h>
#include <string.h>
#include <stdbool.h> //used only for isCorrect method as string does not have inbuilt boolean type


bool RepFlag = false;
bool lenFlag = false;
int RepIdx =-1;
bool isCorrect(char plaintext[60]);

void findij(char ch, char matrix[5][5],int* x , int* y);
void playfair_encryption(char * plaintext,char matrix[5][5],int length);


void findij(char ch, char matrix[5][5],int* x , int* y)
{
     for(int i = 0 ; i<5;i++)
     {
          for(int j = 0 ; j<5; j++)
          {
               if(matrix[i][j]==ch)
               {
                    *x = i;
                    *y =j;
                    break;
               }
          }
     }

}


void playfair_encryption(char* plaintext,char matrix[5][5],int length){
     for(int i = 0 ; i<length ;i=i+2)
     {
          printf("Iteration %d",i/2);
          int ic1=-1,ic2=-2,jc1=-1,jc2=-2;
          findij(plaintext[i],matrix,&ic1,&jc1);
          findij(plaintext[i+1],matrix,&ic2,&jc2);


          //debug codes
          // printf("\n char is %c \n",plaintext[i]);
       
          // printf("\n index is %d %d\n",ic1,jc1);

          // printf("\n char is %c \n",plaintext[i+1]);
          // printf("\n index is %d %d\n",ic2,jc2);

          if((ic1!=ic2)&& (jc1!=jc2))
          {
               plaintext[i]=matrix[ic1][jc2];
               plaintext[i+1]=matrix[ic2][jc1];
               
          }
           else if((ic1!=ic2)&& (jc1==jc2)){
               plaintext[i]= matrix[(ic1+1)%5][jc1];
               
               plaintext[i+1]= matrix[(ic2+1)%5][jc1];
           }
           else if((ic1==ic2)&& (jc1!=jc2)){
               plaintext[i]= matrix[(ic1)][(jc1+1)%5];
               
               plaintext[i+1]= matrix[(ic1)][(jc2+1)%5];
           }
     }
}


bool isCorrect(char plaintext[60]){
     //checking for repetetion first
     for(int i = 0 ; i<strlen(plaintext);i=i+2)
     {
          if(plaintext[i]== plaintext[i+1])
          {
               RepFlag= true;
               RepIdx=i;
               return false;
          }
     }
     
     // then checking for length
     if(strlen(plaintext)%2!=0)
     {    lenFlag=true;
          return false;
     }
     
     return true;
}





int main()
{
     char plaintext[60];
     printf("Enter the plain text of atmost 40 length \n");
     scanf("%s", &plaintext);
         printf("The size of string is %d \n",strlen(plaintext));

     if(isCorrect(plaintext))
     {
          printf("Correct String");
     }
     else
     {
         
          do
          {
               
               
               if(RepFlag)
               {    char temp[60];
                    temp[0]='x';
                    int j =1;
                    for(int i=RepIdx+1;i<strlen(plaintext);i++)
                    {
                         temp[j]= plaintext[i];
                         j++;
                    }
                    temp[j]='\0';
                    j=0;
                    for(int i = RepIdx+1; i<strlen(plaintext)+1;i++)
                    {
                         plaintext[i]= temp[j];
                         j++;
                    }
                    plaintext[strlen(plaintext)]='\0';
                    printf("\n After removal of same text %s",plaintext);
                    printf("\n Intermediate length is : %d \n", strlen(plaintext));
     



                    RepFlag= false;
                    // debug statement 
                    // printf("Repflag = false");
               }
               else if(lenFlag)
               {
                    // printf("lenflag case");
                    printf("The length before adding x is  %d \n",strlen(plaintext));
                    int currentlength = strlen(plaintext);
                    plaintext[currentlength]='x';
                    printf("The string after adding x is %s \n",plaintext);
                    printf("The length is %d \n",strlen(plaintext));
                    plaintext[++currentlength]='\0';
                    lenFlag=false;
               }
          } while (!isCorrect(plaintext));
          
          
          
          
     printf("\n Final text without repetion and of even length is : %s \n",plaintext);
     printf("\n Its length is : %d \n", strlen(plaintext));
     
     }

    //turns Js to Is
    printf("\n ****************************************************** \n"); 
    printf("\n The size of string is %d \n",strlen(plaintext));
    printf("\n The string is %s \n",plaintext);
     
    for(int i = 0 ; i< strlen(plaintext);i++)
    {
     if(plaintext[i]=='j')
     {
          // printf("\n Original plaintext was %s \n",plaintext);
          plaintext[i]='i';
          // printf("\n New plaintext is %s \n",plaintext);
     }
     

    }
printf("\n ****************************************************** \n"); 
char delta[60] ;
strcpy(delta,plaintext);
printf("The delta string is %s ",delta);
printf("\n ****************************************************** \n"); 
char k1[60] ;
printf("\n Enter the key text \n");
scanf("%s", k1);
 
   printf("\n ****************************************************** \n"); 
    printf("\n The key is %s \n",k1);

     //turns Js to Is
    for(int i = 0 ; i< strlen(k1);i++)
    {
     if(k1[i]=='j')
     {
          // printf("\n Original plaintext was %s \n",plaintext);
          k1[i]='i';
          // printf("\n New plaintext is %s \n",plaintext);
     }
    }
    printf("\n ****************************************************** \n"); 
    printf("\n The final key is (after turning Js to Is) %s \n",k1);   

    //Generating the matrix
    int HashTable[26] ={0};
    char playfairMatrix [5][5];
    int keyIdx =0;
    int row = 0 ; 
    int col = 0; 
    
     while(keyIdx<strlen(k1)) {
          if( HashTable[(int)k1[keyIdx]-97] == 0)
          {
               if(keyIdx<strlen(k1))
               {
                    
                    HashTable[(int)k1[keyIdx]-97]=1;
                    playfairMatrix[row][col]=k1[keyIdx];

               }
               
               col= (col+1);
               if(col>4)
               {
                    col = col%5;
                    row++;
                    printf("\n");
               }
               

          }
     keyIdx++;
     }




int hashpoint = 0;
HashTable[9]=1;

printf("\n ****************************************************** \n");   
printf("\nPrinting the matrix\n");
for(int i = 0 ; i<26 ; i++)
{
    
    
     if(HashTable[hashpoint]==0)
     {
          // printf("%c", 97+i);
          playfairMatrix[row][col]= (char)(97+i);
          HashTable[hashpoint]=1;
          col= (col+1);
          if(col>4)
          {
               col = col%5;
               row++;
               
          }

     }
     
     hashpoint++;

}

printf("\n");

//printing the array
    for( int i  = 0 ; i <5 ; i++)
    {
     for( int j = 0 ; j<5; j++)
     {
          printf("%c" , playfairMatrix[i][j]);
     }
     printf("\n");
    }

printf("\n");

//playfair encrypt
printf("\n calling playfair encryption function \n");
playfair_encryption(plaintext,playfairMatrix,strlen(plaintext));
printf("\nThe cipher text is %s \n",plaintext);


return 0;
}
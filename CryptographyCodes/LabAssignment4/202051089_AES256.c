// Ishan Pandey 
// 202051089


    #include <stdio.h>
    unsigned char a = 0x01;
    unsigned int words[60];
    unsigned char key[32] = {
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
        0x00,
    };
    unsigned char RoundKeys[4][4][15];
    unsigned char snew[4][4];
    unsigned char snewd[4][4];

    unsigned char ciphertext1[4][4];
    unsigned char ciphertext2[4][4];
    unsigned char ciphertext_2[4][4];
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

    int main()
    {

        // Encryption

        Encryption();
        //print ciphertext1
        printf("\n\nCiphertext 1 is : ");
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                printf("%02x ", ciphertext1[j][i]);
            }
        }
        //print ciphertext2
        printf("\n\nCiphertext 2 is : ");
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                printf("%02x ", ciphertext2[j][i]);
            }
        }
        printf("\n");

        //********************************************************************************
        // Decryption
      
        copy(p,ciphertext1);
     
        Decryption();
       

        return 0;
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

        printf("\n\nDecrypted text is : ");
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

        KeyschedulingAlgorithm();
        KeyStore();

        // Key set with KA

        unsigned char iv[32] = {0};
        // take 256 bit input and store in unsigned char array
        unsigned char M_A[32] = {0};
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
        printf("\n hue");
        // AES takes in 128 bit block as input so we need to divide the input into 128 bit blocks
        // First Block
        makeBlock(M_A, 0);
        
        EncryptAesCbc(iv, ciphertext1);
        copyIV(iv);
       
        // Second Block
        makeBlock(M_A, 16);
        printf("\n\n");
        printf("Second BLock  is : ");
        for(int i = 0 ; i<4; i++)
        {
            for (int j = 0 ; j<4; j++)
            {
                printf("%02x",p[j][i]);
            }
        }
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
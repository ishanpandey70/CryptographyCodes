#include <stdio.h>

int main() {
    unsigned char hex[16]; // array to store 128-bit hexadecimal number as unsigned chars
    printf("Enter a 128-bit hexadecimal number: ");
    for (int i = 0; i < 16; i++) {
        scanf("%2hhx", &hex[i]); // read in each byte of the hexadecimal number as an unsigned char
    }
    printf("You entered: ");
    for (int i = 0; i < 16; i++) {
        printf("%02x", hex[i]); // print out each byte of the unsigned char array in hexadecimal format
    }
    printf("\n");
    return 0;
}

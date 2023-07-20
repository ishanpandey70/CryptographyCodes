#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#define P 29
#define X_theta 0
#define Y_theta 0

uint32_t X[29] = {0};
uint32_t Y[29] = {0};

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
    // Set default values for the quotient, remainder,
    // s-variables and t-variables
    uint32_t q = 0;
    uint32_t r = 1;
    uint32_t s1 = 1;
    uint32_t s2 = 0;
    uint32_t s3 = 1;
    uint32_t t1 = 0;
    uint32_t t2 = 1;
    uint32_t t3 = 0;

    /*In each iteration of the loop below, we
    calculate the new quotient, remainder, a, b,
    and the new s-variables and t-variables.
    r decreases, so we stop when r = 0*/
    while (r > 0)
    {
        // The calculations
        q = a / b;
        r = a - q * b;
        s3 = s1 - q * s2;
        t3 = t1 - q * t2;

        /* The values for the next iteration,
        (but only if there is a next iteration)*/
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

void Add(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2)
{
    uint32_t m = 0;
    if ((x1 == x2) && (y1 == findAdditiveInverse(y2)))
    {
        x3 = 0;
        y3 = 0;
        return;
    }
    if ((x1 != x2) && (y1 != y2))
    {
        uint32_t numberator = (y2 + findAdditiveInverse(y1)) % P;
        uint32_t denominator = (x2 + findAdditiveInverse(x1)) % P;
        m = (numberator * ExtendedEuclideanAlgorithm(denominator, P)) % P;
    }
    else
    {
        uint32_t m_part1 = (3 * x1 * x1 + 7) % P;
        uint32_t m_part2 = ExtendedEuclideanAlgorithm(2 * y1, P) % P;
        m = (m_part1 + m_part2) % P;
    }
    uint32_t part1_x3 = (m * m) % P;
    uint32_t part2_x3 = findAdditiveInverse((x1 + x2) % P);
    uint32_t part1_y3 = y1 % P;
    x3 = (part1_x3 + part2_x3) % P;
    uint32_t part2_y3 = (m * ((x3 + findAdditiveInverse(x1)) % P)) % P;
    y3 = (part1_y3 + part2_y3) % P;
}

int main(void)
{
    uint32_t number = 0;
    for (uint32_t x = 0; x <= 28; x++)
    {
        for (uint32_t y = 0; y <= 28; y++)
        {
            uint32_t temp = (y * y) % P;
            uint32_t temp1 = (x * x * x + 7 * x + 2) % P;
            if (temp == temp1)
            {
                X[number] = x;
                Y[number] = y;
                number++;
            }
        }
    }
    // Add(11, 23, 26, 30);
    // printf("%d %d\n", x3, findAdditiveInverse(y3));
    // printf("%d %d\n", (x3 * x3 * x3 + 7 * x3 + 2) % P, (y3 * y3) % P);
    printf("%d\n", number);
    
}
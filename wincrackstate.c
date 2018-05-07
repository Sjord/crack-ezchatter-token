#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define PHP_RAND_MAX 0x7fff
#define RAND_RANGE(__n, __min, __max, __tmax) \
    (__min) + (long) ((double) ( (double) (__max) - (__min) + 1.0) * ((__n) / ((__tmax) + 1.0)))

static unsigned int state;

static void winsrand(unsigned int seed) {
    state = seed;
}

static unsigned int winrand() {
    const unsigned int a = 214013;
    const unsigned int c = 2531011;
    state = a * state + c;
    return (state >> 16) & 0x7fff;
}

static char * gen(int len, char * token)
{
    char * pt = token;

    while (len--) {
        int choose = RAND_RANGE(winrand(), 0, 2, PHP_RAND_MAX);
        if (choose == 0) {
            *pt = RAND_RANGE(winrand(), 'A', 'Z', PHP_RAND_MAX);
        } else if(choose == 1) {
            *pt = RAND_RANGE(winrand(), 'a', 'z', PHP_RAND_MAX);
        } else {
            *pt = RAND_RANGE(winrand(), '0', '9', PHP_RAND_MAX);
        }
        pt++;
    }
    *pt = 0;
    return token;
}

int main() {
    char token[11];
    unsigned int i;

    do {
        winsrand(i);
        gen(10, token);
        if (strcmp(token, "pgVp42QhP9") == 0) {
            printf("%d\n", i);
            return 0;
        }
    } while (++i != 0);
    printf("not found\n");
}

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define PHP_RAND_MAX 2147483647
#define RAND_RANGE(__n, __min, __max, __tmax) \
    (__min) + (long) ((double) ( (double) (__max) - (__min) + 1.0) * ((__n) / ((__tmax) + 1.0)))

static char * gen(int len, char * token)
{
    char * pt = token;

    while (len--) {
        int choose = RAND_RANGE(rand(), 0, 2, PHP_RAND_MAX);
        if (choose == 0) {
            *pt = RAND_RANGE(rand(), 'A', 'Z', PHP_RAND_MAX);
        } else if(choose == 1) {
            *pt = RAND_RANGE(rand(), 'a', 'z', PHP_RAND_MAX);
        } else {
            *pt = RAND_RANGE(rand(), '0', '9', PHP_RAND_MAX);
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
        srand(i);
        gen(10, token);
        if (strcmp(token, "2118Jx9w3e") == 0) {
            printf("%d\n", i);
            return 0;
        }
    } while (++i != 0);
    printf("not found\n");
}

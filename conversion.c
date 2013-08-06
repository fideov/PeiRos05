#include <stdlib.h>
#include <math.h>
#include "ring.h"
#include "conversion.h"

/*
int s2i(char** string) {
    return (int) strtol(string, (char **)NULL, 10);
}
 */

int bin2ring(int** string) {
    return 0;
}

void ten2two(int ten, int* two) {
    // we assume two[] is long enough, ie (int) log2(P) + 1
    int len = (int) log2(P) + 1;
    int res;
    int i = len - 1;
    do {
        res = ten % 2;
        two[i] = res;
        ten = (ten - res)/2;
        i--;
    } while (ten > 0);
    for (; i >= 0; i--)
        two[i] = 0;    
}

BinPoly ring2bin(Poly p) {
    BinPoly bp;
    int j, i;
    for (j = 0; j < N - 1; j++){
        printf ("\n%d\t%d\t", j, p.coeff[j]);
        ten2two(p.coeff[j], bp.coeff[j]);
        for (i = 0; i < C; i++)
            printf("%d ", bp.coeff[j][i]);
    }
    return bp;
}

#include <stdlib.h>
#include <math.h>
#include "ring.h"
#include "conversion.h"

/*
int s2i(char** string) {
    return (int) strtol(string, (char **)NULL, 10);
}
 */

Poly bin2ring(BinPoly bp) {
    Poly p;
    int i;
    
    for (i = 0; i < N-1; i++)
        p.coeff[i] = two2ten(bp.coeff[i]);
    
    return p;
}

int two2ten(bool* two) {
    int ten = 0;
    int n = (int)log2(P) + 1;
    int i;
    for (i = n; i != 0; i--)
        ten += ( ((int) two[n-i]) << (i-1));
    return ten;
}

void ten2two(int ten, bool* two) {
    // we assume two[] is long enough, ie (int) log2(P) + 1
    int len = (int) log2(P) + 1;
    int res;
    int i = len - 1;
    do {
        res = ten % 2;
        two[i] = (bool) res;
        ten = (ten - res)/2;
        i--;
    } while (ten > 0);
    for (; i >= 0; i--)
        two[i] = (bool) 0;    
}

BinPoly ring2bin(Poly p) {
    BinPoly bp;
    int j, i;
    for (j = 0; j < N - 1; j++){
        //printf ("\n%d\t%d\t", j, p.coeff[j]);
        ten2two(p.coeff[j], bp.coeff[j]);
        //for (i = 0; i < C; i++)
        //    printf("%d ", bp.coeff[j][i]);
    }
    return bp;
}

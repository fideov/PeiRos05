#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ring.h"
#include "knapsack.h"
#include "conversion.h"
#include "math.h"


int main(int argc, char** argv) {

    
    /*
    // some debug checks follow
    int i, j;
    Poly a, b;
    
    a.coeff[0] = 1;
    a.coeff[1] = 5;
    for (i = 2; i < N; i++)
        a.coeff[i] = 0;
    
    b.coeff[0] = 2;
    b.coeff[1] = 6;
    b.coeff[2] = 1;
    for (i = 3; i < N; i++)
        b.coeff[i] = 0;
    */
    /*
    Word alfa;
    
    alfa.poly[0] = a;
    alfa.poly[1] = b;
    for (i = 2; i < M; i++)
        alfa.poly[i] = zero_poly();
    
    show_word(alfa);
    */
    
/*
    Poly a;
    int i, j;
    a.coeff[0] = 1;
    a.coeff[1] = 5;
    for (i = 2; i < N; i++)
        a.coeff[i] = 0;
    a.coeff[4] = 51;
    
    BinPoly bp = ring2bin(a);
    
    for (i = 0; i < N-1; i++) {
        printf ("\n%d ", i);
        for (j = 0; j <= log2(P); j++)
            printf("%d", bp.coeff[i][j]);
    }
    
    
    // return a Poly. is a fix to do, the correct use is although the following
    Poly p;
    // for some black magic reason this won't work unless bin2ring doesn't
    bin2ring(bp, &p);
    show_poly(p);
*/
    
/*
   
    //ten2two works
    int n = 36; //less than 128 = 2^((int)log2(P) + 1)
    bool nt[(int)log2(P) + 1];
    int i;
    
    ten2two(n, nt);
    //int i;    
    for (i = 0; i <= log2(P); i++)
        printf ("%d ", nt[i]);
    
*/
    
/*
    
    //byte2two works
    char n = 127;
    bool nt[8];
    int i;
    
    byte2two(n, nt);
    for (i = 0; i < 8; i++)
        printf ("%d ", nt[i]);
    
*/
    
    
    return (EXIT_SUCCESS);
}

#include <stdlib.h>
#include "ring.h"

Poly add_polys (Poly a, Poly b) {
    int i;
    Poly c;
    for (i = 0; i < N; i++)
        c.coeff[i] = a.coeff[i] + b.coeff[i];
    return c;
}

Poly mult_polys (Poly a, Poly b) {
    int i, j, k;
    Poly c;
    
    for (k = 0; k < N; k++) {
        c.coeff[k] = 0;
        for (i = 0; i < N; i++)
            for (j = 0; j < N; j++)
                if (i + j % N == k)
                    c.coeff[k] += a.coeff[i] * b.coeff[j];
    }
    
    return c;
}

Poly zero_poly() {
    Poly p;
    int i;
    for (i = 0; i < N; i++)
        p.coeff[i] = 0;
    return p;
}

void show_poly(Poly a) {
    int i;
    printf ("\n a + bx + ...\n");
    for (i = 0; i < N; i++)
        printf ("%d, ", a.coeff[i]);
    printf ("\n");
}


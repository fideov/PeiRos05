#include <stdio.h>
#include "knapsack.h"


Poly Hash (Word a, Word x) {
    Poly hash = zero_poly();
    int i;
    for (i = 0; i < M; i++)
        hash = add_polys(hash, mult_polys(a.poly[i], x.poly[i]));
    return hash;
}

void show_word(Word w) {
    int i;
    printf ("\n Word:");
    for (i = 0; i < M; i++)
        show_poly(w.poly[i]);
    printf ("\n end word;");
}
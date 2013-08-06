/* 
 * File:   main.c
 * Author: fernando
 *
 * Created on August 5, 2013, 10:29 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "conversion.h"
//#include "ring.h"
#include "knapsack.h"

/*
 * 
 */



int main(int argc, char** argv) {

    // some debug checks follow
    int i;
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
    
    
    Word alfa;
    
    alfa.poly[0] = a;
    alfa.poly[1] = b;
    for (i = 2; i < M; i++)
        alfa.poly[i] = zero_poly();
    
    show_word(alfa);
    
    return (EXIT_SUCCESS);
}

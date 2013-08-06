/* 
 * File:   ring.h
 * Author: fernando
 *
 * Created on August 6, 2013, 2:58 AM
 */

#ifndef RING_H
#define	RING_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* RING_H */

#define N 71
#define P 100

typedef struct {
  int coeff[P];
} Poly;

Poly add_polys (Poly a, Poly b);
Poly mult_polys (Poly a, Poly b);
Poly zero_poly ();
void show_poly (Poly a);

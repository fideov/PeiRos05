/* 
 * File:   knapsack.h
 * Author: fernando
 *
 * Created on August 6, 2013, 4:01 AM
 */

#include "ring.h"

#ifndef KNAPSACK_H
#define	KNAPSACK_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* KNAPSACK_H */

#define M 10

typedef struct {
  Poly poly[M];
} Word;

Poly Hash (Word a, Word x);
void show_word(Word w);
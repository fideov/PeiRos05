#include "ring.h"
#define M 10

typedef struct {
  Poly poly[M];
} Word;

Poly Hash (Word a, Word x);
void show_word(Word w);
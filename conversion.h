#define C 10 //wrong! but about (int)log2(P) + 1 for P = 100
#include <stdbool.h>

typedef struct {
  bool coeff[N-1][C];
} BinPoly;

//int s2i(char** string);
Poly bin2ring(BinPoly bp);
void ten2two(int ten, bool* two);
int two2ten(bool* two);
BinPoly ring2bin(Poly p);

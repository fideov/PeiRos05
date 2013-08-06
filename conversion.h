#define C 10 //wrong! but about (int)log2(P) + 1 for P = 100

typedef struct {
  int coeff[N-1][C];
} BinPoly;

//int s2i(char** string);
Poly bin2ring(BinPoly bp);
void ten2two(int ten, int* two);
int two2ten(int* two);
BinPoly ring2bin(Poly p);

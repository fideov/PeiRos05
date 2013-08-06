#define C 10 //wrong! but about (int)log2(P) + 1 for P = 100

typedef struct {
  int coeff[N-1][C];
} BinPoly;

//int s2i(char** string);
int bin2ring(int** string);
void ten2two(int ten, int* two);
BinPoly ring2bin(Poly p);

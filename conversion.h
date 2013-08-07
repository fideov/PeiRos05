#define C 10 //wrong! but about (int)log2(P) + 1 for P = 100
#include <stdbool.h>

typedef struct {
  bool coeff[N-1][C];
} BinPoly;

typedef struct {
    int val;
    int pos;
} Sortable;

//int s2i(char** string);
Poly bin2ring(BinPoly bp, Poly * ptr);
void ten2two(int ten, bool* two);
int two2ten(bool* two);
BinPoly ring2bin(Poly p);


//sorting stuff

void sort(Sortable numbers[]);
void m_sort(Sortable numbers[], Sortable temp[], int left, int right);
void merge(Sortable numbers[], Sortable temp[], int left, int mid, int right);
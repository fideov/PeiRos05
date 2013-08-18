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
void byte2two(char byte, bool* two);
int two2ten(bool* two);
BinPoly ring2bin(Poly p);

// TODO: fix bin2ring to be void.
// WTF: what do I do with ring2poly for negative coordinates?
// It appears from how I don't care of sign in bin2ring and on the lack
// of specifications in ring2poly that I consider +/-v as the same vector


//sorting stuff

void sort(Sortable numbers[]);
void m_sort(Sortable numbers[], Sortable temp[], int left, int right);
void merge(Sortable numbers[], Sortable temp[], int left, int mid, int right);
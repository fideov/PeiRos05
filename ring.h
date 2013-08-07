#define N 71
#define P 100
#define D P

typedef struct {
  int coeff[N];
} Poly;

Poly add_polys (Poly a, Poly b);
Poly mult_polys (Poly a, Poly b);
Poly zero_poly ();
void show_poly (Poly a);

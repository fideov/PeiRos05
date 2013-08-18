#include <stdlib.h>
#include <math.h>
#include "ring.h"
#include "conversion.h"

/*
int s2i(char** string) {
    return (int) strtol(string, (char **)NULL, 10);
}
 */

Poly bin2ring(BinPoly bp, Poly * _ptr) {
    Poly p;
    Sortable s[N-1];
    int i, sign;
    int last = 0;
    
    for (i = 0; i < N-1; i++) {
        s[i].pos = i;
        s[i].val = two2ten(bp.coeff[i]);
        if (s[i].val > P/2)
            s[i].val -= P;
    }
    sort(s); //merge sort for array of Sortable
    
    //for (i = 0; i < N-1; i++)
    //    printf ("\n%d  %d  %d", i, s[i].pos, s[i].val);
    
    for (i = 0; i < N-1; i++) {
        if (i % 2 == 0)
            sign = 1;
        else
            sign = -1;
        
        p.coeff[s[i].pos] = sign * s[i].val;
    //    printf ("\n%d", p.coeff[s[i].pos]);
        
        last += p.coeff[s[i].pos];
    }
    
    p.coeff[N-1] = -last;
/*
    printf ("\n%d", p.coeff[N-1]);
    
    for (i=0; i<N; i++)
        printf ("\n%d", p.coeff[i]);
    
*/
    //show_poly(p);
    printf ("\n&p          = %d", &p);
    *_ptr = p;
    return p;
}

int two2ten(bool* two) {
    int ten = 0;
    int n = (int)log2(P) + 1;
    int i;
    for (i = n; i != 0; i--)
        ten += ( ((int) two[n-i]) << (i-1));
    return ten;
}

void ten2two(int ten, bool* two) {
    // we assume two[] is long enough, ie (int) log2(P) + 1
    // you need to input a bool []!!! int [] will mess up with step
    //eg. p.coeff[0] = 6  = 00000110
    //for bp.coeff[0] = {random values, 0, 0, 0, 0, 0, 1, 1, 0} after do-while
    //and bp.coeff[0] = {0, 0, ..., 0,  0, 0, 0, 0, 0, 1, 1, 0} after for(;...) 
    
    
    int len = (int) log2(P) + 1;
    int res;
    int i = len - 1;
    do {
        res = ten % 2;
        two[i] = (bool) res;
        ten = (ten - res)/2;
        i--;
    } while (ten > 0);
    for (; i >= 0; i--)
        two[i] = (bool) 0;    
    printf ("\n");
    for (i = 0; i <= log2(P); i++)
        printf ("%d ", (bool)two[i]);
    printf ("\nadd = %d\n", &two[0]);
}

void byte2two(char byte, bool* two) {
    // we assume two[] is long enough, ie (int) log2(P) + 1
    
    // here we make use of << to read from the right each bit. idea:
    // I have 0010. if ((0010 >> 1) << 1 == 0010) then last digit is 0
    // hence I do the same comparing ((0010 >> 1) >> 1) << 1 == (0010 >> 1)
    // for the second digit
    // this doesn't care if libc uses logic or arithmetic >>
    
    // two fits 8 bools.
    
    // the output looks to be mod 256
    int len = 8;
    char temp = byte;
    int i;
    
    for (i = 0; i < len; i++){
        two[len-i-1] = (bool) !((temp >> 1) << 1 == temp);
        temp = temp >> 1;
    }
}

BinPoly ring2bin(Poly p) {
    BinPoly bp;
    int j, i;
    for (j = 0; j < N - 1; j++){
        //printf ("\n%d\t%d\t", j, p.coeff[j]);
        ten2two(p.coeff[j], bp.coeff[j]);
        //for (i = 0; i < C; i++)
        //    printf("%d ", bp.coeff[j][i]);
    }
    return bp;
}




//sorting stuff

/* taken from http://web.archive.org/web/20120902184250/
 *            http://p2p.wrox.com/visual-c/66348-merge-sort-c-source-code.html
 */


void sort(Sortable numbers[])
{
    Sortable temp[N-1];
    int array_size = N-1;
    m_sort(numbers, temp, 0, array_size - 1);
}
 
 
void m_sort(Sortable numbers[], Sortable temp[], int left, int right)
{
  int mid;
 
  if (right > left)
  {
    mid = (right + left) / 2;
    m_sort(numbers, temp, left, mid);
    m_sort(numbers, temp, mid+1, right);
 
    merge(numbers, temp, left, mid+1, right);
  }
}
 
void merge(Sortable numbers[], Sortable temp[], int left, int mid, int right)
{
  int i, left_end, num_elements, tmp_pos;
 
  left_end = mid - 1;
  tmp_pos = left;
  num_elements = right - left + 1;
 
  while ((left <= left_end) && (mid <= right))
  {
    if (numbers[left].val <= numbers[mid].val)
    {
      temp[tmp_pos] = numbers[left];
      tmp_pos = tmp_pos + 1;
      left = left +1;
    }
    else
    {
      temp[tmp_pos] = numbers[mid];
      tmp_pos = tmp_pos + 1;
      mid = mid + 1;
    }
  }
 
  while (left <= left_end)
  {
    temp[tmp_pos] = numbers[left];
    left = left + 1;
    tmp_pos = tmp_pos + 1;
  }
  while (mid <= right)
  {
    temp[tmp_pos] = numbers[mid];
    mid = mid + 1;
    tmp_pos = tmp_pos + 1;
  }
 
  for (i=0; i <= num_elements; i++)
  {
    numbers[right] = temp[right];
    right = right - 1;
  }
}
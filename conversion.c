#include <stdlib.h>
#include "conversion.h"


int s2i(char** string) {
    return (int) strtol(string, (char **)NULL, 10);
}

int bin2ring(int** string) {
    return 0;
}
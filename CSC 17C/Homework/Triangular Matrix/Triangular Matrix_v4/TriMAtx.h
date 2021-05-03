#ifndef TRIMATX_H
#define TRIMATX_H

struct TriMatx
{
    int size;
    int *col;
    int *indx;
    int **data;
};

#endif /* TRIMATX_H */


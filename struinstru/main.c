#include <stdio.h>

typedef struct outer
{
    int id;

    struct inter
    {
        int count;
    } inter;
    

} outer;

void printStruct(outer out) {
    printf("out.id:%d\n", out.id); 
    printf("out.count:%d\n", out.inter.count); 
}

int main() {
    outer out;
    out.id = 1;
    out.inter.count = 1;
    printStruct(out);
    return 0;
}


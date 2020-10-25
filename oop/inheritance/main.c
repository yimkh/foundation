#include <stdio.h>

typedef struct parent {
    int a;
} parent;

typedef struct son {
    parent p;
    int b;
} son;

int main() {
    son s;
    s.p.a = 1;
    s.b = 2;
    
    /*error
    parent *p = &s;
    printf("&d", p->a);
    */

   parent *p = (parent *)&s;

   printf("%d\n", p->a);

   return 0;
}
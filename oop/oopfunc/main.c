#include <stdio.h>

typedef struct parent {
    int a;
    struct parent_ops *ops;
} parent;

typedef struct parent_ops {
    void (*read)(parent* p);
    void (*write)(parent* p);
} parent_ops;

void read(parent* p){
    printf("read\n");
};

void write(parent* p){
    printf("write\n");
}

int main() 
{
    parent p;

    p.a = 1;
    p.ops = &(parent_ops){read, write};

    p.ops->read(&p);
    p.ops->write(&p);

    return 0;
}
#include <stdio.h>

typedef struct parent{
    struct parent_ops *ops;
} parent;

typedef struct parent_ops {
    void (*read)(parent* p);
    void (*write)(parent* p);
} parent_ops;

typedef struct child{
    parent c_p;
} child;

void read(parent* p){
    printf("read\n");
};

void write(parent* p){
    printf("write\n");
}

void cwrite(parent* p){
    printf("cwrite\n");
}

int main() 
{
    parent p;
    p.ops = &(parent_ops){read, write};

    child c;
    c.c_p.ops = &(parent_ops){read, cwrite};

    p.ops->read(&p);
    c.c_p.ops->write((parent *)&c);

    return 0;
}
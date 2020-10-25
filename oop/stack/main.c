#include <stdio.h>

typedef struct parent{
    struct parent_ops *ops;
} parent;

typedef struct parent_ops{
    void (*read)(parent* p);
} parent_ops;

typedef struct child{
    parent parent_child;
} child;

void read(parent* p){
    printf("read\n");
}

int main() {
    parent p;
    p.ops = &(parent_ops){read};
    //not use
    // p.ops->read = read;

    printf("parent:");
    p.ops->read(&p);

    child c;
    c.parent_child.ops = &(struct parent_ops){read};

    printf("child:");
    c.parent_child.ops->read((parent *)&c);

    return 0;
}
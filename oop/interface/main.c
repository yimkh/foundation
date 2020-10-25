#include <stdio.h>

typedef struct parent{
    struct parent_ops *ops;
} parent;

typedef struct parent_ops{
    void (*read)(parent* p);
} parent_ops;

struct parent_ops* as_interface(parent* p){
    return p->ops;
}

void read(parent* p){
    printf("read\n");
}

void call_interface(parent_ops *p_ops, parent *p){
    p_ops = &(parent_ops){read};
    p_ops->read(p);
}

typedef struct child{
    struct child_ops *ops;
} child;

typedef struct child_ops{
    void (*read)(child* c);
    void (*write)(child* c);
} child_ops;

int main(){
    parent p;
    call_interface(as_interface(&p), &p);

    child c;
    call_interface(as_interface((parent *)&c), (parent *)&c);

    return 0;
}
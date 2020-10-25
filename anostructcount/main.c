#include <stdio.h>

typedef struct 
{
    int id;
} anoa;

typedef struct 
{
    int id;
} anob;

typedef struct 
{
    int id;
} anoc;

int main() {
    anoa strua;
    strua.id = 1;
    anob strub;
    strub.id = 2;
    anoc struc;
    struc.id = 3;

    printf("strua.id:%d\n", strua.id);
    printf("strub.id:%d\n", strub.id);
    printf("struc.id:%d\n", struc.id);

    return 0;
}
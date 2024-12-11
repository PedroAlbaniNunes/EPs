#include "dynvec.h"
#include <stdio.h>

int main()
{


    DynVec *dv1 = dv_create();
    DynVec *dv2 = dv_create();
    dv_insert(dv1, 1);
    dv_insert(dv1, 3);
    dv_insert(dv1, 6);
    dv_insert(dv2, 10);
    dv_insert(dv2, 20);

    dv_union(dv1,dv2);
    dv_intersection(dv1,dv2);

    printf("Union: ");
    dv_print_values(dv_union(dv1,dv2));
    printf("\n");
    printf("Intersection: ");
    dv_print_values(dv_intersection(dv1,dv2));


    dv_free(dv1);
    dv_free(dv2);
    
    return 0;
}
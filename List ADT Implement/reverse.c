#include <stdio.h>
#include "arrayList.h"
// #include "linkedList.h"
#define l &list 



 int main(){
    arrayList list ;
    init(l) ;
    append(1,l);
    append(2 , l);
    append(3 , l);
    append(4 , l);
    append(5,l);
    append(6,l);
    append(7,l);
    print_list(l);

    reverse_fix(1,3,l);
    reverse_fix(0,4,l);
    reverse_fix(0,6,l);
    
    print_list(l);


    


 }
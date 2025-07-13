#include<stdio.h>
#include "linkedList.h"


int check_loop(linkedList * list){
    node* fast =list->head ,* slow= list->head ; 
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next ;
        slow = slow->next ;
        
        if(fast == slow ) return 1 ;
    }
    return 0 ;

}

int main(){
    linkedList l ;
    init(&l);
    append(4, &l);
    append(3, &l);
    append(2, &l);
    append(1, &l);
    append(5, &l);
    l.tail->next  = l.head ;

    if(check_loop(&l))
        printf("Loop there is \n");
    else printf("No loop\n");


}
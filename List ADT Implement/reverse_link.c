#include <stdio.h>
//#include "arrayList.h"
 #include "linkedList.h"
#define l &list 

node *  reverse (node * h){
    //node* temp = head ;
    if(h ->next ==  NULL){
        return h ;
    }
    node* newhead = reverse(h->next);
    h->next->next = h ;
    h->next = NULL ;
    return newhead ;

}

 int main(){
    linkedList list ;
    init(l);
    int imdex = 0 ;
    node* temp = list.head ;
    for(int j= 0 ; 1;){
        if(temp == list.cur){
            imdex = j ;
            break ;
        }
        temp = temp->next ;
    }
    init(l) ;
    append(2,l);
    append(0 , l);
    append(3 , l);
    append(1 , l);
    print_list(l);

   list.head =   reverse(list.head);
   temp = list.head ;
   for(int i = 0 ; i < imdex; i++){
    temp = temp->next ;
   }
   list.cur = temp ;
   print_list(l);


    


 }
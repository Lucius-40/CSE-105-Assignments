#include <stdio.h>
#include <stdlib.h>
#define endl printf("\n")


// typedef struct node node;  

typedef struct node
{
    int element;
    struct node* next;
    struct node* prev;
} node;

typedef struct 
{
    // declare head, tail, cur and other variables you need
    node* head , *tail , *cur ;
} linkedList;

void init(linkedList* list)
{
    // implement initialization
    list->head = NULL ;
    list->tail = NULL ;
    list -> cur = NULL ;
    
    
}

void free_list(linkedList* list)
{
    // implement destruction of list
    node *p = list->head;
    node *temp  ;
    while (p != NULL){
        temp = p->next ;
        free(p);
        p = temp ;

    }
    init(list);
  
}

void print_list(linkedList* list)
{
    // implement list printing
    node * p = list->head ;
    if ( p == NULL){
        printf("[.]\n");
    }
    else {
        printf("[ ");
        while(p != NULL){
            if ( list->cur == p ){
                printf("%d | ", p->element);
            }
            else printf("%d ", p->element);
            
            p = p->next ;
            

        }
        printf("]");endl ;endl ;
    }
}

void insert(int item, linkedList* list)
{
    // implement insert function
    node* p =(node*) malloc(sizeof(node));
    if( p == NULL) return ;
    p->element = item ;
    p->next = NULL ;
    p->prev = NULL ;
    if ( list-> head == NULL ){
        list->head =  p ;
        list->cur = p ;
        list->tail = p ;
    }
   else  if (list->cur == list ->head){
    p-> prev = list->head ;
    p->next = list->head->next ;
    list->head->next = p ;
    list-> cur = p ;
    if(p ->next == NULL ) list->tail = p ;
   }
   else if (list->cur == list ->tail){
    p->prev = list->tail ;
    p->next = NULL ;
    list->tail = p ;
    list->cur->next = p ;
    list->cur = p ;

   }
   else {
    p-> next = list->cur->next ;
    p-> prev = list->cur ;
    list->cur->next ->prev = p ;
    list->cur->next = p ;
    list->cur = p ;
   }
 
 
}

int delete_cur(linkedList* list)
{
    // implement deletion of current index function

    if (list->cur == NULL) {
        printf("Nothing to delete \n");
        return -1 ;
    } 
    else {
    node* p = list->cur ;int t = p->element ;
    if (list->head == NULL) return -1 ;
    if ( list-> cur == list-> head ){
        
        if( p->next == NULL){
            
            free(p);
            init(list);
            return t ;
        }
        list-> head = p->next ;
        list->head-> prev = NULL ;
        list ->cur = list->head ;
        free(p);
        return t ;

    }
    else if (list-> cur == list->tail){
        
        list-> tail = p->prev ;
        list->tail->next = NULL ;
        list->cur = list->tail ;
        
        free(p);
        return t ;
    }
    else {
        p->next->prev =p->prev;
        p->prev->next = p->next ;
        list->cur = p->prev ;
        free(p);
        return t ;

    }
}
    
}

void append(int item, linkedList* list)
{
    // implement append function
    node *p = (node*)malloc(sizeof(node));
    if( p == NULL )return ;
    p->element = item ;p->next = NULL ; p->prev= NULL ;
    if ( list->head == NULL){
        list->head = p ;
        list->cur = p ;
    }
    else {
        p->prev = list->tail;
        list->tail->next = p ;
       
    }
    list->tail = p ;

}

int size(linkedList* list)
{
    // implement size function
    if ( list->head == NULL) return 0 ;
    else {
        node* p = list->head ;
        int count = 0 ;
        while ( p != NULL){
            count ++ ;
            p = p->next ;
        }
        return count ;
    }
  
}

void prev(int n, linkedList* list)
{
    // implement prev function
    node* p = list->cur ;
    if ( p == NULL) return ;
    for ( int i= 0 ; i < n ; i++){
        if (p == list ->head  ) {list -> cur = list->head  ; return ;}
        p = p->prev ;
    }
    list ->cur = p ;

}

void next(int n, linkedList* list)
{
    // implement next function
    node * p = list-> cur ;
    if ( p == NULL) return ;
    for ( int i= 0 ; i < n ; i++){
        if ( p == list->tail ){list ->cur = list-> tail ; return ;}
        p = p->next ;
    }
    list -> cur = p ;


}

int is_present(int n, linkedList* list)
{
    // implement presence checking function
    node * p = list->head ;
    while (p != NULL){
        if( p-> element == n) return 1 ;
        p = p->next ;
    }
    return 0 ;

}

void clear(linkedList* list)
{
    // implement list clearing function
    free_list(list) ;
    init(list) ;
}

void delete_item(int item, linkedList* list)
{
    // implement item deletion function
    node* p = list -> head ;
    if ( p == NULL) return ;
    while ( p != NULL){
        if ( p -> element == item ){
            if ( p == list ->head ){
                if( list->head->next == NULL){free(p); init(list); return ;}
                list->head = p->next ;
                list->head->prev= NULL ;
                if ( list-> cur == p){list -> cur = list->head;}
                free (p);
                return ;

            }
            if(p == list->tail){
                list->tail = p->prev ;
                list->tail->next = NULL ;
                if ( list->cur == p)list ->cur = list->tail ;
                free(p);
                return ;
            }
            p->prev->next = p->next ;
            p->next->prev = p-> prev ;
            if( list->cur == p) list->cur = p->next ;
            free(p);
            return ;
        }
        p = p->next ;
    }
    printf("%d not Found \n ", item);
    
}

void swap_ind(int ind1, int ind2, linkedList* list)
{
    // implement swap function
    int len = size(list), j;
    if ( ind1 >= len || ind2 >= len || ind1 < 0 || ind2 < 0) printf("Not Valid \n");
    else {
        node * temp1= list->head , * temp2 = list->head, *t ;
        for ( int i=0 ; i < ind1; i++){
            temp1 =  temp1->next ;
        }
        for ( int i=0 ; i < ind2; i++){
            temp2 =  temp2->next ;
        }
     

        j = temp1-> element ;
        temp1->element = temp2->element ;
        temp2->element = j ;


    }

}


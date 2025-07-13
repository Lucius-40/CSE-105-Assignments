#include <stdio.h>
#include <stdlib.h>

#define endl printf("\n")

typedef struct
{
    int *array;
    // declare variables you need
    int length;
    int max_length;
    int curr;
} arrayList;

void init(arrayList *list)
{
    list->array = (int *)calloc(2, sizeof(int));
    if (list->array == NULL)
        printf("Allocation Failed \n");
    else
    {
        list->max_length = 2;
        list->length = 0;
        list->curr = -1;
    }
}

void free_list(arrayList *list)
{
    // implement destruction of list
    free(list->array);
}

void increase_capacity(arrayList *list)
{
   
    int len = list->max_length ;
    int * p = (int*)calloc(sizeof(int), (2*len));
    if ( p == NULL){printf("Allocation failed\n"); return ;}
    for ( int i=0 ; i < list->length; i++ ){
        *(p+i)= *(list->array + i );
    }
    free(list->array);
    list->array = p ;
    list->max_length = 2 *len ;
    printf("Size increased from %d to %d \n",len , 2*len);
    
}

void decrease_capacity(arrayList *list)
{
    
    int len = list->max_length ;
    int * p = (int*)calloc(sizeof(int), (len/2));
    if ( p == NULL){printf("Allocation failed\n"); return ;}
    for ( int i=0 ; i < list->length; i++ ){
        *(p+i)= *(list->array + i );
    }
    free(list->array);
    list->array = p ;
    list->max_length = len/2 ;
    printf("Size decreased from %d to %d \n",len , len/2);
    

}

void print(arrayList *list)
{
    // implement list printing
    for (int i = 0; i < list->length; i++)
    {
        printf("%d ", *(list->array + i));
    }
    endl;
}

void insert(int item, arrayList *list)
{
    // implement insert function
    //debug : 
    
    if (list->length >= list->max_length / 2)
        increase_capacity(list);



    for (int i = list->length - 1; i > list->curr; i--)
        *(list->array + i + 1) = *(list->array + i);
    

    *(list->array + list->curr + 1) = item;
    list->length++;
    list->curr++;
    //printf("Inserted %d");
   // printf ("Curr : %d \n", list->curr);
}

int delete_cur(arrayList *list)
{
    // implement deletion of current index function
    int del ;
    if (list->length <= list->max_length / 4 && list->length != 0)
        decrease_capacity(list);
    if (list->curr == -1 || list->length == 0)
        printf("No element to delete\n");
    else
    {
        del = *(list->array + list->curr) ;
        for (int i = list->curr; i < list->length - 1; i++)
        {
            *(list->array + i) = *(list->array + 1 + i);
        }
        list->length--;
        if (list->curr >= list->length)
            list->curr--;
    }
    //printf ("Curr : %d \n", list->curr);
    return del;
}

void append(int item, arrayList *list)
{
    // implement append function
    if( list-> curr == -1)
        list->curr = 0 ;
    if (list->length >= list->max_length / 2)
        increase_capacity(list);
    *(list->array + list->length) = item;
    list->length++;

    //printf ("Curr : %d \n", list->curr);
}

int size(arrayList *list)
{
    // implement size function
    return list->length;
}

void prev(int n, arrayList *list)
{
    // implement prev function
    if (list->curr - n < 0)
        list->curr = 0;
    else
    {
        list->curr = list->curr - n;
    }

   // printf ("Curr : %d \n", list->curr);
}

void next(int n, arrayList *list)
{
    // implement next function
    if (list->curr + n >= list->length)
        list->curr = list->length - 1;
    else
        list->curr = list->curr + n;

      //  printf ("Curr : %d \n", list->curr);
}

int is_present(int n, arrayList *list)
{
    // implement presence checking function
    int flag = 0;
    for (int i = 0; i < list->length; i++)
    {
        if (*(list->array + i) == n)
        {
            flag = 1;
           
            break;
        }
    }
    if (flag)
        return 1;
    else{
      
        return 0;
    }
}

void clear(arrayList *list)
{
    // implement list clearing function
    
    list->curr = -1;
    list->length = 0;
    list->max_length = 2;
    free(list->array);
    int * p = (int*)calloc(2,sizeof(int));
    list->array = p ;
    if (list->array == NULL)
    {
        printf("Realloc Failed ");
        endl;
    }
}

void delete_item(int item, arrayList *list)
{
    // implement item deletion function
    int flag = -1;
    for (int i = 0; i < list->length; i++)
    {
        if (*(list->array + i) == item)
            flag = i;
    }
    if (flag == -1)
        printf("Item does not exist \n");
    else
    {
        if (list->length <= list->max_length / 4 && list->length != 0)
            decrease_capacity(list);

        for (int i = flag; i < list->length - 1; i++)
        {
            *(list->array + i) = *(list->array + 1 + i);
        }
        list->length--;
        if ( list->curr >= list->length )
            list->curr -- ;
    }
    //printf ("Curr : %d \n", list->curr);
}

void swap_ind(int ind1, int ind2, arrayList *list)
{
    // implement swap function
    if (ind1 < 0 || ind2 < 0 || ind1 >= list->length || ind2 >= list->length)
    {
        printf("Invalid Imput ");
        endl;
    }
    else
    {
        int temp = *(list->array + ind1);
        *(list->array + ind1) = *(list->array + ind2);
        *(list->array + ind2) = temp;
    }
   // printf ("Curr : %d \n", list->curr);
}

// you can define helper functions you need
void print_list(arrayList* l){
    if (l->length == 0){
        printf("[.]\n");

    }
    else {
    printf("[ ");
    for ( int i= 0 ; i < l->length ; i++){
        if ( i == l->curr){
            printf("%d | ",*(l->array + i));
        }
        else 
        printf("%d ", *(l->array + i));
    }
    printf("]");
        endl; endl ;
}
}

void reverse_fix(int ind1, int ind2,arrayList* list){
    int n = ind2 - ind1 ;
    while(ind1 < ind2){
        swap_ind(ind1,ind2, list);
         ind1++ ;
         ind2 -- ;
    }
}
#include <stdio.h>
//#include "arrayList.h"
 #include "linkedList.h"

int main()
{
    FILE* file = fopen("in.txt", "r");
    if(file == NULL){
        printf("abcd");
        return 1;
    }

   //arrayList list;
   linkedList list;
    init(&list);

    int func, param, param2;
     while(fscanf(file, "%d", &func) == 1 && func != 0)
    {
        if(func == 1 && fscanf(file, "%d", &param) == 1){
            printf("Insert %d\n", param);
            insert(param, &list);
            print_list(&list);
        }
        else if(func == 2){
            printf("Delete current item\n");
            int ret = delete_cur(&list);
            print_list(&list);
            printf("%d is deleted\n", ret);
        }
        else if(func == 3 && fscanf(file, "%d", &param) == 1){
            printf("Append %d\n", param);
            append(param, &list);
            print_list(&list);
            
        }
        else if(func == 4){
            int ret = size(&list);
            printf("Size of the list is %d\n", ret);
        }
        else if(func == 5 && fscanf(file, "%d", &param) == 1){
            printf("Prev %d\n", param);
            prev(param, &list);
           print_list(&list);
        }
        else if(func == 6 && fscanf(file, "%d", &param) == 1){
            printf("Next %d\n", param);
            next(param, &list);
           print_list(&list);
        }
        else if(func == 7 && fscanf(file, "%d", &param) == 1){
            int ret = is_present(param, &list);
            if(ret){
                printf("%d is present\n", param);
            }
            else{
                printf("%d is not present\n", param);
            }
        }
        else if(func == 8){
            printf("Clear list\n");
            clear(&list);
           print_list(&list);
        }

        else if(func == 9 && fscanf(file, "%d", &param) == 1){
            printf("Delete %d\n", param);
            delete_item(param, &list);
            print_list(&list);
        }
        else if(func == 10 && fscanf(file, "%d %d", &param, &param2) == 2){
            printf("Swap index %d and %d\n", param, param2);
            swap_ind(param, param2, &list);
         print_list(&list);
            
        }
       // printf("\n");
    }

    free_list(&list);
    return 0;
}

/*

1 1
1 2
1 3
1 4 
1 5
1 6
5 2
1 0
2
9 5
9 3
9 100
2
2
2
2
3 7
3 8
3 9
3 10
4
7 8
7 11
3 11
10 1 3
6 10
5 3
8
1 12
*/

/*
1 1
1 2
1 3
1 4 
1 5
1 6
5 2
1 0
2
9 5
9 3
9 100
2
2
2
2
3 7
3 8
3 9
3 10
4
7 8
7 11
3 11
10 1 3
6 10
5 3
8
1 12
2
2
2
2
2
2
1 34
*/
/*
1 1
1 2
1 3
1 4 
1 5
1 6
5 2
1 0
2
9 5
9 3
9 100
2
2
2
2
3 7
3 8
3 9
3 10
4
7 8
7 11
3 11
10 1 3
6 10
5 3
8
1 12
2
2
2
2
2
2
1 34
*/
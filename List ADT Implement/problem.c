#include <stdio.h>
//#include "arrayList.h"
 #include "linkedList.h"

int main()
{
    FILE* file = fopen("in_prob.txt", "r");
    if(file == NULL){
        return 1;
    }

    //arrayList dal, fl;
     linkedList dal, fl;
    
    // initialize the lists
    init(&dal); init(&fl);

    int func, param;
    while(fscanf(file, "%d", &func) == 1 && func != 0)
    {
        if(func == 1 && fscanf(file, "%d", &param) == 1){
            printf("Recruit %d\n", param);
            // implement logic here
            int trus = is_present(param, &fl);
            if(trus)printf("Is a foe, cannot recruit \n");
            else{
                append(param, &dal);
                printf("DA List : \n");
                print_list(&dal);
            }
        }
        else if(func == 2 && fscanf(file, "%d", &param) == 1){
            printf("Fire %d\n", param);
            // implement logic here
            int trus = is_present(param, &dal);
            if(trus){
                delete_item(param, &dal);
                printf("DA List : \n");
                print_list(&dal);
                append(param, &fl);
                printf("Foe List : \n");
                print_list(&fl);
            }
        }
        else if(func == 3 && fscanf(file, "%d", &param) == 1){
            printf("Check %d\n", param);
            //implement logic here
            int d = is_present(param, &dal);
            int f = is_present(param, &fl);
            if(d)printf("Friend\n");
            else if (f)printf("Foe \n");
            else printf("Unknown\n");
        }
        else{
            free_list(&dal);
            free_list(&fl);
            break;
        }
        printf("\n");
    }
   
    // free memory
    
    return 0;
}
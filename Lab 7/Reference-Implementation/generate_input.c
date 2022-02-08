#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv){
    FILE *fptr;
    fptr = fopen("input.txt","w");
    if(fptr == NULL){
        printf("Error!");
        exit(1);
    }

    int no_values = atoi(*(argv+1)), count = 2;

    for(int i = 0; i < no_values; i++){
        fprintf(fptr, "photon%d\n", count);
        count += rand() % 10;
    }

    fclose(fptr);
}
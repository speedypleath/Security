#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    FILE *fptr;
    char *line = NULL, *str;
    size_t len, error;
    fptr = fopen("output.txt","r");
    if(fptr == NULL){
        printf("Error!");
        exit(1);
    }
    char *test[11] = {"6c2bf8cad416a071d11e", "9cdcc99b9e68cbb273d5", "22a5a77ccc941ea042cf", "8e0368802e8a1d1f4c82", "f41198894e0d8b74a0e8", "a62e7dea24ac2eb9fee6", "5d06b6668377b1f656a1", "ee7276c10429a02deda9", "eb64cbee5d53640eafc9", "03ac754af5f6e6072798", "f9d99e0b5fcb2083a6b9"};
    int collisions = 0, count = 0;

    while ((line = fgetln(fptr, &len)) != NULL) {
        str = (char *)malloc(len * sizeof(char));
        str = strncpy(str, line, len);
        for(int i = 0; i < 11; i++) 
            if(strcmp(&str[len-20], test[i]) == 0) 
                collisions++;
        count++;
	}

    printf("Number of inputs: %d\n", count);
    printf("Number of collision: %d\n", collisions);
    return 0;
}

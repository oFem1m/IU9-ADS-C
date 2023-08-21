#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){
    if (argc < 4){
        printf("Usage: frame <height> <width> <text>");
        return 0;
    }
    int height = atoi(argv[1]), width = atoi(argv[2]);
    char text[1000];
    strcpy(text, argv[3]);
    int len_str = strlen(text);
    if ((height < 3) || ((width - 2) < len_str)){
        printf("Error");
        return 0;
    }
    for (int i = 0; i < height; i++){
        if ((i == 0) || (i == (height - 1))){
            for (int k = 0; k < width; k++) printf("*");
            printf("\n");
        }else if (i == ((height - 1) / 2)){
            printf("*");
            for (int k = 0; k < ((width - 2 - len_str) / 2); k++)
                printf(" ");
            printf("%s", text);
            if ((width - 2 - len_str) % 2 == 1)
                for (int k = 0; k < ((width - len_str) / 2); k++)
                    printf(" ");
            else
                for (int k = 0; k < ((width - 2 - len_str) / 2); k++)
                    printf(" ");
            printf("*\n");
        }else{
            printf("*");
            for (int k = 0; k < (width - 2); k++) printf(" ");
            printf("*\n");
        }
    }
    return 0;
}
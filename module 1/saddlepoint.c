#include <stdio.h>
#include <math.h>


int main(int argc, char **argv){
    long long Array[10][10], min_in_column[10][2], max_in_line[10][2];
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++){
        min_in_column[i][0] = -1;
        min_in_column[i][1] = 9223372036854775807;
    }
    for (int i = 0; i < n; i++){
        max_in_line[i][0] = -1;
        max_in_line[i][1] = -9223372036854775807;
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            scanf("%lld", &Array[i][j]);
            if (Array[i][j] > max_in_line[i][1]){
                max_in_line[i][0] = j;
                max_in_line[i][1] = Array[i][j];
            }
            if (i == 0){
                min_in_column[j][0] = 0;
                min_in_column[j][1] = Array[i][j];
            }else{
                if (Array[i][j] < min_in_column[j][1]){
                    min_in_column[j][0] = i;
                    min_in_column[j][1] = Array[i][j];
                }
            }
        }
    }

    int check_saddle = 0;
    for (int i = 0; i < n; i++){
        if (max_in_line[i][1] == min_in_column[max_in_line[i][0]][1]){
            check_saddle = 1;
            printf("%d %lld", i, max_in_line[i][0]);
            break;
        }
    }
    if (check_saddle == 0)
        printf("none");

    return 0;
}
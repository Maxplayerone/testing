#include<stdio.h>
#include<stdlib.h>

int CheckAbsolute(int a, int b){
    if(a < 0){
        a = a * -1;
    }
    if(b < 0){
        b = b * -1;
    }
    if(a > b) return 1;
    else return -1;
    
}

void Sort(int array[], int size, int (*isAbs)(int, int)){
    for(int i=0; i < size; i++){
        for(int j=0; j < size; j++){
                if(isAbs(array[j], array[j + 1]) > 0){
                    int temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
        }
    }
}

int main(){
    int list[] = {-3, -1934, 2, 1204, -102, 0};
    int (*Absolute)(int, int);
    Absolute = CheckAbsolute;
    printf("The sorted thingy looks like this: \n");
    int size = sizeof(list)/sizeof(list[0]);
    Sort(list, size, Absolute);
    for(int i = 0; i < size; i++){
        printf("%d\n", list[i]);
    }

    return 0;
}
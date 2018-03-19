//
// Created by Bartek on 06.03.2018.
//

#include "Array2D.h"

int **Array2D(int n_rows, int n_columns){
    int ** array = new int * [n_columns];
    for (int i=0;i<n_columns;i++){
        array[i] = new int[n_rows];
    }
    return array;
}

void DeleteArray2D(int **array, int n_rows, int n_columns){
    for (int i=0;i<n_columns;i++){
        delete [] array[i];
        delete array;
    }
}

void FillArray(int **array, int n_rows, int n_columns){
    int number=1;
    for (int i=0;i<n_columns;i++){
        for(int j=0;j<n_rows;j++){
            *(*(array+i)+j)=number;
            number++;
        }
    }
}
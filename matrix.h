#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

struct matrix {
    int *data;
    int n_rows;
    int n_cols;
    int stride_rows;
    int stride_cols;
    int offset;
} m, array, a_matrix;

struct matrix create_matrix(int *data, int n_rows, int n_cols) {

    struct matrix array;
    int x = 0;
    int data_matrix[n_rows][n_cols];

    for (int i=0; i < n_rows; i++) {
        for (int j=0; j < n_cols; j++) {
            data_matrix[i][j] = data[x];
            x++;
        }
    }
    array.data = *data_matrix;
    array.stride_rows = n_cols;
    array.stride_cols = 1;
    array.offset = 0;

    return array;
}

void print_matrix(struct matrix a_matrix) { 
    
    int x = 0;

    for (int i=0; i<a_matrix.n_rows; i++) {
        printf("|");
        for (int j=0; j<a_matrix.n_cols; j++) {
            printf(" %d ", a_matrix.data[x]);
            x++;
        }
        printf("|\n");
    }
}

struct matrix zeros_matrix(int n_rows, int n_cols) {
    
    struct matrix array; 
    int data_matrix[n_rows][n_cols];

    for (int i=0; i < n_rows; i++) {
        for (int j=0; j < n_cols; j++) {
            data_matrix[i][j] = 0;
        }
    }
    array.data = *data_matrix;
    array.n_rows = n_rows;
    array.n_cols = n_cols;
    array.stride_rows = n_cols;
    array.stride_cols = 1;
    array.offset = 0;

    return array;
}

struct matrix random_matrix(int n_rows, int n_cols, int b, int e) {

    srand(time(NULL));
    int x = e - b;

    struct matrix array; 
    int data_matrix[n_rows][n_cols];

    for (int i=0; i < n_rows; i++) {
        for (int j=0; j < n_cols; j++) {
            int num = rand() % x + b;
            data_matrix[i][j] = num;
        }
    }
    array.data = *data_matrix;
    array.n_rows = n_rows;
    array.n_cols = n_cols;
    array.stride_rows = n_cols;
    array.stride_cols = 1;
    array.offset = 0;

    return array;
}

struct matrix i_matrix(int n) {

    struct matrix array;
    int data_matrix[n][n];

	for(int i=0; i < n; i++){
		for (int j=0; j < n; j++){
			if(i==j){
				data_matrix[i][j] = 1;
			} else {
				data_matrix[i][j] = 0;
			}
		}
	}
    array.data = *data_matrix;
    array.n_rows = n;
    array.n_cols = n;
    array.stride_rows = n;
    array.stride_cols = 1;
    array.offset = 0;

    return array;
}

int get_element(struct matrix a_matrix, int ri, int ci) {
    
    int x = a_matrix.data[ri][ci];

    return x;
}

void put_element(struct matrix a_matrix, int ri, int ci, int elem) {
    a_matrix.data[ri][ci] = elem;
}

int sum(struct matrix a_matrix) {
    int sum = 0;
    
    for (int i=0; i<a_matrix.n_rows; i++) {
        for (int j=0; j<a_matrix.n_cols; j++) {
            sum += a_matrix.data[i][j];
        }
    }
    return sum;
}

int mean(struct matrix a_matrix) {
 
    for (int i=0; i<a_matrix.n_rows; i++) {
        for (int j=0; j<a_matrix.n_cols; j++) {
            sum += a_matrix.data[i][j];
        }
    }
}
#include <stdio.h>
#include <stdlib.h>

void print1DimArr(int ar[], int n) {
	for(int i = 0; i < n; i++ ) {
		printf("\nPhan tu ar[%d] = %d", i, ar[i]);
	}
	
} 

int print2DimArrA(int ar[][3], int m){
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < 3; j++) {
            printf("\n%d\t", &ar[i][j]);
        }
        printf("\n");
    }
} 

int print2DimArrB(int ar[][3], int m){
    int i, j;
    for (i = 0; i < m; i++) {
        print1DimArr( ar[i] , 3);
        printf("\n");
    }
} 

int main(){
	int A1[3][3] = {{1,2,3}, {2,3,4}, {3,4,5}};
    
    printf("print1DimArr\n");
    print1DimArr(A1[1],3);
    
    printf("\nprint2DimArrA\n");
    print2DimArrA(A1,3);
    
    printf("print2DimArrB\n");
    print2DimArrB(A1,3);
    
    return 0;

}
    
    

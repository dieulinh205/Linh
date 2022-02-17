#include <stdio.h>
#include <stdlib.h>

void print1DimArr(int* ar , int n) {
	int i;
	for(i = 0; i < n; i++){
		printf("%d",*(ar + i) );
	}
} 

int print2DimA(int* ar , int m, int n){
    int i, j;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
        	printf("%d\t",*( ar+ i*m + j) );
        }
        printf("\n");
    }
} 

int print2DimB(int* ar , int m, int n){
    int i, j;
    for (i = 0; i < m; i++) {
        print1Dim( ar + i*m, n);
        printf("\n");
    }
}

int main(void){
	int A1[3][3] = {{1,2,3}, {2,3,4}, {3,4,5}};
	
    printf("print1DimArr\n");
    print1DimArr(A1[1],3);
    
    printf("print2DimA");
    print2DimA(&A1[1][1],3,3);
    
    printf("print2DimB");
    print2DimB(A1,3,3);
    
    return 0;

}
   

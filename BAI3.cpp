//BÀI 3
#include <stdio.h>
#include <stdlib.h>
int main(void) {
 int i;
 int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
 printf("\nDUYET MANG: LIET KE GIA TRI CAC PHAN TU\n");
 for (i = 0 ; i < 12 ; i++ )
 printf("Thang %d co %d ngay\n", i + 1, days[i]);
} 

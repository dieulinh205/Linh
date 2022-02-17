#include <stdio.h>
#include <stdlib.h>

//  Bai 1
//int main(void)
//{
/*
    int h[4] = {4, 5, 6};
    printf("Gia tri cua h[0]=%d\n", h[0]);
    printf("Gia tri cua h[4]=%d\n", h[3]);
    printf("Dia chi cua h[0]=%p\n", h);     // Cach 1
    printf("Dia chi cua h[0]=%p\n", &h[0]); // Cach 2
    printf("Dia chi cua h[1]=%p\n", h + 1); // Cach 1
    printf("Dia chi cua h[1]=%p\n", &h[1]); // Cach 2
    printf("Gia tri cua h[1]=%d\n", h[1]);  // Cach 1
    printf("Gia tri cua h[1]=%d\n", h[1]);  // Cach 2
    return 0;
}
*/

// Bai 2
/*
#define MTHS 12
int main(void)
{
    int days[MTHS] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days2[MTHS] = {31, 28, 31, 30, 31, 30, 31};
    int days3[] = {31, 28, 31, 30, 31, 30, 31};
    printf("So luong phan tu cua days: %d\n", MTHS);
    printf("So luong phan tu cua days2: %d\n", MTHS);
    printf("So luong phan tu cua days3: %d\n", sizeof(days3) / sizeof(days3[0]));
    printf("Gia tri cua phan tu days2[7]: %d\n", days2[7]);
    printf("Gia tri cua phan tu days3[7]: %d\n", days3[7]);
    return 0;
}
*/
// Bai 3
/*
#define MTHS 12
int main(void)
{
    int i;
    int days[MTHS] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    printf("\nDUYET MANG: LIET KE GIA TRI CAC PHAN TU\n");
    for (i = 0; i < MTHS; i++)
        printf("Thang %d co %d ngay\n", i, days[i]);
}
*/

#include <stdio.h>
#include <stdlib.h>

// Bài 4
/*
#define SIZE 5
void ex4Search()
{
    int i;
    printf("\nDUYET MANG: TIM KIEM GIA TRI\n");
    char myChar[SIZE] = {'b', 'a', 'c', 'k', 's'};
    char searchChar;
    printf("Nhap vao ki tu can tim kiem: ");
    scanf("%c", &searchChar);

    for (i = 0; i < SIZE; i++)
    {
        if (myChar[i] == searchChar)
        {
            printf("Tim thay ki tu %c tai vi tri %d\n", myChar[i], i);
            break;
        }
    }
}
*/

//  Bài 5
/*
int ex5FindMax1()
 {
     int i;
     printf("\nDUYET MANG: TIM GIA TRI LON NHAT\n");
     int index, max, numArray[10];
     max = -1;
     printf("Nhap 10 gia tri so vao mang numArray: \n");
     for (index = 0; index < 10; index++)
     {
         scanf("%d", &numArray[index]);
     }
     for (index = 0; index < 10; index++)
     {
         if (numArray[index] > max)
             max = numArray[index];
     }
     printf("Gia tri lon nhat la %d.\n", max);
 }
 */

// Bài 6
int ex5FindMax2()
{
    int i;
    printf("\nDUYET MANG: TIM GIA TRI LON NHAT\n");
    int index, imax, numArray[10];
    imax = 0;
    printf("Nhap 10 gia tri so vao mang numArray: \n");
    for (index = 0; index < 10; index++)
    {
        scanf("%d", &numArray[index]);
    }
    for (index = 1; index < 10; index++)
    {
        if (numArray[index] > numArray[imax])
            imax = index;
    }
    printf("Gia tri lon nhat la %d.\n", numArray[imax]);
}

int main()
{
    // ex4Search();
    // ex5FindMax1();
    ex5FindMax2();
    return 0;
}

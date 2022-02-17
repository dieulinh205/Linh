#include<stdio.h>
#include<stdlib.h>

void selection_sort1(int k[], int n)
{
    int i, j, m, x;
    for (i = 0; i < n; i++)
    {
        m = i;
        for (j = i + 1; j < n; j++)
        {
            if (k[j] < k[m])
                m = j;
        }

        if (m != i)
        {
            // Thêm mã chuong trình d? d?i ch? k[i] và k[m]
            x = k[i];
            k[i] = k[m];
            k[m] = x;                                           
        }
    }
}

void selection_sort2(int k[], int n)
{
    int i, j, m, x;
    for (i = 0; i < n; i++)
    {
        m = i;
        for (j = i + 1; j < n; j++)
        {
            if (k[j] > k[m])
                m = j;
        }

        if (m != i)
        {
            // Thêm mã chuong trình d? d?i ch? k[i] và k[m]
            x = k[i];
            k[i] = k[m];
            k[m] = x;                                           
        }
    }
}

void insert_sort1(int k[], int n)
{
    int i, j, x;
    for (i = 1; i < n; i++)
    {
        x = k[i];
        j = i - 1;
        while (x < k[j] && j >= 0)
        {
            k[j + 1] = k[j];
            j = j - 1;
        }
        k[j + 1] = x;
    }
}

void insert_sort2(int k[], int n)
{
    int i, j, x;
    for (i = 1; i < n; i++)
    {
        x = k[i];
        j = i - 1;
        while (x > k[j] && j >= 0)
        {
            k[j + 1] = k[j];
            j = j - 1;
        }
        k[j + 1] = x;
    }
}


void bubble_sort1(int k[], int n)
{
    int i, j, x;
    for (i = 0; i < n - 1; i++)
    {
        for (j = n - 1; j > i; j--)
        {
            if (k[j] < k[j - 1])
            {
                // Thêm mã chuong trình d? d?i ch? k[j] và k[j-1];
                x = k[j];
                k[j] = k[j - 1];
                k[j - 1] = x;
            }
        }
    }
}


void bubble_sort2(int k[], int n)
{
    int i, j, x;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 1; j > i; j--)
        {
            if (k[j] < k[j - 1])
            {
                // Thêm mã chuong trình d? d?i ch? k[j] và k[j-1];
                x = k[j];
                k[j] = k[j - 1];
                k[j - 1] = x;
            }
        }
    }
}

void printOut(int k[], int n){
	int i;
    for(i = 0; i<n; i++) {
        printf("%d ", k[i]);
    }
}


int main() {
	int i,n;
	printf("so phan tu can sap xep: ");
	scanf("%d",&n);
	int k[n];
	printf("\nNhap so phan tu cho mang,\n");
	for(i = 0; i < n; i++) {
		printf("k[%d] = ",i+1);
		scanf("%d",&k[i]);
	}
	
	
    //selection_sort1(k, n);
   // insert_sort1(k, n);
    // bubble_sort1(k, n);

    // selection_sort2(k, n);
    // insert_sort2(k, n);
     bubble_sort2(k, n);
		
	printf("\nMang sau khi sap xep:");
	for(i = 0; i<n; i++) {
		printf("%d ",k[i]);
	}
	
	
	
}








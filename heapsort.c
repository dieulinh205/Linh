#include <stdio.h>
#include <math.h>

/* Bug tao ��ng se bo qua phan tu K[0] ~ phan tu �au tien
=> Ta se chi thao t�c voi n - 1 phan tu,
	duyet tu phan tu thu 2 trong mang.
*/
void printArray(int K[], int n)
{
	int i;
	for (i = 1; i < n; i++)
	{
		printf("%d ", K[i]);
	}
}

void ADJUST(int K[], int i, int n) // i l� chi so n�t goc, n l� so n�t cua c�y
{
	int KEY = K[i];
	int j = 2 * i; // j ghi nhan so thu tu N�t Con Tr�i cua i

	while (j <= n)
	{
		if ((j < n) && (K[j] < K[j + 1])) // tim vi tr� n�t con phai (n�t con lon nhat) �e so s�nh voi n�t goc(KEY)
			j = j + 1;

		if (KEY > K[j])
		{
			K[j / 2] = KEY; // khi x�c �inh �uoc v? tr� cua KEY => dung lai
			return;
		}
		K[j / 2] = K[j]; // Neu KEY nho hon kh�a con => �ua kh�a con l�n

		j = 2 * j; // Ti?p t?c �i xuong nh�nh duoi �e tim vi tr� cho KEY, vi KEY c� the nho hin n�t o nh�nh n�y
	}
	K[j / 2] = KEY;
}

void HeapSort(int K[], int n)
{
	int i;
	// Tao �ong
	for (i = n / 2; i >= 1; i--)
	{
		ADJUST(K, i, n);
	}
	for (i = n - 1; i >= 1; i--)
	{
		// �oi cho phan tu �au voi phan tu cuoi
		int tmp = K[1];
		K[1] = K[i + 1];
		K[i + 1] = tmp;

		ADJUST(K, 1, i);
	}
}

int main()
{
	int K[] = {2 ,9 , 3, 6, 1, 4, 5, 7, 0, 8};
	int n = sizeof(K) / sizeof(int); // K�ch thuoc mang

	printf("Mang truoc khi sap xep: ");
	printArray(K, n);

	HeapSort(K, n);

	printf("\nMang sau khi sap xep: ");
	printArray(K, n);
}

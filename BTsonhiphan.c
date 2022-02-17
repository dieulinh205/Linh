#include<stdio.h>
#include<stdlib.h>

//Cho khai b�o ki�u cua m�t n�t trong danh s�ch li�n k�t 
typedef struct _listnode {
    int num;
    struct _listnode *next;
} ListNode;


//Cho khai b�o kieu cua m�t danh sach li�n k�t
typedef struct _linkedlist
{
    ListNode *head;
    ListNode *tail;
    int size;
} LinkedList;


//Cho khai b�o ki�u cua mopt h�ng doi
typedef struct _queue {
    LinkedList ll;
} Queue;


void printList(ListNode *head)
{
    ListNode *cur = head;
    if (cur == NULL){
    	printf("Danh sach lien ket khong co phan tu nao.");
	}
    while (cur != NULL)
    {
        printf("%d", cur->num);
        cur = cur->next;
    }
}


//Tr? v? d?a ch? c?a node th? i trong danh s�ch li�n k?t tr? b?i head. Node d?u ti�n c?a danh s�ch li�n k?t l� node th? 0.
ListNode *findNode(ListNode *head, int i)
{
    ListNode *cur = head;
    if ((head == NULL) || (i < 0))
    {
        printf("\nDanh sach lien ket rong hoac phan tu tim kiem khong ton tai");
        return NULL;
    }
    while (i > 0)
    {
        cur = cur->next;
        i = i - 1;
        if (cur == NULL)
        {
            printf("\nPhan tu tim kiem khong ton tai");
            return NULL;
        }
    }
    return cur;
}


//Ch�n m?t n�t c� gi� tr? value v�o v? tr� index trong danh s�ch li�n k?t tr? b?i *pHead.
void insertNode(ListNode **pHead, int index, int value)
{
    ListNode *cur, *newNode;
    
    if (*pHead == NULL || index == 0) //start by index 0 && list none node
    {
        newNode = (ListNode *)malloc(sizeof(ListNode));
        newNode->num = value;
        newNode->next = NULL;
        *pHead = newNode;
    }
    else if ((cur = findNode(*pHead, index - 1)) != NULL) 
    {
        newNode = (ListNode *)malloc(sizeof(ListNode));
        newNode->num = value;
        newNode->next = cur->next;
        cur->next = newNode;
    }
    else
        printf("\ncan not insert the new item at index %d!\n", index);
}

void removeNode(ListNode **ptrHead, int index)
{
    ListNode *cur, *pre;
    if (index == 0) //the first node will start by 0
    {
        cur = *ptrHead;
        *ptrHead = NULL;
        free(cur);
    }
    else
    {
        pre = findNode(*ptrHead, index - 1);   //take node in front of index of list
        cur = *ptrHead;
        pre->next = cur->next;
        free(cur);
    }
}


//khai b�o c?a c�c h�m th?c hi?n c�c thao t�c tr�n h�ng d?i
void enqueue(Queue *q, int item)
{
    if (q->ll.tail == NULL)
    {
        insertNode(&(q->ll.head), 0, item);
        (q->ll).tail = (q->ll).head;
    }
    else
    {
        (q->ll).tail->next = malloc(sizeof(ListNode));
        (q->ll).tail = ((q->ll).tail)->next;
        (q->ll).tail->num = item;
        (q->ll).tail->next = NULL;
        (q->ll).size++;
    }
}
//L?y m?t ph?n t? ra kh?i h�ng d?i. Gi� tr? tr? v? c?a h�m l� gi� tr? c?a ph?n t? l?y ra.
int dequeue(Queue *q) {
    int item;
    if (q->ll.head!=NULL) {
        item = ((q->ll).head)->num;
        removeNode(&(q->ll).head, 0);
        (q->ll).size--;
        return item;
    }
    else {
    	printf("Hang doi rong.");
    	return 0;
	}
}


//L?y gi� tr? c?a n�t d?u ti�n c?a danh s�ch li�n k?t
int peek(Queue *q){
    if (q->ll.head!=NULL)
        return (q->ll).head->num;
    else {
    	printf("Hang doi rong.");
    	return 0;
	}
}

void chuyen_co_so(int num) {
    Queue *q = malloc(sizeof(Queue));
    q->ll.size = 0;
    q->ll.head = NULL;
    q->ll.tail = NULL;
   
    while (num > 0)
    {
        enqueue(q,num % 2);
        num /= 2;
    }

    printList(q->ll.head);

    printf("\n");
    
}




//Ki?m tra xem s? ph?n t? trong h�ng d?i c� ph?i b?ng 0 kh�ng
int isEmptyQueue(Queue *q){
    if ((q->ll).size == 0) return 1;
    return 0;
}

int main(void) {
	int  i;
	int n;
	printf("Input: ");
    scanf("%d", &n);
    
    
   for( i = 1; i <= n; i++){
        chuyen_co_so(i);
    }

    

}

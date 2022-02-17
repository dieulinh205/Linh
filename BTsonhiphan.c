#include<stdio.h>
#include<stdlib.h>

//Cho khai báo kiêu cua môt nút trong danh sách liên kêt 
typedef struct _listnode {
    int num;
    struct _listnode *next;
} ListNode;


//Cho khai báo kieu cua môt danh sach liên kêt
typedef struct _linkedlist
{
    ListNode *head;
    ListNode *tail;
    int size;
} LinkedList;


//Cho khai báo kiêu cua mopt hàng doi
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


//Tr? v? d?a ch? c?a node th? i trong danh sách liên k?t tr? b?i head. Node d?u tiên c?a danh sách liên k?t là node th? 0.
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


//Chèn m?t nút có giá tr? value vào v? trí index trong danh sách liên k?t tr? b?i *pHead.
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


//khai báo c?a các hàm th?c hi?n các thao tác trên hàng d?i
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
//L?y m?t ph?n t? ra kh?i hàng d?i. Giá tr? tr? v? c?a hàm là giá tr? c?a ph?n t? l?y ra.
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


//L?y giá tr? c?a nút d?u tiên c?a danh sách liên k?t
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




//Ki?m tra xem s? ph?n t? trong hàng d?i có ph?i b?ng 0 không
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

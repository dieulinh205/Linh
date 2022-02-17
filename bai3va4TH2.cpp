#include <stdio.h>
#include <stdlib.h>



#BÀI3
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


#BÀI 4
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


#BÀI 5
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


int main() {
	printf("\n%i ", findNode(head, 1)); //%i - interface 

    insertNode(&node0, 2, 32);
    printList(head);
    free(node0);
    free(node1);
}
	
	
	
	
	
	
	
	
	


#include<stdio.h>
#include<stdlib.h>

typedef struct _btnode {
    int item;
    struct _btnode *left;
    struct _btnode *right;
} BTNode;

//n hàm duy?t cây nh? phân theo thu tu truoc
void TreeTraversal_PreOrder(BTNode *cur) {
    if (cur == NULL)
        return;
    printf("%d ",cur->item);
    TreeTraversal_PreOrder(cur->left); //Tham nút con trái
    TreeTraversal_PreOrder(cur->right);//Tham nút con ph?i
} 

// theo th? t? gi?a
void TreeTraversal_InOrder(BTNode *cur) {
    if (cur == NULL)
        return;
    TreeTraversal_InOrder(cur->left); //Tham nút con trái
    printf("%d ",cur->item);
    
    TreeTraversal_InOrder(cur->right);//Tham nút con ph?i
} 


// theo thu tu sau
void TreeTraversal_PostOrder(BTNode *cur) {
    if (cur == NULL)
        return;
    TreeTraversal_PostOrder(cur->left); //Tham nút con trái
    TreeTraversal_PostOrder(cur->right);//Tham nút con ph?i
    printf("%d ",cur->item);
    
} 
int main(){
	int item1 = 1, item2 = 2, item3 = 3;
    BTNode btnode1, btnode2, btnode3;
    btnode1.item = item1;
    btnode2.item = item2;
    btnode3.item = item3;
    btnode2.left = NULL;
    btnode2.right = NULL;
    btnode3.left = NULL;
    btnode3.right = NULL;
    btnode1.left = &btnode2;
    btnode1.right = &btnode3;
    printf("\nDuyet cay theo thu tu truoc: ");
    TreeTraversal_PreOrder(&btnode1);
    printf("\nDu?et cay theo thu tu giua: ");
    TreeTraversal_InOrder(&btnode1);
    printf("\nDu?et cay theo thu tu sau: ");  
    TreeTraversal_PostOrder(&btnode1);
}


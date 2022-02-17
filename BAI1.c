#include<stdio.h>
#include<string.h>
// #include<ctype.h>


typedef struct SanPham{
    char ten[100];
    char masanpham[10];
    int soluong;
    int giathanh;
    int hansudung;
} SP;

void nhaplieu(SP danhsach[], int *size){
    
    for(int i=1; ;++i){
        printf("Nhap ten sp %d: ",i);
        gets(danhsach[i].ten);
        do{
            printf("Nhap ma sp %d: ",i);
            gets(danhsach[i].masanpham);
        }while (strlen(danhsach[i].masanpham)!=6);

        do{
            printf("Nhap so luong %d: ",i);
            scanf("%d", &danhsach[i].soluong);
        } while (danhsach[i].soluong < 0);   


        do{
            printf("Nhap gia san pham %d: ",i);
            scanf("%d", &danhsach[i].giathanh);
        } while (danhsach[i].giathanh < 0); 

        do{
            printf("Nhap hsd san pham %d: ",i);
            scanf("%d", &danhsach[i].hansudung);
        } while (danhsach[i].hansudung < 0); 
    // (*size)+=1;
    getchar();
    char option;
    printf("Nhap tiep? "); scanf("%c", &option); getchar();
    if(option != 'y') break;
    }
}

void inthongtin(SP s){
    printf("%10s %8s %4d %4d %4d", s.ten,s.masanpham,s.soluong,s.giathanh,s.hansudung);
}

void inmax(SP danhsach[], int size){
    int giamax= danhsach[0].giathanh;
    for(int i=0;i<size;++i){
        if(danhsach[i].giathanh>giamax);
            inthongtin(danhsach[i]);
    }
}

void sapxep(SP danhsach[], int size){
    for(int i=0;i<size;++i){
        for(int j=i+1;j<size;++j){
            if(danhsach[i].hansudung>danhsach[j].hansudung){
                SP tam = danhsach[i];
                danhsach[i]=danhsach[j];
                danhsach[j]=tam;
            }
        }
    }
}

void insaphethan(SP danhsach[], int size){
    int n;
    do{
        printf("Nhap n san pham sap het han: ");
        scanf("%d", &n);
    } while (n>size);

    for(int i=0;i<n;++i){
        inthongtin(danhsach[i]);
    }
    
}

int main(){
    int n;
    SP danhsach[100];
    nhaplieu(danhsach, &n);
    inmax(danhsach,n);
    sapxep(danhsach,n);
    insaphethan(danhsach,n);
    return 0;
}
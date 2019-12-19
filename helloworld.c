#include<stdio.h>
#include<malloc.h>
typedef struct LNode *List;
typedef int ElementType;
#define MAXSIZE 1000

struct LNode {
    ElementType Data[MAXSIZE];
    int Last;
};

List MakeEmpty(){
    List Ptrl;
    Ptrl = (List)malloc(sizeof(struct LNode));
    Ptrl->Last = -1;
    return Ptrl;
}

int Find(List Ptrl, ElementType X){
    int i;
    for (i = 0; i <= Ptrl->Last;i++){
        if(Ptrl->Data[i] == X)
            break;
    }

    if(Ptrl->Last + 1 == i)
        return -1;
    else
        return i;
} 

void Insert(List Ptrl, int i, int X){
    int j;

    if(Ptrl->Last == MAXSIZE -1){
        printf("表满\n");
        return;
    }

    if(i<1 || i > Ptrl->Last+2){
        printf("位置错误\n");
        return;        
    }

 
    for (j = Ptrl->Last; j >= i-1; j--){
        Ptrl->Data[j + 1] = Ptrl->Data[j];
    }
    
    Ptrl->Data[i-1] = X;
    Ptrl->Last++;
    return;
}

void Delete(List Ptrl, int i){
    int j;
    if(i<1 || i > Ptrl->Last+2){
        printf("位置错误\n");
        return;        
    }

    for (j = i; j <= Ptrl->Last; j++){
        Ptrl->Data[j-1] = Ptrl->Data[j];
    }
    
    Ptrl->Last--;
    return;

}

void Print(List Ptrl){
    int i;
    for (i = 0; i <= Ptrl->Last; i++)
        printf("%d ", Ptrl->Data[i]);
}

int main(){
    List L;
    L = MakeEmpty();
    Insert(L, 1, 5);
    Insert(L, 2, 15);
    Insert(L, 3, 25);
    Insert(L, 4, 35);
    Print(L);

    printf("\n");
    
    Delete(L, 1);

    Print(L);

    return 0;
}
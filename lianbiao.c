#include<stdio.h>
#include <malloc.h>

typedef struct LNode *List;
struct LNode{
    int Data;
    List Next;
};

int Length(List L){
    List P;
    P = L;
    int i=0;
    while(P){
        i++;
        P = P->Next;
    }
    return i;
}

List FindKth(List L, int i){
    List P = L;
    int j = 1;
    while(j < i && P != NULL){
        P = P->Next;
        j++;
    }

    if(j == i)
        return P;
    else
        return NULL;
}

List Find(List L, int X){
    List P = L;

    while(P!=NULL && P->Data !=X){
        P = P->Next;
    }
    return P;

}

List Insert(List L, int i, int X){
    List s, p;
    
    

    if(i == 1){
        s = (List)malloc(sizeof(struct LNode));
        s->Data = X;
        s->Next = L;
        return s;
    }

    p = FindKth(L, i-1);
    if(p == NULL){
        printf("error\n");
        return NULL;
    }else{
        s = (List)malloc(sizeof(struct LNode));
        s->Data = X;
        s->Next = p->Next;
        p->Next = s;
        return L;
    }
}

List Delete(List L, int i){
    List s, p;
    if(i == 1){
        s = L;
        if(L!=NULL){
            L = L->Next;
        }else
            return NULL;
        free(s);
        return L;
    }

    p = FindKth(L, i - 1);
    if(p == NULL){
        printf("error\n");
        return NULL;
    }else if(p->Next == NULL){
        return NULL;
    }else {
        s = p->Next;
        p->Next = s->Next;
        free(s);
        return L;
    }


}

void Print(List L){
    List t = L;
    while(t != NULL){
        printf("%d ", t->Data);
        t = t->Next;
    }
    free(t);
}

int main(){
    List L = (List)malloc(sizeof(struct LNode));
    L->Next = NULL;
    L->Data = 0;
    L = Insert(L, 1, 25);
    L = Insert(L, 1, 5);
    L = Insert(L, 1, 15);
    L = Insert(L, 1, 35);
    Print(L);

    L = Delete(L, 5);
    Print(L);

    printf("%d", Length(L));
    return 0;
}
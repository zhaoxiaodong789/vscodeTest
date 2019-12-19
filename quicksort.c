#include <stdio.h>
int a[101], n;

void quicksort(int left, int right){
    int i, j, temp, t;
    if(left > right){
        return;

    }

    temp = a[left];
    i = left;
    j = right;
    while(i!=j){
        while(a[j]>=temp && i<j){
            j--;
        }
            
        while(a[i]<=temp && i<j){
            i++;
        }

        if(i<j){
            t = a[j];
            a[j] = a[i];
            a[i] = t;
        }
        
    }
    
    a[left] = a[i];
    a[i] = temp;

    quicksort(left, i - 1);
    quicksort(i + 1, right);

}

int main(){
	
	int i,temp[101],j;
	scanf("%d", &n);
	for(i=1;i<=n;i++)
		scanf("%d", &a[i]);
	quicksort(1,n);
	for(i=2,j=2;i<=n;i++){
		if(a[i] != a[i-1]){
			
			temp[j]=a[i];
		   j++;
		}
			
	
	}
    j--;

    temp[1]=a[1];
	printf("%d\n", j);
	for(i=1;i<=j;i++){
		printf("%d ", temp[i]);
			
	
	}

    getchar();
    getchar();
    return 0;



}
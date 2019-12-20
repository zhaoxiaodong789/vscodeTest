#include <iostream>
#include <vector>
using namespace std;
void SelectionSort( vector<int>& arr){
    int min, i,j,temp  ;
    
    for (i = 0; i < arr.size()-1;i++){
        min = i;
        for(j=i+1;j<arr.size();j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }

        if(min != i){
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }


}

int main(){
    
    vector<int> src(10), arr(10);
    cout << "hello" << endl;
    for (int i = 0; i < 10 ;i++){
        cin >> src[i];
       
    }
    arr = src;
    cout << arr.size()<<endl;

    SelectionSort(arr);

    for (int i = 0; i < 10;i++){
        
        cout << arr[i] <<" ";
    }
   

   
    return 0;
}
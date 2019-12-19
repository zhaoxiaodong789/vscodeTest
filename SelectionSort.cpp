#include <iostream>
#include <vector>
using namespace std;
void SelectionSort(vector<int>& src, vector<int>& arr){
    int min, i,j,temp  ;
    arr = src;
    for (i = 0; i < arr.size()-1;i++){
        min = i;
        for(j=i+1;j<arr.size();j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }

        if(min != i){
            temp = arr[j];
            arr[j] = arr[min];
            arr[min] = temp;
        }
    }


}

int main(){
    
    vector<int> src(10), arr(10);
    cout << "hello" << endl;
    for (int i = 0; i < 2;i++){
        cin >> src[i];
       
    }

    cout << arr.size();

    SelectionSort(src, arr);

    for (int i = 0; i < 10;i++){
        
        cout << arr[i] <<" ";
    }
   

    system("pause");
    return 0;
}
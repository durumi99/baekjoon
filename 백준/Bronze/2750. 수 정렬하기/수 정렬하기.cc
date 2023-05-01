#include <iostream>

using namespace std;
int arr[1010];
int n;

void swap(int i,int j){
    int tmp = arr[j];
    arr[j] = arr[i];
    arr[i] = tmp;
}
void selectionSort(){
    for(int i = 0 ; i < n ; i++){
        int minIdx = i;
        for(int j = i + 1 ; j < n ; j++){
            if(arr[j] < arr[minIdx]){
                minIdx = j;
            }
        }
        swap(i,minIdx);
    }
}

void insertionSort(){
    for(int i = 0 ; i < n ; i++){
        int j = i-1;
        int key = arr[i];
        while(j > 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void BubbleSort(){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n-1-i ; j++){
            if(arr[j] > arr[j+1]){
                swap(j,j+1);
            }
        }
    }
}
int main() {
    cin >> n;
    for(int i = 0 ; i < n ; i++)
        cin >> arr[i];
    selectionSort();
    // insertionSort();
    // BubbleSort();
    for(int i = 0 ; i < n ; i++)
        cout << arr[i] << '\n';
    
    return 0;
}
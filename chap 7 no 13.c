#include <stdio.h>

void seleksiAngka(int arr[], int n){
  int minIndex, temp;

  for(int i = 0; i < n - 1; i++){
    minIndex = i;
    for(int j = i + 1; j < n; j++){
      if(arr[j] < arr[minIndex]){
        minIndex = j;
      }
    }
    temp = arr[minIndex];
    arr[minIndex] = arr[i];
    arr[i] = temp;
  }
}

void output(int arr[], int size){
  for(int i = 0; i < size; i++){
    printf("%d ", arr[i]);
  }
}

int main(){
  int n;
  scanf("%d", &n);

  if(n <= 0){
    return 1;
  }

  int arr[n];
  for(int i = 0; i < n; i++){
    scanf("%d", &arr[i]);
  }

  seleksiAngka(arr, n);
  output(arr, n);

  return 0;
}
#include <stdio.h>

//prototype

void selection_sort(int arr[], int n);
void swap(int *i, int *j);

void print_array(int arr[], int size);

int main(void) {
    //test selection_sort
    int arr1[4] = {2, 4, 7, 6};
    selection_sort(arr1, 4);
    print_array(arr1, 4);


    return 0;
}   


void selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i + 1;
        
        for (int j = i; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        swap(&arr[i], &arr[min_index]);
    }
    


}

void swap(int *i, int *j) {
    int temp = *i;
    *i = *j;
    *j = temp;

}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
#include <stdio.h>
#include <stdbool.h>

//prototype

void selection_sort(int arr[], int n);
void bubble_sort(int arr[], int n);
void shell_sort(int arr[], int n);

void swap(int *i, int *j);

void print_array(int arr[], int size);

int main(void) {
    //test different sort
    int arr1[4] = {2, 4, 7, 6};

    //selection_sort(arr1, 4);
    //bubble_sort(arr1, 4); 
    //selection_sort(arr1, 4);
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

void bubble_sort(int arr[], int n) {
    int i, j;
    //i is used to avoid comparing the sorted elements
    for (int i = 0; i < n; i++) {
        //check the adjacent elements
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }

        //If no elements were compared by inner loop
        //then stop sorting
        if (swapped == false) {
            break;
        }
    }
}


void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > arr[j - 1]) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j] = key;

   }

}

void shell_sort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        //keep adding one more element until the whole array is sorted
        for (int i = gap; i < n; i ++) {
            int temp = arr[i];
            int j;
            for (int j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
                arr[j] = temp;
            }  
        }
        
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



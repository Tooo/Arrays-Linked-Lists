//Array.cpp
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Create len sized array and randomized
void CreateRandomArray (int arr[], int len) {
    srand(time(0));
    for (int i = 0; i < len; i++) {
        int newnum = rand() %100;
        arr[i] = newnum;
    }
    return;
}

//Print all elements of array
void PrintArray(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return;
}

//Swapping arr[a] with arr[b]
void Swap (int arr[], int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
    return;
}

void SelectionSort (int arr[], int len) {
    //Cycle from arr[0] to arr[len-1]
    for (int i = 0; i < len; i++) {
        int minpos = i;
        //Cycle from arr[i+1] to arr[len-1]
        for (int j = i + 1; j < len; j++) {
            //If arr[minpos] is bigger than arr[j]
            //minpos becomes j
            if (arr[minpos] > arr[j]) minpos = j;
        }
        //swap arr[minpos] with arr[i]
        Swap(arr, minpos, i);
        PrintArray(arr, len);
    }
    return;
}

void InsertionSort (int arr[], int len) {
    //Cycle from arr[1] to arr[len-1]
    for (int i = 1; i < len; i++) {
        //Temp copy or arr[i]
        int newEle = arr[i];
        int j = i;
        //while j is bigger than 0 and newEle is smaller 
        while (j > 0 && newEle < arr[j-1]) {
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = newEle;
        PrintArray(arr, len);
    }
    return;
}

int LinearSearch (int arr[], int len, int target) {
    int num = -1;
    for (int i = 0; i < len; i++) {
        if (arr[i] == target) num = i;
    }
    return num;
}

int BinarySearch (int arr[], int len, int target) {
    int first = 0, last = len-1;
    while (first <= last) {
        int mid = (first + last) /2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) first = mid+1;
        else last = mid-1;
    }
    return -1;
}


//Merge Sort
//Copy array from src to dest
void ArrayCopy(int dest[], int src[], int len) {
    for (int i = 0; i < len; i++) {
        dest[i] = src[i];
    }
}

// Pre: arr[first..mid] and arr[mid+1..last] are sorted
// Post: arr[first..last] are sorted
void Merge(int arr[], int first, int mid, int last) {
    int len = last-first+1; int newArr[len];
    int leftPos = first; int rightPos = mid+1; int newPos = 0;
    while (leftPos <= mid && rightPos <= last) {
        if (arr[leftPos] < arr[rightPos]) {
            newArr[newPos++] = arr[leftPos++];
        } else {
            newArr[newPos++] = arr[rightPos++];
        }
    }

    // Flush non empty piece
    ArrayCopy(newArr + newPos, arr + leftPos, mid - leftPos +1);
    ArrayCopy(newArr + newPos, arr + rightPos, last - rightPos + 1);

    ArrayCopy(arr + first, newArr, len);
}

// Post: arr[first..last] are sorted
void MergeSort(int arr[], int first, int last) {
    //Base case
    if (last<=first) return;

    //Split array
    int mid = (first+last) / 2;

    //Recursively sort
    MergeSort(arr, first, mid);
    MergeSort(arr, mid+1, last);

    //Join
    Merge(arr, first, mid, last);
    PrintArray(arr, last+1);
}


//Quick Sort
//Arrange array so smaller than pivot on left and larger on right
int partition(int arr[], int first, int last) {
    int pivot = arr[last];
    int mid = first;

    //Loops from first to last-1
    for (int i = first; i < last; i++) {
        if (arr[i] <= pivot) {
            Swap(arr, i, mid++);
        }
    }

    Swap(arr, last, mid);

    //return correct index of pivot
    return mid;
}

//Post: arr[first..last] are sorted
void QuickSort(int arr[], int first, int last) {
    //Base case
    if (last <= first) return;

    //Split array
    int mid = partition(arr, first, last);

    //Recursively sort
    QuickSort(arr, first, mid-1);
    QuickSort(arr, mid+1, last);
    
    PrintArray(arr, last+1);
}
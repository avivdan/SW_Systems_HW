#include <stdio.h>
#include <string.h>
#define MAARACH_SIZE 50


void swap(int* p, int* q);
void shift_element(int* arr, int i);
void insertion_sort(int* arr, int len);


int main() {
    int arr[MAARACH_SIZE];
    for (int i = 0; i < MAARACH_SIZE; ++i) {
        scanf("%d", &arr[i]);
    }
    insertion_sort(arr, MAARACH_SIZE);
    for (int i = 0; i < MAARACH_SIZE; ++i) {
        printf("%d \n", arr[i]);
    }
    return 0;
}

void swap(int* p, int* q)
{
    int tmp = *p;
    *p = *q;
    *q = tmp;
}

void shift_element(int* arr, int i)
{
    for (int j = i; j > 0; j = j - 1)
    {
        swap((arr +j), (arr + j -1));
    }
}

void insertion_sort(int* arr, int len)
{
    for (int i = 1 ; i < len; i = i + 1)
    {
        int (*tempI) = arr + i;

        for (int j = 0; j < i; j++)
        {
            int (*tempArr) = arr + j;
            if (*tempArr > *tempI)
            {
                shift_element(tempArr, i - j);
            }
        }
    }
}

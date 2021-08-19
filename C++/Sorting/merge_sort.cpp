#include <bits/stdc++.h>
using namespace std;

void printarray(int n, int array[])
{
    // print the sorted array
    cout << "Sorted array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

// The merge() function is used for merging two sorted arrays.
void merge(int array[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int left[n1], right[n2];
    for (i = 0; i < n1; i++)
    {
        left[i] = array[l + i];
    }
    for (j = 0; j < n2; j++)
    {
        right[j] = array[m + j + 1];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            array[k] = left[i];
            i++;
        }
        else
        {
            array[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        array[k] = left[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        array[k] = right[j];
        j++;
        k++;
    }
}
void mergesort(int array[], int left, int right)
{
    // left - start index of array
    // right - end index of array
    if (left < right)
    {
        int middle = left + (right - left) / 2;
        mergesort(array, left, middle);
        mergesort(array, middle + 1, right);
        merge(array, left, middle, right);
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements in the array" << endl;
    cin >> n; // Total number of elements
    int array[n];
    cout << "Enter the values of numbers in the array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    mergesort(array, 0, n - 1);
    printarray(n, array); // function to print an array.
}

/* 
    Time Complexity  : O(N*logN) 
    Space Complexity : O(N)
    
Sample Input :
     Enter the number of elements in the array : 7
     Enter the values of numbers in the array:
     7 4 1 5 2 6 3
Output :
    Sorted array: 
        1 2 3 4 5 6 7
*/
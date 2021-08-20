/*
Given an array of integers, and return a sorted array
Bubble sort is a sorting algorithm. 
This is comparison-based algorithm that works by comparing each pair of adjacent elements.
And the elements are swapped, if they are in wrong order.
The algorithm is suitable for small data sets.
*/

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
void bubblesort(int n, int array[])
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                //Swap two numbers
                swap(array[j], array[j + 1]);
            }
        }
    }
    printarray(n, array); // function to print an array
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
    bubblesort(n, array);
}

/* 
    Time Complexity  : O(N^2) 
    Space Complexity : O(1)
    
Sample Input :
     Enter the number of elements in the array : 7
     Enter the values of numbers in the array:
     7 4 1 5 2 6 3
Output :
    Sorted array: 
        1 2 3 4 5 6 7
*/


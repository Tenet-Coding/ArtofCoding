/*
Given an array of integers, and return a sorted array.
Insertion sort is a sorting algorithm which is less effiecient compared to other sorting algorithms like heap sort, merge sort.
It is a stable sorting algorithm. The idea is similar to sorting playing cards.
we insert each element onto its proper index in the array.
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

void insertionsort(int n, int array[])
{
    int i, temp;
    for (i = 1; i < n; i++)
    {
        temp = i - 1;
        while (array[temp + 1] < array[temp] && temp >= 0)
        {
            swap(array[temp + 1], array[temp]);
            temp--;
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
    insertionsort(n, array);
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


/*
Binary Search:
- An algorithm that finds the position of a target value within a sorted array.
- Binary search compares the target value to the middle element of the array.
- If they are not equal, the half in which the target cannot lie is eliminated and
  the search continues on the remaining half, again taking the middle element to
  compare to the target value, and repeating this until the target value is found.
- If the search ends with the remaining half being empty, the target is not in the array.

Time Complexity: O(n log n)
Space Complexity: O(1)

Source: https://en.wikipedia.org/wiki/Binary_search_algorithm
*/


function binarySearch(arr, key) {
  let low = 0;
  let high = arr.length - 1;

  while(low <= high) {
    const mid = low + Math.floor((high - low)/2);

    if(key === arr[mid]){
      return mid;
    }
    else if(key < arr[mid]){
      high = mid - 1;
    }
    else {
      low = mid + 1;
    }
  }

  return -1;
}


/*
INPUT
arr = [4, 6, 7, 9, 11, 13, 16, 18, 20];
key = 13;

OUTPUT
index = 5
*/
/*
Quick Sort:
- It is a divide-and-conquer algorithm that sorts a given array of elements.
- It works by selecting a 'pivot' element from the array and
  partitioning the other elements into two sub-arrays,
  according to whether they are less than or greater than the pivot.
- The sub-arrays are then sorted recursively untill the whole array is sorted.
- At each step the left, center and right arrays are concated or joined. 
- Finally the sorted array is obtained.

Time Complexity: O(n log n)
Space Complexity: O(log n)

Source: https://en.wikipedia.org/wiki/Quicksort
*/

function quickSort(originalArr) {
  if (originalArr.length <= 1) {
    return originalArr;
  }

  const arr = [...originalArr];

  const leftArr = [];
  const rightArr = [];
  const centerArr = [];

  const randInt = Math.floor(Math.random() * (arr.length - 1) + 1);

  [arr[0], arr[randInt]] = [arr[randInt], arr[0]];

  const pivotElem = arr.shift();
  centerArr.push(pivotElem);

  while(arr.length > 0) {
    const curElem = arr.shift();

    if(curElem === pivotElem) {
      centerArr.push(curElem);
    } else if (curElem < pivotElem) {
      leftArr.push(curElem);
    } else if (curElem > pivotElem) {
      rightArr.push(curElem);
    }
  }

  const sortedLeftArr = quickSort(leftArr);
  const sortedRightArr = quickSort(rightArr);

  return sortedLeftArr.concat(centerArr, sortedRightArr);
}

/*Driver Code*/

const array = [9, 2, 5, 7, 1];
const result = quickSort(array);

console.log("Input: ", array);
console.log("Output: ", result);
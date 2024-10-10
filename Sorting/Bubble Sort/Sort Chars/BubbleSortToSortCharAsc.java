// Algorithm:
// 1. Initialize Variables:
//    Create an integer variable n to store the length of the array. 
//    Also, create a boolean variable swapped to keep track of whether any elements were swapped during a pass.
// 
// 2. Outer Loop (Repeat Passes):
//    Repeat n-1 times (for i from 0 to n-1):
//    a. Set swapped to false at the start of each pass.
//    b. Inner Loop (Compare Adjacent Elements):
//       For each adjacent pair of characters in the array (for j from 0 to n-i-1):
//       i. Compare the characters arr[j] and arr[j+1]:
//          If arr[j] > arr[j+1], swap them and set swapped to true.
//    c. If no elements were swapped during the pass (swapped remains false), the array is already sorted, so exit the loop early.
//
// 3. End:
//    After all passes, the array will be sorted in ascending order.
//    Print or return the sorted array.

public class BubbleSortCharacters {

    // Function to perform bubble sort on the array of characters
    public static void bubbleSort(char[] arr) {
        int n = arr.length;
        boolean swapped;

        // Outer loop to traverse the array multiple times
        for (int i = 0; i < n - 1; i++) {
            swapped = false;

            // Inner loop to compare adjacent elements
            for (int j = 0; j < n - i - 1; j++) {
                // Compare and swap if elements are in the wrong order
                if (arr[j] > arr[j + 1]) {
                    // Swap arr[j] and arr[j+1]
                    char temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swapped = true;
                }
            }

            // If no two elements were swapped in the inner loop, then the array is already sorted
            if (!swapped) {
                break;
            }
        }
    }

    // Main function to test the bubble sort function
    public static void main(String[] args) {
        // Test Case 1
        char[] arr1 = { 'd', 'b', 'a', 'c' };
        bubbleSort(arr1);
        System.out.println("Sorted array: " + java.util.Arrays.toString(arr1));  // Output: [a, b, c, d]

        // Test Case 2
        char[] arr2 = { 'z', 'x', 'y' };
        bubbleSort(arr2);
        System.out.println("Sorted array: " + java.util.Arrays.toString(arr2));  // Output: [x, y, z]
    }
}

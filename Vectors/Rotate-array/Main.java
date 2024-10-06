import java.util.Scanner;
import java.util.ArrayList;

class Solution {
    public void rotate(ArrayList<Integer> nums, int k) {
        int last;
        int n = nums.size();

        for (int i = 0; i < k; i++) {
            last = nums.get(n - 1);
            for (int j = n - 2; j >= 0; j--) {
                nums.set(j + 1, nums.get(j));
            }
            nums.set(0, last);
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Solution sol = new Solution();

        System.out.print("Enter the size of the array: ");
        int n = scanner.nextInt();

        System.out.print("Enter the number of times you want to rotate: ");
        int k = scanner.nextInt();

        ArrayList<Integer> arr = new ArrayList<>(n);
        System.out.println("Enter the elements of the array: ");
        for (int i = 0; i < n; i++) {
            arr.add(scanner.nextInt());
        }

        sol.rotate(arr, k);

        System.out.println("Array after rotation:");
        for (int i : arr) {
            System.out.print(i + " ");
        }

        scanner.close();
    }
}
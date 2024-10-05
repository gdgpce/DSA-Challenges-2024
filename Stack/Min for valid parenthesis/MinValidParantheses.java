// Algorithm:

// 1.Initialize Counters:
// Create two integer variables: open and close, both initialized to 0.
// open: This will count unmatched opening parentheses '('.
// close: This will count unmatched closing parentheses ')'.

// 2.Iterate Through Each Character:
// Loop through each character c in the input string s:
// a.If c is an opening parenthesis '(':Increment the open counter by 1 (open++).
// b.If c is a closing parenthesis ')':
//   Check if there are unmatched opening parentheses:
//     If open > 0:
//     Decrement the open counter by 1 (open--) since this closing parenthesis can match an opening one.
//   Otherwise:
//     Increment the close counter by 1 (close++) because this closing parenthesis is unmatched.

// 4.Calculate the Result:
// After iterating through all characters, the total number of parentheses that need to be added to make the string valid is:
// result=open+close

// 5.Return or Print the Result:
// Return or print the calculated result.

import java.util.Scanner;

public class MinValidParantheses{

    public static int minAddToMakeValid(String s) {
        // Count of unmatched '('
        int open = 0; 
        // Count of unmatched ')'
        int close = 0; 

        for (char c : s.toCharArray()) {
            if (c == '(') {
                open++; // Increment for an unmatched opening parenthesis
            } else if (c == ')') {
                if (open > 0) {
                    open--; // Match with an opening parenthesis
                } else {
                    close++; // Increment for an unmatched closing parenthesis
                }
            }
        }
        // The total needed is unmatched '(' + unmatched ')'
        return open + close;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a string of parentheses: ");
        String input = sc.nextLine();

        int result = minAddToMakeValid(input);
        System.out.println("Minimum number of parentheses to add: " + result);
    }
}

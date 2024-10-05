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

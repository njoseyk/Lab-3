import java.util.Scanner;

public class SimpleCalculator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String choice;
        
        System.out.println("Welcome to the Java Calculator!");
        
        do {
            System.out.print("Enter an operation (+, -, *, /, or exit): ");
            choice = scanner.next();
            
            if (choice.equals("exit")) {
                break;
            }
            
            if (!(choice.equals("+") || choice.equals("-") || choice.equals("*") || choice.equals("/"))) {
                System.out.println("Invalid operation. Please enter +, -, *, /, or exit.");
                continue;
            }
            
            System.out.print("Enter the first number: ");
            if (!scanner.hasNextDouble()) {
                System.out.println("Invalid input. Please enter a valid number.");
                scanner.next(); // consume the invalid input
                continue;
            }
            double num1 = scanner.nextDouble();
            
            System.out.print("Enter the second number: ");
            if (!scanner.hasNextDouble()) {
                System.out.println("Invalid input. Please enter a valid number.");
                scanner.next(); // consume the invalid input
                continue;
            }
            double num2 = scanner.nextDouble();
            
            if (num1 < -1000 || num1 > 1000 || num2 < -1000 || num2 > 1000) {
                System.out.println("Error: Numbers must be between -1000 and 1000.");
                continue;
            }
            
            double result = 0;
            boolean validOperation = true;
            
            switch (choice) {
                case "+":
                    result = num1 + num2;
                    break;
                case "-":
                    result = num1 - num2;
                    break;
                case "*":
                    result = num1 * num2;
                    break;
                case "/":
                    if (num2 == 0) {
                        System.out.println("Error: Division by zero is not allowed.");
                        validOperation = false;
                    } else {
                        result = num1 / num2;
                    }
                    break;
                default:
                    validOperation = false;
                    System.out.println("Invalid operation.");
            }
            
            if (validOperation) {
                System.out.println("The result of " + num1 + " " + choice + " " + num2 + " = " + result);
            }
            
            System.out.print("Would you like to perform another operation (yes/no)? ");
            choice = scanner.next();
            
        } while (choice.equalsIgnoreCase("yes"));
        
        System.out.println("Thank you for using the Java Calculator! Goodbye!");
        scanner.close();
    }
}

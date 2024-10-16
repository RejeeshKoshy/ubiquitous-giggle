import java.util.HashSet;
import java.util.Scanner;

public class StudentIDManager {

    public static void main(String[] args) {
        // Create a HashSet to store unique student IDs
        HashSet<Integer> studentIDs = new HashSet<>();
        Scanner scanner = new Scanner(System.in);
        int choice;

        do {
            System.out.println("\n--- Student ID Management System ---");
            System.out.println("1. Add a student ID");
            System.out.println("2. Remove a student ID");
            System.out.println("3. Check if a student ID exists");
            System.out.println("4. Display all student IDs");
            System.out.println("5. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    // Add a student ID
                    System.out.print("Enter student ID to add: ");
                    int newID = scanner.nextInt();
                    if (studentIDs.add(newID)) {
                        System.out.println("Student ID added successfully.");
                    } else {
                        System.out.println("Student ID already exists! No duplicates allowed.");
                    }
                    break;

                case 2:
                    // Remove a student ID
                    System.out.print("Enter student ID to remove: ");
                    int removeID = scanner.nextInt();
                    if (studentIDs.remove(removeID)) {
                        System.out.println("Student ID removed successfully.");
                    } else {
                        System.out.println("Student ID not found.");
                    }
                    break;

                case 3:
                    // Check if a student ID exists
                    System.out.print("Enter student ID to check: ");
                    int checkID = scanner.nextInt();
                    if (studentIDs.contains(checkID)) {
                        System.out.println("Student ID exists.");
                    } else {
                        System.out.println("Student ID does not exist.");
                    }
                    break;

                case 4:
                    // Display all student IDs
                    System.out.println("\nAll student IDs:");
                    if (studentIDs.isEmpty()) {
                        System.out.println("No student IDs found.");
                    } else {
                        for (Integer id : studentIDs) {
                            System.out.println(id);
                        }
                    }
                    break;

                case 5:
                    // Exit
                    System.out.println("Exiting...");
                    break;

                default:
                    System.out.println("Invalid choice! Please try again.");
            }

        } while (choice != 5);

        scanner.close();
    }
}

import java.util.LinkedList;

public class LinkedListDemo {

    public static void main(String[] args) {
        // Create a LinkedList of Strings
        LinkedList<String> friends = new LinkedList<>();

        // 1. Add elements to the LinkedList
        System.out.println("Adding elements to the LinkedList...");
        friends.add("Antony");
        friends.add("Betson");
        friends.add("Akshatha");
        friends.add("Shreyas");

        System.out.println("LinkedList after adding elements:");
        traverseList(friends);

        // 2. Add elements at the beginning and end of the LinkedList
        System.out.println("\nAdding 'Jarin' at the beginning and 'Clancy' at the end...");
        friends.addFirst("Jarin");
        friends.addLast("Clancy");

        System.out.println("LinkedList after adding elements at beginning and end:");
        traverseList(friends);

        // 3. Access first and last element
        System.out.println("\nFirst element: " + friends.getFirst());
        System.out.println("Last element: " + friends.getLast());

        // 4. Remove first and last elements
        System.out.println("\nRemoving first and last elements...");
        friends.removeFirst();
        friends.removeLast();

        System.out.println("LinkedList after removing first and last elements:");
        traverseList(friends);

        // 5. Insert an element at a specific position
        System.out.println("\nInserting 'Awma' at index 2...");
        friends.add(2, "Awma");

        System.out.println("LinkedList after inserting 'Awma' at index 2:");
        traverseList(friends);

        // 6. Remove an element using remove()
        System.out.println("\nRemoving 'Akshatha' from the list...");
        friends.remove("Akshatha");

        System.out.println("LinkedList after removing 'Akshatha':");
        traverseList(friends);

        // 7. Check if a specific element exists in the LinkedList
        System.out.println("\nChecking if 'Shreyas' is in the list: " + friends.contains("Shreyas"));
        System.out.println("Checking if 'Akshatha' is in the list: " + friends.contains("Akshatha"));

        // 8. Get the size of the LinkedList
        System.out.println("\nSize of the LinkedList: " + friends.size());

        // 9. Clear all elements from the LinkedList
        System.out.println("\nClearing the entire LinkedList...");
        friends.clear();

        System.out.println("LinkedList after clearing:");
        traverseList(friends);
    }

    // Method to traverse and display the elements of the LinkedList
    public static void traverseList(LinkedList<String> list) {
        if (list.isEmpty()) {
            System.out.println("The list is empty.");
        } else {
            for (String item : list) {
                System.out.println(item);
            }
        }
    }
}

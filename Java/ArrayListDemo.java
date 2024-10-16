import java.util.ArrayList;

public class ArrayListDemo {

    public static void main(String[] args) {
        // Create an ArrayList
        ArrayList<String> lang = new ArrayList<>();

        // 1. Add elements to the ArrayList
        System.out.println("Adding elements to the ArrayList...");
        lang.add("C");
        lang.add("Python");
        lang.add("C++");
        lang.add("Rust");

        System.out.println("ArrayList after adding elements:");
        traverseList(lang);

        // 2. Access an element using get()
        System.out.println("\nAccessing element at index 2: " + lang.get(2));

        // 3. Modify an element using set()
        System.out.println("\nModifying the element at index 1...");
        lang.set(1, "Kotlin");

        System.out.println("ArrayList after modifying:");
        traverseList(lang);

        // 4. Remove an element using remove()
        System.out.println("\nRemoving element at index 3...");
        lang.remove(3);

        System.out.println("ArrayList after removing an element:");
        traverseList(lang);

        // 5. Check if an element exists using contains()
        System.out.println("\nChecking if 'Python' is in the list: " + lang.contains("Python"));
        System.out.println("Checking if 'C' is in the list: " + lang.contains("C"));

        // 6. Add an element at a specific position
        System.out.println("\nAdding 'Ruby' at index 2...");
        lang.add(2, "Ruby");

        System.out.println("ArrayList after adding 'Ruby' at index 2:");
        traverseList(lang);

        // 7. Get the size of the ArrayList
        System.out.println("\nSize of ArrayList: " + lang.size());

        // 8. Clear all elements from the ArrayList
        System.out.println("\nClearing the entire ArrayList...");
        lang.clear();

        System.out.println("ArrayList after clearing:");
        traverseList(lang);
    }

    // Method to traverse and display the elements of the ArrayList
    public static void traverseList(ArrayList<String> list) {
        if (list.isEmpty()) {
            System.out.println("The list is empty.");
        } else {
            for (String item : list) {
                System.out.println(item);
            }
        }
    }
}

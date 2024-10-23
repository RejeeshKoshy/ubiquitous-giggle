package com.mca_demo;

public class MVCPatternDemo {

    public static void main(String[] args) {
        // Fetch the course record based on user input
        Course model = retrieveCourseFromDatabase();

        // Create the view to show course details on console
        CourseView view = new CourseView();

        // Create the controller, passing model and view
        CourseController controller = new CourseController(model, view);

        // Display the current course details
        controller.updateView();

        // Update the model data
        controller.setCourseName("Advanced Computing");

        // Display the updated course details
        System.out.println("\nAfter updating the course name...");
        controller.updateView();
    }

    // Simulating data retrieval from a database or any data source
    private static Course retrieveCourseFromDatabase() {
        return new Course("Introduction to Java", "CS101", "Programming");
    }
}

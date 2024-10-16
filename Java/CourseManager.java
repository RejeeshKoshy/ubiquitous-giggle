import java.util.Scanner;

class Course {
    // Private member variables
    private String courseName;
    private String courseID;
    private String courseCategory;

    // Getter and Setter for courseName
    public String getCourseName() {
        return courseName;
    }

    public void setCourseName(String courseName) {
        this.courseName = courseName;
    }

    // Getter and Setter for courseID
    public String getCourseID() {
        return courseID;
    }

    public void setCourseID(String courseID) {
        this.courseID = courseID;
    }

    // Getter and Setter for courseCategory
    public String getCourseCategory() {
        return courseCategory;
    }

    public void setCourseCategory(String courseCategory) {
        this.courseCategory = courseCategory;
    }

    // Method to display course details
    public void printCourseDetails(String courseName, String courseID, String courseCategory) {
        System.out.println("\nCourse Details:");
        System.out.println("Course Name: " + courseName);
        System.out.println("Course ID: " + courseID);
        System.out.println("Course Category: " + courseCategory);
    }

    // Method to retrieve course details from the user
    public void retrieveCourseFromDatabase() {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter course name: ");
        setCourseName(scanner.nextLine());

        System.out.print("Enter course ID: ");
        setCourseID(scanner.nextLine());

        System.out.print("Enter course category: ");
        setCourseCategory(scanner.nextLine());
    }
}

public class CourseManager {

    public static void main(String[] args) {
        // Create a Course object
        Course course = new Course();

        // 1. Retrieve course details from the user
        course.retrieveCourseFromDatabase();

        // 2. Display course details using printCourseDetails
        course.printCourseDetails(course.getCourseName(), course.getCourseID(), course.getCourseCategory());

        // 3. Update the course name to "Computing in Java"
        course.setCourseName("Computing in Java");

        // 4. Display updated course details
        System.out.println("\nUpdated Course Name:");
        course.printCourseDetails(course.getCourseName(), course.getCourseID(), course.getCourseCategory());
    }
}

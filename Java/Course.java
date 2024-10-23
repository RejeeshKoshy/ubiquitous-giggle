package com.mca_demo;

public class Course {
    private String courseName;
    private String courseId;
    private String courseCategory;

    // Constructor
    public Course(String courseName, String courseId, String courseCategory) {
        this.courseName = courseName;
        this.courseId = courseId;
        this.courseCategory = courseCategory;
    }

    // Getter and Setter for courseName
    public String getCourseName() {
        return courseName;
    }

    public void setCourseName(String courseName) {
        this.courseName = courseName;
    }

    // Getter and Setter for courseId
    public String getCourseId() {
        return courseId;
    }

    public void setCourseId(String courseId) {
        this.courseId = courseId;
    }

    // Getter and Setter for courseCategory
    public String getCourseCategory() {
        return courseCategory;
    }

    public void setCourseCategory(String courseCategory) {
        this.courseCategory = courseCategory;
    }
}

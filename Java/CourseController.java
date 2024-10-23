package com.mca_demo;

public class CourseController {
    private Course model;
    private CourseView view;

    // Constructor
    public CourseController(Course model, CourseView view) {
        this.model = model;
        this.view = view;
    }

    // Getters and Setters to update model data
    public void setCourseName(String courseName) {
        model.setCourseName(courseName);
    }

    public String getCourseName() {
        return model.getCourseName();
    }

    public void setCourseId(String courseId) {
        model.setCourseId(courseId);
    }

    public String getCourseId() {
        return model.getCourseId();
    }

    public void setCourseCategory(String courseCategory) {
        model.setCourseCategory(courseCategory);
    }

    public String getCourseCategory() {
        return model.getCourseCategory();
    }

    // Method to update the view (display model data)
    public void updateView() {
        view.printCourseDetails(model.getCourseName(), model.getCourseId(), model.getCourseCategory());
    }
}

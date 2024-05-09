package com.example;

import com.opensymphony.xwork2.ActionSupport;

public class LoginAction extends ActionSupport {
    private String name;
    private String mobile;
    private String email;

    // Getters and setters

    public String execute() {
        // Perform validation
        if (!isValidName(name)) {
            addActionError("Invalid name");
            return INPUT;
        }

        if (!isValidMobileNumber(mobile)) {
            addActionError("Invalid mobile number");
            return INPUT;
        }

        if (!isValidEmail(email)) {
            addActionError("Invalid email");
            return INPUT;
        }

        return SUCCESS;
    }

    private boolean isValidName(String name) {
        // Implement name validation logic
        return name != null && !name.isEmpty();
    }

    private boolean isValidMobileNumber(String mobile) {
        // Implement mobile number validation logic
        return mobile != null && mobile.matches("\\d{10}");
    }

    private boolean isValidEmail(String email) {
        // Implement email validation logic
        return email != null && email.matches("[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}");
    }
}

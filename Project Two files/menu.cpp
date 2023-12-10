#include "menu.h"
#include "Course.h"
#include "Courses.h"
#include <fstream>

/// <summary>
/// Check if a file exists.
/// </summary>
/// <param name="filename"></param>
bool fileExists(const std::string& filename) {
    std::ifstream file(filename);
    return file.good();
}

void printMenu(void) {
    cout << "Menu:" << endl;
    cout << "  1. Load Data Structure." << endl;
    cout << "  2. Print Course List." << endl;
    cout << "  3. Print Course." << endl;
    cout << "  9. Exit" << endl << endl;
    cout << "What would you like to do? ";
}

void handleChoice(int choice, Courses& courses) {
    switch (choice) {
    case 1: // load file
    {
        string filename = "C:\\Users\\arman\\source\\repos\\ProjectTwo\\Data\\Advising Program Input.csv";
        if (!fileExists(filename)) {
            cout << "Error: File does not exist." << endl;
            break;
        }

        if (courses.getSize() > 0) {
            courses.clear();
        }

        try {
            courses.loadFromCSV(filename);
        }
        catch (const std::exception& ex) {
            cout << "Exception occurred: " << ex.what() << endl;
        }
    }
    break;

    case 2: // print all courses
        try {
            cout << "Here is a sample schedule:" << endl << endl;
            courses.printAll();
        }
        catch (const std::exception& ex) {
            cout << "Exception occurred: " << ex.what() << endl;
        }
        break;

    case 3: // print one course and its prerequisites
        try {
            string courseId;
            cout << "What course do you want to know about? ";
            cin >> courseId;
            courses.printCourse(courseId);
        }
        catch (const std::exception& ex) {
            cout << "Exception occurred: " << ex.what() << endl;
        }
        break;

    case 9: // exit program
        cout << "Thank you for using the course planner!" << endl;
        return; // Returning from the function to exit

    default: // invalid choice
        cout << choice << " is not a valid option." << endl << endl;
        break;
    }
}

void commandLoop(void) {
    int choice = 0;
    Courses courses;

    cout << "Welcome to the course planner." << endl;

    while (true) { // changing to an infinite loop
        cout << endl;
        printMenu();
        if (!(cin >> choice)) {
            cout << "Invalid input. Exiting program." << endl;
            break;
        }

        if (choice == 9) {
            handleChoice(choice, courses);
            break; // Break the loop to exit the program
        }

        handleChoice(choice, courses);
    }
}

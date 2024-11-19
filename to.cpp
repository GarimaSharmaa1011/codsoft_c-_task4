#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Task structure
struct Task {
    string description;
    bool isCompleted;
};

// Function prototypes
void addTask(vector<Task>& tasks);
void viewTasks(const vector<Task>& tasks);
void markTaskCompleted(vector<Task>& tasks);
void removeTask(vector<Task>& tasks);

int main() {
    vector<Task> tasks; // List to store tasks
    int choice;

    cout << "===== TO-DO LIST =====" << endl;

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                cout << "Exiting... Have a productive day!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}

// Function to add a task
void addTask(vector<Task>& tasks) {
    cin.ignore(); // Clear input buffer
    Task newTask;
    cout << "Enter the task description: ";
    getline(cin, newTask.description);
    newTask.isCompleted = false;
    tasks.push_back(newTask);
    cout << "Task added successfully!" << endl;
}

// Function to view tasks
void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available!" << endl;
        return;
    }
    cout << "\nYour Tasks:" << endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i].description
             << " [" << (tasks[i].isCompleted ? "Completed" : "Pending") << "]" << endl;
    }
}

// Function to mark a task as completed
void markTaskCompleted(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available to mark as completed!" << endl;
        return;
    }
    int taskNumber;
    viewTasks(tasks);
    cout << "Enter the task number to mark as completed: ";
    cin >> taskNumber;

    if (taskNumber < 1 || taskNumber > tasks.size()) {
        cout << "Invalid task number!" << endl;
        return;
    }
    tasks[taskNumber - 1].isCompleted = true;
    cout << "Task marked as completed!" << endl;
}

// Function to remove a task
void removeTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available to remove!" << endl;
        return;
    }
    int taskNumber;
    viewTasks(tasks);
    cout << "Enter the task number to remove: ";
    cin >> taskNumber;

    if (taskNumber < 1 || taskNumber > tasks.size()) {
        cout << "Invalid task number!" << endl;
        return;
    }
    tasks.erase(tasks.begin() + taskNumber - 1);
    cout << "Task removed successfully!" << endl;
}

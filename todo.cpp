#include <iostream>
using namespace std;

const int MAX = 100;
string tasks[MAX];
bool completed[MAX];
int taskCount = 0;

void addTask() {
    if (taskCount >= MAX) {
        cout << "Task list is full.\n";
        return;
    }
    cout << "Enter new task: ";
    cin.ignore();
    getline(cin, tasks[taskCount]);
    completed[taskCount] = false;
    taskCount++;
    cout << "Task added.\n";
}

void viewTasks() {
    if (taskCount == 0) {
        cout << "No tasks added yet.\n";
        return;
    }
    for (int i = 0; i < taskCount; i++) {
        cout << i + 1 << ". [" << (completed[i] ? "X" : " ") << "] " << tasks[i] << "\n";
    }
}

void completeTask() {
    int n;
    cout << "Enter task number to mark as completed: ";
    cin >> n;
    if (n < 1 || n > taskCount) {
        cout << "Invalid task number.\n";
        return;
    }
    completed[n - 1] = true;
    cout << "Task marked as completed.\n";
}

void removeTask() {
    int n;
    cout << "Enter task number to remove: ";
    cin >> n;
    if (n < 1 || n > taskCount) {
        cout << "Invalid task number.\n";
        return;
    }
    for (int i = n - 1; i < taskCount - 1; i++) {
        tasks[i] = tasks[i + 1];
        completed[i] = completed[i + 1];
    }
    taskCount--;
    cout << "Task removed.\n";
}

int main() {
    int choice;
    while (true) {
        cout << "\n?? TO-DO LIST\n";
        cout << "1. Add Task\n2. View Tasks\n3. Complete Task\n4. Remove Task\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) addTask();
        else if (choice == 2) viewTasks();
        else if (choice == 3) completeTask();
        else if (choice == 4) removeTask();
        else if (choice == 5) break;
        else cout << "Invalid choice!\n";
    }
    return 0;
}


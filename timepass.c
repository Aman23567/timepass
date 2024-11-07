typedef struct {
    int id;
    char name[NAME_LENGTH];
    int age;
} Student;
Student students[MAX_STUDENTS];
int student_count = 0;

void addStudent() {
    if (student_count >= MAX_STUDENTS) {
        printf("Cannot add more students. Maximum limit reached.\n");
        return;
    }
    Student new_student;
    new_student.id = student_count + 1; // Simple ID assignment
    printf("Enter name: ");
    scanf("%s", new_student.name);
    printf("Enter age: ");
    scanf("%d", &new_student.age);
    students[student_count++] = new_student;
    printf("Student added successfully!\n");
}
void updateStudent() {
    int id;
    printf("Enter student ID to update: ");
    scanf("%d", &id);
    if (id <= 0 || id > student_count) {
        printf("Invalid student ID.\n");
        return;
    }
    Student *student = &students[id - 1];
    printf("Updating student %d:\n", id);
    printf("Current name: %s\n", student->name);
    printf("Enter new name: ");
    scanf("%s", student->name);
    printf("Current age: %d\n", student->age);
    printf("Enter new age: ");
    scanf("%d", &student->age);
    printf("Student updated successfully!\n");
}
  

  void displayStudents() {
    if (student_count == 0) {
        printf("No students to display.\n");
        return;
    }
    printf("Student List:\n");
    for (int i = 0; i < student_count; i++) {
        printf("ID: %d, Name: %s, Age: %d\n", students[i].id, students[i].name, students[i].age);
    }
}


int main() {
    int choice;
    do {
        printf("\nStudent Information Management System\n");
        printf("1. Add Student\n");
        printf("2. Update Student\n");
        printf("3. Delete Student\n");
        printf("4. Display Students\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                updateStudent();
                break;
            case 3:
                deleteStudent();
                break;
            case 4:
                displayStudents();
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

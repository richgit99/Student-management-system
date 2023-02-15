
#include "student.h"


int main()
{
    struct Student *head = NULL; // pointer to the head of the linked list
    // Declaring variables for storing student data
    int choice;
    char name[100];
    char phone[100];
    int rollnumber;
    float percentage;
    int semester;


 // Display main menu
    do{

        printf("________________________________________________________________\n");
        printf("|                                                               |\n");
        printf("|                   STUDENT MANAGEMENT SYSTEM                   |\n");
        printf("|                                                               |\n");
        printf("|   Press 1: To insert student details                          |\n");
        printf("|   Press 2: To search student details                          |\n");
        printf("|   Press 3: To delete student details                          |\n");
        printf("|   Press 4: To update student details                          |\n");
        printf("|   Press 5: To display student details                         |\n");
        printf("|   Press 6: To update student details                          |\n");
        printf("|   Press 7: To sort students in Roll Number wise               |\n");
        printf("|   Press 8: To sort students in increasing percentages order   |\n");
        printf("|   Press 9: Exit                                               |\n");
        printf("|                                                               |\n");
        printf("|_______________________________________________________________|\n");


 // Perform actions based on menu choice

        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
            case 1:
                printf("Enter roll number: ");
                scanf("%d", &rollnumber);
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone number: ");
                scanf("%s", phone);
                printf("Enter percentage: ");
                scanf("%f", &percentage);
                printf("Enter semester: ");
                scanf("%d",&semester);
                // Insert student data into linked list
                head = insert(head,rollnumber, name, phone, percentage,semester);
                break;
            case 2:
             // Get input for roll number to search for
                printf("Enter roll number to search: ");
                scanf("%d", &rollnumber);
                search(head,rollnumber); // Search for student with given roll number
                break;
            case 3:
                printf("Enter roll number to delete: ");  // Get input for roll number to delete
                scanf("%d", &rollnumber);
                  // Delete student with given roll number
                head = Delete(head, rollnumber);
                break;
            case 4:
             // Get input for roll number to update
                printf("Enter roll number to update: ");
                scanf("%d", &rollnumber);
                update(head, rollnumber);
                break;
            case 5:
            // Display all students in the linked list
                display(head);
                break;
            case 6:
             // Update student data in linked list
                 printf("Enter roll number to update: ");
                scanf("%d", &rollnumber);
                update(head, rollnumber);
                break;
            case 7:
            // Sorts the students according to their roll numbers.
                head = sort_by_roll(head);
                display(head);
                break;
            case 8:
            // Sorts the students in increasing order based on their percentages.
                head = sort_by_percentage(head);
                display(head);
                break;
                case 9: {   //to exit the application
                printf("Exited!");
            break;
}

        }

    } while (choice != 9);
}

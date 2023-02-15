#ifndef STUDENT_H
#define STUDENT_H

#include<stdlib.h>
#include<string.h>
#include <stdio.h>

// structure to store student details
struct Student
{
    int rollnumber;  // roll number of student
    int semester;    // current semester of student
    char name[100]; // name of student
    char phone[100];  // phone number of student
    float percentage;   // percentage of student
    struct Student *next;   // pointer to next node in linked list

};

// function to insert new student record in linked list
struct Student * insert(struct Student *head, int rollnumber, char name[100], char phone[100], float percentage,int semester)
{
    struct Student * student = (struct Student *) malloc(sizeof(struct Student));
    // assign student details to the node
    student->rollnumber = rollnumber;
    strcpy(student->name, name);
    strcpy(student->phone, phone);
    student->percentage = percentage;
    student->semester = semester;
    student->next = NULL;

    if(head==NULL)  // insert node at beginning of linked list
    {
        // if head is NULL, set student as the new head
        head = student;
    }
    else{
   // if list is not empty, insert student in beginning of head
        student->next = head;
        head = student;
    }
    // return updated head of linked list
    return head;

}


// searching the student details using their roll no

void search(struct Student *head, int rollnumber)
{
    struct Student * temp = head;
    while(temp!=NULL){                          // traverse through the linked list
        if(temp->rollnumber==rollnumber){
// if roll number is found, print student details
        printf("_______________________________\n");
        printf("|                             |\n");
        printf("|                             |\n");
        printf("    Roll Number: %d             \n", temp->rollnumber);
        printf("    Name: %s                    \n", temp->name);
        printf("    Phone: %s                   \n", temp->phone);
        printf("    Percentage: %0.4f           \n", temp->percentage);
        printf("    Semester: %d                \n",temp->semester);
        printf("|                             |\n");
        printf("|_____________________________|\n");


            return;
        }
        temp = temp->next;
    } // if roll number is not found, print error message
    printf("Student with roll number %d is not found !!!\n", rollnumber);
}
void update(struct Student *head, int rollnumber)     // function to update student details using their roll number
    // takes head of linked list and roll number as input

{

    struct Student * temp = head;
    while(temp!=NULL){                 // traverse through the linked list

        if(temp->rollnumber==rollnumber){                             // if roll number is found, update student details
            printf("Record with roll number %d Found !!!\n", rollnumber);
            printf("Enter new name: ");
            scanf("%s", temp->name);
            printf("Enter new phone number: ");
            scanf("%s", temp->phone);
            printf("Enter new percentage: ");
            scanf("%f",&temp->percentage);
            printf("Enter semester: ");
            scanf("%d",&temp->semester);
            printf("Updation Successful!!!\n");
            return;
        }
        temp = temp->next;

    }                            // if roll number is not found, print error message
    printf("Student with roll number %d is not found !!!\n", rollnumber);

}
struct Student * Delete(struct Student *head, int rollnumber)
{
// two pointers to traverse through the linked list
// temp1 points to current node and temp2 points to previous node

    struct Student * temp1 = head;
    struct Student * temp2 = head;
    while(temp1!=NULL){

        if(temp1->rollnumber==rollnumber){ // if roll number is found, delete the node


            if(temp1==temp2){
                // this condition will run if the record that we need to delete is the first node of the linked list
                head = head->next;
                free(temp1);
            }
            else{
                // temp1 is the node we need to delete temp2 is the node previous to temp1
                temp2->next = temp1->next;
                free(temp1);
            }

            return head; // return updated head of linked list

        } // move temp2 to current node and temp1 to next node
        temp2 = temp1;
        temp1 = temp1->next;

    }

    return head; // return head if roll number is not found

}
void display(struct Student *head)  // function to display all student records in the linked list
{
    struct Student * temp = head;
    while(temp!=NULL){            // traverse through the linked list and print student details
        printf("_______________________________\n");
        printf("|                             |\n");
        printf("|                             |\n");
        printf("    Roll Number: %d             \n", temp->rollnumber);
        printf("    Name: %s                    \n", temp->name);
        printf("    Phone: %s                   \n", temp->phone);
        printf("    Percentage: %0.4f           \n", temp->percentage);
        printf("    Semester: %d                \n",temp->semester);
        printf("|                             |\n");
        printf("|_____________________________|\n");
        temp = temp->next;

    }
}
struct Student * sort(struct Student *head){

    struct Student *temp = NULL;
    struct Student *ptr;
    struct Student *lptr;
    while(head!=NULL){

        ptr = head;
        lptr = head;
        while(ptr!=NULL){
            if(ptr->rollnumber > lptr->rollnumber){
                lptr = ptr;
            }
            ptr = ptr->next;
        }
        temp = insert(temp, lptr->rollnumber, lptr->name, lptr->phone, lptr->percentage,lptr->semester);
        head = Delete(head, lptr->rollnumber);
    }
    return temp;

}

// sorting the students in roll number

struct Student *sort_by_roll(struct Student *head){    // function to sort student records roll number
                                                                // takes head of linked list as input

    struct Student *temp1 = head;
    struct Student *temp2 = head;
    while(temp1 != NULL){
        temp2 = temp1->next;
        while(temp2 != NULL){
            if(temp1->rollnumber > temp2->rollnumber ||  // Add semester as a tie-breaker
               (temp1->rollnumber == temp2->rollnumber && temp1->semester > temp2->semester)){

                struct Student *temp = (struct Student *) malloc(sizeof(struct Student));
                temp->rollnumber = temp1->rollnumber;
                strcpy(temp->name, temp1->name);
                strcpy(temp->phone, temp1->phone);
                temp->percentage = temp1->percentage;
                temp->semester = temp1->semester;
                temp1->rollnumber = temp2->rollnumber;
                strcpy(temp1->name, temp2->name);
                strcpy(temp1->phone, temp2->phone);
                temp1->percentage = temp2->percentage;
                temp1->semester = temp2->semester;
                temp2->rollnumber = temp->rollnumber;
                strcpy(temp2->name, temp->name);
                strcpy(temp2->phone, temp->phone);
                temp2->percentage = temp->percentage;
                temp2->semester = temp->semester;
                free(temp);
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return head; // return head of sorted linked list
}


// sorting the students in increasing order of their percentages

struct Student *sort_by_percentage(struct Student *head){
    // pointers to traverse through the linked list

    struct Student *temp1 = head;   // temp1 points to current node and temp2 points to next node
    struct Student *temp2 = head;
    while(temp1 != NULL){
        temp2 = temp1->next;
        while(temp2 != NULL){   // nested loop to compare each node with all other nodes in the list
            if(temp1->percentage > temp2->percentage ||  // Add semester as a tie-breaker
               (temp1->percentage == temp2->percentage && temp1->semester > temp2->semester)){
                struct Student *temp = (struct Student *) malloc(sizeof(struct Student));  // create a temporary node to store values of temp1
                temp->rollnumber = temp1->rollnumber;
                strcpy(temp->name, temp1->name);
                strcpy(temp->phone, temp1->phone);
                temp->percentage = temp1->percentage;
                temp->semester = temp1->semester;
                temp1->rollnumber = temp2->rollnumber;
                strcpy(temp1->name, temp2->name);
                strcpy(temp1->phone, temp2->phone);
                temp1->percentage = temp2->percentage;
                temp1->semester = temp2->semester;
                temp2->rollnumber = temp->rollnumber;
                strcpy(temp2->name, temp->name);
                strcpy(temp2->phone, temp->phone);
                temp2->percentage = temp->percentage;
                temp2->semester = temp->semester;
                free(temp);
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return head;
}










#endif

//Name - Madhur Bajpai
//Reg. No. - 2022ca047
//Date - 02/05/2023

//Objective - Birthday Program 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[50];
    int reg_no;
    char city[50];
    int day;
    int month;
    int year;
} Student;

// Function to compare students based on their age
int compareAge(const void *a, const void *b) {
    Student* student1 = (Student*)a;
    Student* student2 = (Student*)b;
    if (student1->year != student2->year) {
        return student2->year - student1->year;
    } else if (student1->month != student2->month) {
        return student2->month - student1->month;
    } else {
        return student2->day - student1->day;
    }
}

// Function to print student information
void printStudents(Student students[], int n) {
    printf("Name\tRegistration No.\tCity of Birth\tDate of Birth\n");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\t\t\t%s\t\t%d/%d/%d\n", students[i].name, students[i].reg_no, students[i].city, students[i].day, students[i].month, students[i].year);
    }
    printf("-------------------------------------------------------------\n");
}

// Function to generate happy birthday message for a student
void generateBirthdayMessage(Student student) {
    time_t t = time(NULL);
    struct tm* now = localtime(&t);
    int currentDay = now->tm_mday;
    int currentMonth = now->tm_mon + 1;

    if (student.month == currentMonth && student.day == currentDay) {
        printf("Happy birthday, %s!\n", student.name);
    } else {
        int nextYear = now->tm_year + 1900;
        int nextMonth = student.month;
        int nextDay = student.day;
        if (nextMonth < currentMonth || (nextMonth == currentMonth && nextDay < currentDay)) {
            nextYear++;
        }
        printf("Next birthday for %s will be on %d/%d/%d\n", student.name, nextDay, nextMonth, nextYear);
    }
}

// Driver function
int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    Student students[n];
    for (int i = 0; i < n; i++) {
        printf("Enter information for student %d:\n", i+1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Registration No.: ");
        scanf("%d", &students[i].reg_no);
        printf("City of Birth: ");
        scanf("%s", students[i].city);
        printf("Date of Birth (DD MM YYYY): ");
        scanf("%d %d %d", &students[i].day, &students[i].month, &students[i].year);
    }

    qsort(students, n, sizeof(Student), compareAge);

    printf("Student Information sorted by age:\n");
    printStudents(students, n);

    for (int i = 0; i < n; i++) {
        generateBirthdayMessage(students[i]);
    }

    return 0;
}
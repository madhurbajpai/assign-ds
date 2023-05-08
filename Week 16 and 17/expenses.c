//Name - Madhur Bajpai
//Reg. No. - 2022ca047
//Date - 25/04/2023

//Expense Calculator

#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 50


//defining structure for items for each student
typedef struct {
    char item_name[50];
    int units;
    float price_per_unit;
    float total_cost;
} Item;

//defining structure for the list of students
typedef struct {
	//for storing the name of the student
    char member_name[50];
    //for storing the number of items he purchase
    int num_items;
    //structure for the details of item
    Item items[MAX_ITEMS];
    //for storing the amount a particular person has to pay
    float contribution;
} Member;

// Function to calculate total cost of items
float calculateTotalCost(Item items[], int num_items) {
    float total_cost = 0;
    //iterating through each item with their no. of units and priceperunit
    for (int i = 0; i < num_items; i++) {
        total_cost += items[i].units * items[i].price_per_unit;
    }
    return total_cost;
}

// Function to print items of a member
void printItems(Item items[], int num_items) {
    printf("Item Name\tUnits\tPrice per unit\tTotal cost\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t\t%d\t%.2f\t\t%.2f\n", items[i].item_name, items[i].units, items[i].price_per_unit, items[i].total_cost);
    }
}

// Function to print information of all members
void printMemberInfo(Member members[], int num_members) {
    printf("Member Name\tTotal Contribution\n");
    for (int i = 0; i < num_members; i++) {
        printf("%s\t\t%.2f\n", members[i].member_name, members[i].contribution);
        printf("Items contributed:\n");
        printItems(members[i].items, members[i].num_items);
    }
}

// Driver function
int main() {
    int num_members;
    printf("Enter number of members: ");
    scanf("%d", &num_members);

    Member members[num_members];
    for (int i = 0; i < num_members; i++) {
        printf("Enter information for member %d:\n", i+1);
        printf("Name: ");
        scanf("%s", members[i].member_name);
        printf("Number of items: ");
        scanf("%d", &members[i].num_items);
        for (int j = 0; j < members[i].num_items; j++) {
            printf("Item %d:\n", j+1);
            printf("Item Name: ");
            scanf("%s", members[i].items[j].item_name);
            printf("Units: ");
            scanf("%d", &members[i].items[j].units);
            printf("Price per unit: ");
            scanf("%f", &members[i].items[j].price_per_unit);
            members[i].items[j].total_cost = members[i].items[j].units * members[i].items[j].price_per_unit;
        }
        members[i].contribution = calculateTotalCost(members[i].items, members[i].num_items);
    }

    float total_cost = 0;
    for (int i = 0; i < num_members; i++) {
        total_cost += members[i].contribution;
    }
    float avg_cost = total_cost / num_members;

    printf("Picnic Expenses:\n");
    printMemberInfo(members, num_members);

    printf("Each member should contribute approximately %.2f towards picnic expenses.\n", avg_cost);

    return 0;
}
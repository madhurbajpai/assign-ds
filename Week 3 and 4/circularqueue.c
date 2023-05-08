//Name - Madhur Bajpai
//Reg. No.- 2022CA047
//Date- 31/01/2023
#include <stdio.h>
#include <conio.h>
#include "circularqueue.h"
#define MAX 10

int main()
{
    int option, val;

    //main menu to show operations on circular queue
    do
    {
        printf("\n ***** MAIN MENU *****");
        printf("\n 1. Insert an element");
        printf("\n 2. Delete an element");
        printf("\n 3. Peek");
        printf("\n 4. Display the queue");
        printf("\n 5. EXIT");
        printf("\n Enter your option : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            insert();
            break;
        case 2:
            val = delete_element();
            if (val != -1)
                printf("\n The number deleted is : %d", val);
            break;
        case 3:
            val = peek();
            if (val != -1)
                printf("\n The first value in queue is : %d", val);
            break;
        case 4:
            display();
            break;
        }
    } while (option != 5);

    return 0;
}

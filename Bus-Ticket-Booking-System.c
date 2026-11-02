
#include <stdio.h>

int main()
{
    int seat[10] = {0};
    char name[10][30];
    int choice, s, i;

    do
    {
        printf("\n--- BUS TICKET BOOKING ---\n");
        printf("1. View Seats\n");
        printf("2. Book Ticket\n");
        printf("3. View Bookings\n");
        printf("4. Cancel Ticket\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                for(i = 0; i < 10; i++)
                    printf("Seat %d: %s\n", i+1,
                    seat[i] ? "Booked" : "Available");
                break;

            case 2:
                printf("Enter seat number (1-10): ");
                scanf("%d", &s);

                if(s < 1 || s > 10)
                    printf("Invalid seat!\n");
                else if(seat[s-1])
                    printf("Seat already booked!\n");
                else
                {
                    printf("Enter name: ");
                    scanf(" %29[^\n]", name[s-1]);
                    seat[s-1] = 1;
                    printf("Ticket booked! Price: Rs. 500\n");
                }
                break;

            case 3:
                for(i = 0; i < 10; i++)
                    if(seat[i])
                        printf("Seat %d: %s - Rs. 500\n",
                        i+1, name[i]);
                break;

            case 4:
                printf("Enter seat number: ");
                scanf("%d", &s);

                if(s < 1 || s > 10)
                    printf("Invalid seat!\n");
                else if(!seat[s-1])
                    printf("Seat is not booked!\n");
                else
                {
                    seat[s-1] = 0;
                    printf("Ticket cancelled!\n");
                }
                break;

            case 5:
                printf("Thank you!\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 5);

    return 0;
}

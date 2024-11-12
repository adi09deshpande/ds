#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int prn; // Student PRN
    char name[20];
    struct node *next;
};

struct node *head = 0, *newnode, *temp;

void make_node()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter PRN: ");
    scanf("%d", &newnode->prn);
    printf("Enter Name: ");
    scanf("%s", newnode->name);
}
void create_node()
{
    make_node();
    newnode->next = 0;
    if (head == 0)
    {
        head = temp = newnode;
    }
    else
    {
        temp->next = newnode;
        temp = newnode;
    }
}

// void display()
// {
//     if (head == 0)
//     {
//         printf("\nThere are no members in the club!");
//     }

//     temp = head;
//     while (temp != 0)
//     {
//         printf("PRN: %d, Name: %s\n", temp->prn, temp->name);
//         temp = temp->next;
//     }
// }
void display()
{
    if (head == 0)
    {
        printf("\nThere are no members in the club!\n");
    }
    else
    {
        printf("\n-----------MEMBERS OF THE CLUB------------\n");
        temp = head;
        int position = 0; // To track the position of the current node
        while (temp != 0)
        {
            // Print PRN and Name for each member
            printf("\nPRN: %d, Name: %s", temp->prn, temp->name);

            // Check if the current node is the president (first node)
            if (position == 0)
            {
                printf(" (President)");
            }
            // Check if the current node is the secretary (last node)
            else if (temp->next == 0)
            {
                printf(" (Secretary)");
            }

            printf("\n"); // Newline for each member
            temp = temp->next;
            position++; // Increment position
        }
    }
}

int count()
{
    int count = 0;
    temp = head;
    while (temp != 0)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void insert_beginning()
{
    if (head == 0)
    {
        printf("\nPlease create linked list first !!");
    }
    else
    {
        make_node();
        newnode->next = head;
        head = newnode;
        printf("\nPresident Added !!");
    }
}
void insert_end()
{
    if (head == 0)
    {
        printf("\nPlease create linked list first !!");
    }
    else
    {
        make_node();
        temp = head;
        while (temp->next != 0)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = 0;
        printf("\nSecretary Added !!");
    }
}

void insert_pos()
{
    if (head == 0)
    {
        printf("\nPlease create linked list first !!");
    }
    else
    {
        int pos;
        printf("Enter the position at which u want to insert:");
        scanf("%d", &pos);
        if (pos < 1)
        {
            printf("Invalid position");
        }
        else
        {
            if (pos == 1)
            {
                printf("1st Position is reserved for President !!");
            }
            else if (pos == count()+1)
            {
                printf("Last Position is reserved for Seceratary !!");
            }
            else
            {
                make_node();
                int i = 1;
                temp = head;
                while (i < pos-1)
                {
                    temp = temp->next;
                    i++;
                }
                newnode->next = temp->next;
                temp->next = newnode;

                /* OR
                make_node();
                temp = head;

                while (--pos > 0)
                {
                    temp = temp->next;
                }

                newnode->next = temp->next;
                temp->next = newnode;
                */
                printf("\nMember Added");
            }
        }
    }
}

void delete_beginning()
{
    if (head == 0)
    {
        printf("\nThere are no members in the club!");
    }
    else
    {
        temp = head;
        head = head->next;
        free(temp);
        printf("\nPresident deleted !! ");
    }
}

void delete_end()
{
    if (head == 0)
    {
        printf("\nThere are no members in the club!");
    }
    else if (head->next == 0)
    {
        // free(head);
        // head = 0;
        // printf("\nLast element deleted !! ");
        printf("There is no secretary as of now !!");
    }
    else
    {
        temp = head;
        while (temp->next->next != 0)
        {
            temp = temp->next;
        }
        // temp is now the second-last node
        free(temp->next); // Free the last node
        temp->next = 0;   // Set next of second-last node to 0
        printf("\nSecretary deleted !! ");
    }
}

void delete_pos()
{
    struct node *node_to_delete;
    if (head == 0)
    {
        printf("\nThere are no members in the club!");
    }
    else
    {
        int pos;
        printf("Enter the position which you want to delete: ");
        scanf("%d", &pos);
        if (pos <= 0 || pos > count())
        {
            printf("Invalid Position");
        }
        else if (pos == 1)
        {
            printf("Cannot  delete the president !!");
        }
        else if (pos == count())
        {
            printf("Cannot delete the secretary !!");
        }
        else
        {
            int i = 1;
            temp = head;
            while (i < pos - 1)
            {
                temp = temp->next;
                i++;
            }
            node_to_delete = temp->next;
            temp->next = node_to_delete->next;
            free(node_to_delete);
            printf("\nMember deleted");
        }
    }
}

void reverse()
{
    struct node *prev = 0;
    struct node *nextnode;
    temp = nextnode = head;
    while (nextnode != 0)
    {
        nextnode = nextnode->next;
        temp->next = prev;
        prev = temp;
        temp = nextnode;
    }
    head = prev;
}

void sort()
{
    struct node *nextnode;
    int tPRN;
    char tName[20];

    temp = head;
    while (temp->next != 0)
    {
        nextnode = temp->next;
        while (nextnode != 0)
        {
            if (temp->prn > nextnode->prn)
            {
                tPRN = temp->prn;
                temp->prn = nextnode->prn;
                nextnode->prn = tPRN;

                strcpy(tName, temp->name);
                strcpy(temp->name, nextnode->name);
                strcpy(nextnode->name, tName);
            }
            nextnode = nextnode->next;
        }
        temp = temp->next;
    }
}

int main()
{
    int choice;
    printf("\nSELECT:\n1.Create node\n2.Display\n3.Count Members\n4.Add New president\n5.Add New secretary\n6.Add Member\n7.Delete President\n8.Delete Secretary\n9.Delete Members\n10.Reverse\n11.Sort\n12.Exit");
    do
    {
        printf("\n\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create_node();
            break;
        case 2:
            display();
            break;
        case 3:
            printf("The number of members in the club are:  %d\n", count());
            break;
        case 4:
            insert_beginning();
            break;
        case 5:
            insert_end();
            break;
        case 6:
            insert_pos();
            break;
        case 7:
            delete_beginning();
            break;
        case 8:
            delete_end();
            break;
        case 9:
            delete_pos();
            break;
        case 10:
            reverse();
            break;
        case 11:
            sort();
            break;
        case 12:
            return 0;
            break;

        default:
            printf("\nPlease enter a valid choice !! ");
            break;
        }
    } while (choice != 12);
    return 0;
}

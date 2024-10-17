#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store property details
typedef struct Property {
    char address[100];
    int bhk;
    float area;
    float price;
} Property;

// Function prototypes
void addRecord();
void displayRecords();
void searchRecords();
void buyOrSellRecord();
void editRecord();
void deleteRecord();

// Global variables
Property properties[100]; // Array to store property details
int numProperties = 0; // Number of properties currently stored

int main() {
    int choice;
    
    // Menu-driven program loop
    do {
        printf("\n---------------> Real Estate Advisor Program <--------------\n");
        printf("1. Add New Record\n");
        printf("2. Display Available Properties\n");
        printf("3. Search Properties\n");
        printf("4. Buy or Sell Property\n");
        printf("5. Edit Record\n");
        printf("6. Delete Record\n");
        printf("0. Exit\n");
        printf("Enter your choice:----------------------------------------------------------------\n ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addRecord();
                break;
            case 2:
                displayRecords();
                break;
            case 3:
                searchRecords();
                break;
            case 4:
                buyOrSellRecord();
                break;
            case 5:
                editRecord();
                break;
            case 6:
                deleteRecord();
                break;
            case 0:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}

void addRecord() {
    // Prompt user to enter property details
    Property property;
    printf("\nEnter Property Details:\n");
    printf("Address: ");
    scanf("%s", property.address);
    printf("BHK: ");
    scanf("%d", &property.bhk);
    printf("Area (in sq.ft.): ");
    scanf("%f", &property.area);
    printf("Price: ");
    scanf("%f", &property.price);
    
    // Add property to array
    properties[numProperties++] = property;
    
    printf("Record added successfully.\n");
}

void displayRecords() {
    // Display header
    printf("\n%-15s %-5s %-10s %-10s\n", "Address", "BHK", "Area", "Price");
    
    // Display each property in array
    for (int i = 0; i < numProperties; i++) {
        printf("%-15s %-5d %-10.2f %-10.2f\n", properties[i].address, properties[i].bhk, properties[i].area, properties[i].price);
    }
}
// Function to search for properties
void searchRecords() {
    // Prompt user to enter search criteria
    float maxPrice, minArea;
    printf("\nEnter Search Criteria:\n");
    printf("Maximum Price: ");
    scanf("%f", &maxPrice);
    printf("Minimum Area (in sq.ft.): ");
    scanf("%f", &minArea);

    // Search for properties matching criteria and display results
    printf("\nProperties matching search criteria:\n");
    printf("%-15s %-5s %-10s %-10s\n", "Address", "BHK", "Area", "Price");
    for (int i = 0; i < numProperties; i++) {
        if (properties[i].price <= maxPrice && properties[i].area >= minArea) {
            printf("%-15s %-5d %-10.2f %-10.2f\n", properties[i].address, properties[i].bhk, properties[i].area, properties[i].price);
        }
    }
}

// Function to buy or sell a property
void buyOrSellRecord() {
    int choice, index;
    float offer;

    // Prompt user to enter property index and offer
    printf("\nEnter Property Index: ");
    scanf("%d", &index);
    printf("Enter Offer: ");
    scanf("%f", &offer);

    // Prompt user to buy or sell property
    printf("\nWhat do you want to do?\n");
    printf("1. Buy Property\n");
    printf("2. Sell Property\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Perform buy or sell operation
    if (choice == 1) {
        if (offer >= properties[index].price) {
            printf("Congratulations! Property bought.\n");
        } else {
            printf("Offer rejected. Please try again with a higher offer.\n");
        }
    } else if (choice == 2) {
        properties[index].price = offer;
        printf("Property price updated successfully.\n");
    } else {
        printf("Invalid choice. Please try again.\n");
    }
}

// Function to edit a property record
void editRecord() {
    int index;

    // Prompt user to enter property index
    printf("\nEnter Property Index: ");
    scanf("%d", &index);

    // Prompt user to enter new property details
    printf("\nEnter New Property Details:\n");
    printf("Address: ");
    scanf("%s", properties[index].address);
    printf("BHK: ");
    scanf("%d", &properties[index].bhk);
    printf("Area (in sq.ft.): ");
    scanf("%f", &properties[index].area);
    printf("Price: ");
    scanf("%f", &properties[index].price);

    printf("Record updated successfully.\n");
}

// Function to delete a property record
void deleteRecord() {
    int index;

    // Prompt user to enter property index
    printf("\nEnter Property Index: ");
    scanf("%d", &index);

    // Shift all properties after the deleted property left by one position
    for (int i = index; i < numProperties - 1; i++) {
        properties[i] = properties[i + 1];
    }

    numProperties--;
    printf("Record deleted successfully.\n");
}

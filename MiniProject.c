#include <stdio.h>

// Define constants for array sizes
#define MAX_PROPERTIES 100
#define MAX_CLIENTS 100
#define MAX_INQUIRIES 100
#define MAX_VIEWINGS 100
#define MAX_TRANSACTIONS 100

// Define structures for Property, Client, Inquiry, Viewing, and Transaction
typedef struct {
    int id;
    char address[100];
    float price;
    int bedrooms;
    int bathrooms;
    int isAvailable;
} Property;

typedef struct {
    int id;
    char name[50];
    char phone[15];
    char email[50];
} Client;

typedef struct {
    int id;
    int propertyId;
    int clientId;
    char date[11];
} Inquiry;

typedef struct {
    int id;
    int propertyId;
    int clientId;
    char date[11];
    char time[6];
} Viewing;

typedef struct {
    int id;
    int propertyId;
    int clientId;
    float finalPrice;
    char date[11];
} Transaction;

// Arrays to store entities
Property properties[MAX_PROPERTIES];
Client clients[MAX_CLIENTS];
Inquiry inquiries[MAX_INQUIRIES];
Viewing viewings[MAX_VIEWINGS];
Transaction transactions[MAX_TRANSACTIONS];

// Counters to track the number of entities
int propertyCount = 0;
int clientCount = 0;
int inquiryCount = 0;
int viewingCount = 0;
int transactionCount = 0;

void addProperty() {
    if (propertyCount >= MAX_PROPERTIES) {
        printf("Property list is full.\n");
        return;
    }

    Property *property = &properties[propertyCount];
    printf("Enter Property ID: ");
    scanf("%d", &property->id);
    printf("Enter Address: ");
    scanf(" %[^\n]", property->address);
    printf("Enter Price: ");
    scanf("%f", &property->price);
    printf("Enter Bedrooms: ");
    scanf("%d", &property->bedrooms);
    printf("Enter Bathrooms: ");
    scanf("%d", &property->bathrooms);
    property->isAvailable = 1;

    propertyCount++;
    printf("Property added successfully.\n");
}

void listProperties() {
    printf("ID\tAddress\t\tPrice\tBedrooms\tBathrooms\tAvailable\n");
    for (int i = 0; i < propertyCount; i++) {
        Property *property = &properties[i];
        printf("%d\t%s\t%.2f\t%d\t\t%d\t\t%d\n", property->id, property->address, property->price, property->bedrooms, property->bathrooms, property->isAvailable);
    }
}


void addInquiry() {
    if (inquiryCount >= MAX_INQUIRIES) {
        printf("Inquiry list is full.\n");
        return;
    }

    Inquiry *inquiry = &inquiries[inquiryCount];
    printf("Enter Inquiry ID: ");
    scanf("%d", &inquiry->id);
    printf("Enter Property ID: ");
    scanf("%d", &inquiry->propertyId);
    printf("Enter Client ID: ");
    scanf("%d", &inquiry->clientId);
    printf("Enter Date (YYYY-MM-DD): ");
    scanf("%s", inquiry->date);

    inquiryCount++;
    printf("Inquiry added successfully.\n");
}

void listInquiries() {
    printf("ID\tProperty ID\tClient ID\tDate\n");
    for (int i = 0; i < inquiryCount; i++) {
        Inquiry *inquiry = &inquiries[i];
        printf("%d\t%d\t\t%d\t\t%s\n", inquiry->id, inquiry->propertyId, inquiry->clientId, inquiry->date);
    }
}

void addViewing() {
    if (viewingCount >= MAX_VIEWINGS) {
        printf("Viewing list is full.\n");
        return;
    }

    Viewing *viewing = &viewings[viewingCount];
    printf("Enter Viewing ID: ");
    scanf("%d", &viewing->id);
    printf("Enter Property ID: ");
    scanf("%d", &viewing->propertyId);
    printf("Enter Client ID: ");
    scanf("%d", &viewing->clientId);
    printf("Enter Date (YYYY-MM-DD): ");
    scanf("%s", viewing->date);
    printf("Enter Time (HH:MM): ");
    scanf("%s", viewing->time);

    viewingCount++;
    printf("Viewing scheduled successfully.\n");
}

void listViewings() {
    printf("ID\tProperty ID\tClient ID\tDate\t\tTime\n");
    for (int i = 0; i < viewingCount; i++) {
        Viewing *viewing = &viewings[i];
        printf("%d\t%d\t\t%d\t\t%s\t%s\n", viewing->id, viewing->propertyId, viewing->clientId, viewing->date, viewing->time);
    }
}

void addTransaction() {
    if (transactionCount >= MAX_TRANSACTIONS) {
        printf("Transaction list is full.\n");
        return;
    }

    Transaction *transaction = &transactions[transactionCount];
    printf("Enter Transaction ID: ");
    scanf("%d", &transaction->id);
    printf("Enter Property ID: ");
    scanf("%d", &transaction->propertyId);
    printf("Enter Client ID: ");
    scanf("%d", &transaction->clientId);
    printf("Enter Final Price: ");
    scanf("%f", &transaction->finalPrice);
    printf("Enter Date (YYYY-MM-DD): ");
    scanf("%s", transaction->date);

    transactionCount++;
    printf("Transaction recorded successfully.\n");
}

void listTransactions() {
    printf("ID\tProperty ID\tClient ID\tFinal Price\tDate\n");
    for (int i = 0; i < transactionCount; i++) {
        Transaction *transaction = &transactions[i];
        printf("%d\t%d\t\t%d\t\t%.2f\t\t%s\n", transaction->id, transaction->propertyId, transaction->clientId, transaction->finalPrice, transaction->date);
    }
}

int main() {
    int choice;
    while (1) {
        printf("Real Estate Management System\n");
        printf("1. Add Property\n");
        printf("2. List Properties\n");
        printf("3. Add Inquiry\n");
        printf("4. List Inquiries\n");
        printf("5. Schedule Viewing\n");
        printf("6. List Viewings\n");
        printf("7. Record Transaction\n");
        printf("8. List Transactions\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProperty();
                break;
            case 2:
                listProperties();
                break;
            case 3:
                addInquiry();
                break;
            case 4:
                listInquiries();
                break;
            case 5:
                addViewing();
                break;
            case 6:
                listViewings();
                break;
            case 7:
                addTransaction();
                break;
            case 8:
                listTransactions();
                break;
            case 9:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}


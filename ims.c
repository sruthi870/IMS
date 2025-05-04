#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent an inventory item
typedef struct Item {
    int id;
    char name[50];
    int quantity;
    float price;
    struct Item* next;
} Item;

Item* head = NULL;

// Function to create a new item node
Item* createItem(int id, const char* name, int quantity, float price) {
    Item* newItem = (Item*)malloc(sizeof(Item));
    newItem->id = id;
    strcpy(newItem->name, name);
    newItem->quantity = quantity;
    newItem->price = price;
    newItem->next = NULL;
    return newItem;
}

// Add item to inventory
void addItem(int id, const char* name, int quantity, float price) {
    Item* newItem = createItem(id, name, quantity, price);
    newItem->next = head;
    head = newItem;
    printf("Item added successfully.\n");
}

// Display all items
void displayItems() {
    if (head == NULL) {
        printf("Inventory is empty.\n");
        return;
    }
    Item* temp = head;
    printf("ID\tName\t\tQuantity\tPrice\n");
    while (temp != NULL) {
        printf("%d\t%-10s\t%d\t\t%.2f\n", temp->id, temp->name, temp->quantity, temp->price);
        temp = temp->next;
    }
}

// Search item by ID
void searchItem(int id) {
    Item* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            printf("Item found: %s, Quantity: %d, Price: %.2f\n", temp->name, temp->quantity, temp->price);
            return;
        }
        temp = temp->next;
    }
    printf("Item with ID %d not found.\n", id);
}

// Delete item by ID
void deleteItem(int id) {
    Item *temp = head, *prev = NULL;
    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Item not found.\n");
        return;
    }
    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
    printf("Item deleted successfully.\n");
}

// Main menu
int main() {
    int choice, id, quantity;
    float price;
    char name[50];

    while (1) {
        printf("\nInventory Management System\n");
        printf("1. Add Item\n2. Display Items\n3. Search Item\n4. Delete Item\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Quantity: ");
                scanf("%d", &quantity);
                printf("Enter Price: ");
                scanf("%f", &price);
                addItem(id, name, quantity, price);
                break;
            case 2:
                displayItems();
                break;
            case 3:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                searchItem(id);
                break;
            case 4:
                printf("Enter ID to delete: ");
                scanf("%d", &id);
                deleteItem(id);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
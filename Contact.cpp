#include <iostream>
#include <string>
using namespace std;
struct Contact {
    string name;
    string phoneNumber;
    string email;
    string location;
};
class ContactManager {
private:
    const static int MAX_CONTACTS = 100;
    Contact contacts[MAX_CONTACTS];
    int numContacts;
public:
    ContactManager() : numContacts(0) {}
void addContact(const Contact& newContact) {
        if (numContacts >= MAX_CONTACTS) {
            cout << "Contact list is full!" << endl;
            return;
        }
contacts[numContacts] = newContact;
        numContacts++;
        cout << "Contact added successfully!" << endl << endl;
    }
void displayAllContacts() {
        if (numContacts == 0) {
            cout << "No contacts available" << endl << endl;
            return;
        }
cout << "Contacts:" << endl;
        for (int i = 0; i < numContacts; ++i) {
            cout << "Name: " << contacts[i].name << endl;
            cout << "Phone Number: " << contacts[i].phoneNumber << endl;
            cout << "Email: " << contacts[i].email << endl;
            cout << "Location: " << contacts[i].location << endl;
            cout<<endl;
        }
    }
void searchContact(const string& name) {
        bool found = false;
        for (int i = 0; i < numContacts; ++i) {
            if (contacts[i].name == name) {
                found = true;
                cout << "Contact found:" << endl;
                cout << "Name: " << contacts[i].name << endl;
                cout << "Phone Number: " << contacts[i].phoneNumber << endl;
                cout << "Email: " << contacts[i].email << endl;
                cout << "Location: " << contacts[i].location << endl << endl;
                break;
            }
        }
        if (!found) {
            cout << "Contact not found" << endl<< endl;
            cout<<endl;
        }
    }
void deleteContact(const string& name) {
        bool found = false;
        for (int i = 0; i < numContacts; ++i) {
            if (contacts[i].name == name) {
                found = true;
                for (int j = i; j < numContacts - 1; ++j) {
                    contacts[j] = contacts[j + 1];
                }
                numContacts--;
                cout << "Contact deleted successfully!" << endl <<endl;
                break;
}
        }
        if (!found) {
            cout << "Contact not found" << endl<< endl;
        }
    }
};
int main() {
    ContactManager manager;
    int choice;
    Contact newContact;
    string searchName, deleteName;
do {
        cout << "------ Contact Management System ------   " << endl<< endl;
        cout << "1. Add Contact" << endl;
        cout << "2. Display All Contacts" << endl;
        cout << "3. Search Contact" << endl;
        cout << "4. Delete Contact" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: "<<endl;
        cin >> choice;
switch (choice) {
            case 1:
                cout << "Enter Name: ";
                cin >> newContact.name;
                cout << "Enter Phone Number: ";
                cin >> newContact.phoneNumber;
                cout << "Enter Email: ";
                cin >> newContact.email;
                cout << "Location: ";
                cin >> newContact.location;
                manager.addContact(newContact);
                break;
            case 2:
                manager.displayAllContacts();
                break;
            case 3:
                cout << "Enter Name to Search: ";
                cin >> searchName;
                manager.searchContact(searchName);
                break;
            case 4:
                cout << "Enter Name to Delete: ";
                cin >> deleteName;
                manager.deleteContact(deleteName);
                break;
            case 5:
                cout << "Exited";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
                break;
        }
    } while (choice != 5);
return 0;
}

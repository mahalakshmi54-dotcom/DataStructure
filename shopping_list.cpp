#include <iostream>
#include <string>
using namespace std;

int main() {
    string items[100], item;
    int n = 0, choice, pos;

    do {
        cout << "\n1. Add Item\n2. Remove Item\n";
        cout << "3. Search Item\n4. Display Items\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (n == 100) {
                cout << "Shopping list is full!\n";
                break;
            }
            cout << "Enter item: ";
            cin >> item;
            items[n++] = item;
            cout << "Item added.\n";
            break;

        case 2:
            cout << "Enter item to remove: ";
            cin >> item;
            pos = -1;
            for (int i = 0; i < n; i++) {
                if (items[i] == item) {
                    pos = i;
                    break;
                }
            }
            if (pos == -1) {
                cout << "Item not found.\n";
            } else {
                for (int i = pos; i < n - 1; i++)
                    items[i] = items[i + 1];
                n--;
                cout << "Item removed.\n";
            }
            break;

        case 3:
            cout << "Enter item to search: ";
            cin >> item;
            pos = -1;
            for (int i = 0; i < n; i++) {
                if (items[i] == item) {
                    pos = i;
                    break;
                }
            }
            if (pos == -1)
                cout << "Item not found.\n";
            else
                cout << "Item found at position " << pos + 1 << ".\n";
            break;

        case 4:
            if (n == 0)
                cout << "Shopping list is empty.\n";
            else {
                cout << "Shopping List: ";
                for (int i = 0; i < n; i++)
                    cout << items[i] << " ";
                cout << endl;
            }
            break;

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}

#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> garage;
    int choice, car;

    do {
        cout << "\n1. Enter Car\n2. Remove Car\n";
        cout << "3. Display Cars\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter car number: ";
            cin >> car;
            garage.push(car);
            cout << "Car entered the garage.\n";
            break;

        case 2:
            if (garage.empty())
                cout << "Garage is empty.\n";
            else {
                cout << "Car " << garage.top()
                     << " leaves the garage.\n";
                garage.pop();
            }
            break;

        case 3: {
            if (garage.empty()) {
                cout << "Garage is empty.\n";
                break;
            }

            stack<int> temp = garage;
            cout << "Cars from exit to entrance: ";
            while (!temp.empty()) {
                cout << temp.top() << " ";
                temp.pop();
            }
            cout << endl;
            break;
        }

        case 4:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}

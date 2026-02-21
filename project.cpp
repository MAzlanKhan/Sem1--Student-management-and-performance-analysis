#include <iostream>
using namespace std;

int main() {
    int choice, n = 0, index;
    float budget = 0, expenses[50], total = 0;
    string category[50], key;

    cout << "========== Monthly Budget System ==========\n";
    cout << "Enter Monthly Budget: ";
    cin >> budget;

    do {
        cout << "\n-------------- MENU --------------\n";
        cout << "1. Add Expense\n";
        cout << "2. View All Expenses\n";
        cout << "3. Edit Expense\n";
        cout << "4. Delete Expense\n";
        cout << "5. Search Expense\n";
        cout << "6. Total Expenses\n";
        cout << "7. Budget Status\n";
        cout << "8. Highest & Lowest Expense\n";
        cout << "9. Average Expense\n";
        cout << "10. Expense Percentage\n";
        cout << "11. Clear All Expenses\n";
        cout << "12. Update Monthly Budget\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1: // Add expense
            if (n < 50) {
                cout << "Enter Expense Category: ";
                cin >> category[n];
                cout << "Enter Amount: ";
                cin >> expenses[n];
                total += expenses[n];
                n++;
                cout << "Expense Added Successfully!\n";
            } else {
                cout << "Maximum limit reached!\n";
            }
            break;

        case 2: // View expenses
            if (n == 0) {
                cout << "No expenses found.\n";
            } else {
                cout << "\nCategory\tAmount\n";
                for (int i = 0; i < n; i++) {
                    cout << category[i] << "\t\t" << expenses[i] << endl;
                }
            }
            break;

        case 3: // Edit expense
            cout << "Enter expense number to edit (1-" << n << "): ";
            cin >> index;
            if (index > 0 && index <= n) {
                total -= expenses[index - 1];
                cout << "Enter New Category: ";
                cin >> category[index - 1];
                cout << "Enter New Amount: ";
                cin >> expenses[index - 1];
                total += expenses[index - 1];
                cout << "Expense Updated!\n";
            } else {
                cout << "Invalid number!\n";
            }
            break;

        case 4: // Delete expense
            cout << "Enter expense number to delete (1-" << n << "): ";
            cin >> index;
            if (index > 0 && index <= n) {
                total -= expenses[index - 1];
                for (int i = index - 1; i < n - 1; i++) {
                    category[i] = category[i + 1];
                    expenses[i] = expenses[i + 1];
                }
                n--;
                cout << "Expense Deleted!\n";
            } else {
                cout << "Invalid number!\n";
            }
            break;

        case 5: // Search expense
            cout << "Enter category to search: ";
            cin >> key;
            for (int i = 0; i < n; i++) {
                if (category[i] == key) {
                    cout << "Found: " << category[i]
                         << " = " << expenses[i] << endl;
                    break;
                }
                if (i == n - 1)
                    cout << "Expense not found!\n";
            }
            break;

        case 6: // Total
            cout << "Total Expenses = " << total << endl;
            break;

        case 7: // Budget status
            if (total > budget)
                cout << "Over Budget by " << total - budget << endl;
            else
                cout << "Remaining Budget = " << budget - total << endl;
            break;

        case 8: // Max & Min
            if (n > 0) {
                float max = expenses[0], min = expenses[0];
                for (int i = 1; i < n; i++) {
                    if (expenses[i] > max) max = expenses[i];
                    if (expenses[i] < min) min = expenses[i];
                }
                cout << "Highest Expense = " << max << endl;
                cout << "Lowest Expense = " << min << endl;
            } else {
                cout << "No expenses available.\n";
            }
            break;

        case 9: // Average
            if (n > 0)
                cout << "Average Expense = " << total / n << endl;
            else
                cout << "No expenses available.\n";
            break;

        case 10: // Percentage
            if (budget > 0)
                cout << "Expense Percentage = "
                     << (total / budget) * 100 << "%\n";
            else
                cout << "Budget not set.\n";
            break;

        case 11: // Clear all
            n = 0;
            total = 0;
            cout << "All expenses cleared!\n";
            break;

        case 12: // Update budget
            cout << "Enter new monthly budget: ";
            cin >> budget;
            cout << "Budget updated successfully!\n";
            break;

        case 0:
            cout << "Program terminated.\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
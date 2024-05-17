#include <iostream>
#include "kolejka.h"

using namespace std;

void displayMenu() {
    cout << "\nMenu:\n";
    cout << "1 - Dodaj liczbe do kolejki (Push)\n";
    cout << "2 - Sprawdz wartosc pierwszego elementu (Top)\n";
    cout << "3 - Usun pierwszy element (Pop)\n";
    cout << "4 - Czy kolejka jest pusta?\n";
    cout << "5 - Czy kolejka jest pelna?\n";
    cout << "6 - Zakoncz program\n";
    cout << endl;
}

int main() {
    int value = 0;
    int choice = 0;

    while (true) {
        displayMenu();
        cout << "Wybierz opcje: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (!isQueueFull()) {
                    cout << "Podaj wartosc: ";
                    cin >> value;
                    enqueue(value);
                } else {
                    cout << "Operacja niemozliwa, kolejka jest pelna!\n\n";
                }
                break;

            case 2:
                if (!isQueueEmpty()) {
                    cout << "Wartosc pierwszego elementu: " << front() << endl;
                } else {
                    cout << "Operacja niemozliwa, kolejka jest pusta!\n";
                }
                break;

            case 3:
                if (!isQueueEmpty()) {
                    dequeue();
                    if (!isQueueEmpty()) {
                        cout << "Nowy pierwszy element: " << front() << endl;
                    } else {
                        cout << "Kolejka jest teraz pusta.\n";
                    }
                } else {
                    cout << "Operacja niemozliwa, kolejka jest pusta!\n";
                }
                break;

            case 4:
                cout << (isQueueEmpty() ? "Kolejka jest pusta." : "Kolejka nie jest pusta.") << endl;
                break;

            case 5:
                cout << (isQueueFull() ? "Kolejka jest pelna." : "Kolejka nie jest pelna.") << endl;
                break;

            case 6:
                cout << "Koniec programu.\n";
                return 0;

            default:
                cout << "Nieprawidlowa opcja. Sprobuj ponownie.\n";
                break;
        }
    }

    return 0;
}
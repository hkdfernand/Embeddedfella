// CarManagements.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Fernand havugimana
//copy right 2023

#include <iostream>
#include <string>

using namespace std;

// Base Car class
class Car {
protected:
    string vehicleId;
    int mileage;

public:
    Car(string id, int m) : vehicleId(id), mileage(m) {}

    virtual void displayInfo() = 0;

    string getVehicleId() const {
        return vehicleId;
    }

    int getMileage(int m)
    { 
        mileage = m;
        return mileage;
    }
};

// ElectricCar derived from Car
class ElectricCar : 
    public Car 
{
private:
    int chargeLevel;

public:
    ElectricCar(string id, int m, int charge) : Car(id, m), chargeLevel(charge) {}

    void displayInfo() override {
        cout << "Vehicle ID: " << vehicleId << endl;
        cout << "Mileage: " << mileage << " miles" << endl;
        cout << "Charge Level: " << chargeLevel << "%" << endl;
    }

    int getChargeLevel() const {
        return chargeLevel;
    }

    void setChargeLevel(int charge) {
        chargeLevel = charge;
    }
};

// GasolineCar derived from Car
class GasolineCar : public Car {
private:
    double fuelAmount;

public:
    GasolineCar(string id, int m, double fuel) : Car(id, m), fuelAmount(fuel) {}

    void displayInfo() override {
        cout << "Vehicle ID: " << vehicleId << endl;
        cout << "Mileage: " << mileage << " miles" << endl;
        cout << "Fuel Amount: " << fuelAmount << " gallons" << endl;
    }

    double getFuelAmount() const {
        return fuelAmount;
    }

    void setFuelAmount(double fuel) {
        fuelAmount = fuel;
    }
};

const int MAX_CARS = 5;


int main()
{
    Car* rentedCars[MAX_CARS];
    Car* availableCars[MAX_CARS];

    int rentedCount = 0;
    int availableCount = 0;

    while (true) 
    {
        cout << "Main Menu:" << endl;
        cout << "a) Add a car" << endl;
        cout << "b) Display a list of rented cars" << endl;
        cout << "c) Display a list of available cars" << endl;
        cout << "d) Rent a car" << endl;
        cout << "e) Return a rental car" << endl;
        cout << "f) Exit the program" << endl;
        cout << "Enter your choice: ";

        char choice;
        cin >> choice;

        switch (choice)
        {
        case 'a': {
            string id;
            int mileage;
            int chargeLevel;
            double fuelAmount;

            cout << "Enter vehicle identification number: ";
            cin >> id;
            cout << "Enter mileage: ";
            cin >> mileage;

            cout << "Is the car electric? (y/n): ";
            char electricChoice;
            cin >> electricChoice;

            if (electricChoice == 'y' || electricChoice == 'Y')
            {
                cout << "Enter charge level (0-100%): ";
                cin >> chargeLevel;

                if (availableCount >= MAX_CARS) 
                {
                    cout << "Cannot add more than five cars." << endl;
                    break;
                }

                availableCars[availableCount] = new ElectricCar(id, mileage, chargeLevel);
                availableCount++;
                cout << "Car added successfully." << endl;
            }
            else {
                cout << "Enter fuel amount in gallons: ";
                cin >> fuelAmount;

                if (availableCount >= MAX_CARS) {
                    cout << "Cannot add more than five cars." << endl;
                    break;
                }

                availableCars[availableCount] = new GasolineCar(id, mileage, fuelAmount);
                availableCount++;
                cout << "Car added successfully." << endl;
            }
            break;
        }


        case 'b': 
        {
            cout << "List of rented cars:" << endl;
            for (int i = 0; i < rentedCount; i++)
            {
                rentedCars[i]->displayInfo();
                cout << endl;
            }
            break;
        }

        case 'c': {
            cout << "List of available cars:" << endl;
            for (int i = 0; i < availableCount; i++) {
                availableCars[i]->displayInfo();
                cout << endl;
            }
            break;
        }

        case 'd': {
            if (availableCount == 0) {
                cout << "No cars available for renting." << endl;
                break;
            }

            string customerName;
            int carIndex;

            cout << "Enter your name: ";
            cin.ignore();
            getline(cin, customerName);

            cout << "Choose a car to rent (enter car index): " << endl;
            for (int i = 0; i < availableCount; i++) {
                cout << i << ") ";
                availableCars[i]->displayInfo();
                cout << endl;
            }

            cin >> carIndex;

            if (carIndex >= 0 && carIndex < availableCount) {
                rentedCars[rentedCount] = availableCars[carIndex];
                rentedCount++;
                availableCars[carIndex] = availableCars[availableCount - 1];
                availableCount--;

                cout << "Car rented successfully." << endl;
            }
            else {
                cout << "Invalid car index." << endl;
            }
            break;
        }

        case 'e': {
            if (rentedCount == 0) {
                cout << "No cars rented at the moment." << endl;
                break;
            }

            int carIndex;

            cout << "Choose a car to return (enter car index): " << endl;
            for (int i = 0; i < rentedCount; i++) {
                cout << i << ") ";
                rentedCars[i]->displayInfo();
                cout << endl;
            }

            cin >> carIndex;

            if (carIndex >= 0 && carIndex < rentedCount) {
                rentedCars[carIndex]->displayInfo();
                cout << "Enter updated mileage: ";
                int newMileage;
                cin >> newMileage;

                rentedCars[carIndex]->getMileage(newMileage);

                if (dynamic_cast<GasolineCar*>(rentedCars[carIndex])) {
                    double fuelAmount;
                    cout << "Enter updated fuel amount: ";
                    cin >> fuelAmount;
                    dynamic_cast<GasolineCar*>(rentedCars[carIndex])->setFuelAmount(fuelAmount);
                }
                else if (dynamic_cast<ElectricCar*>(rentedCars[carIndex])) {
                    int chargeLevel;
                    cout << "Enter updated charge level (0-100%): ";
                    cin >> chargeLevel;
                    dynamic_cast<ElectricCar*>(rentedCars[carIndex])->setChargeLevel(chargeLevel);
                }

                availableCars[availableCount] = rentedCars[carIndex];
                availableCount++;
                rentedCars[carIndex] = rentedCars[rentedCount - 1];
                rentedCount--;

                cout << "Car returned successfully." << endl;
            }
            else {
                cout << "Invalid car index." << endl;
            }
            break;
        }

        case 'f': {
            // Free allocated memory

             // Free allocated memory
            for (int i = 0; i < rentedCount; i++) {
                delete rentedCars[i];
            }

            for (int i = 0; i < availableCount; i++) {
                delete availableCars[i];
            }

            cout << "Exiting the program..." << endl;
            return 0;
        }

        default: {
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        }
        }
    }

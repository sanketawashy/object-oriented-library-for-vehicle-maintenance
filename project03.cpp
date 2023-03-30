#include <iostream>    // include the iostream library for standard input/output functions
#include <vector>      // include the vector library for dynamic arrays
#include <limits>      // include the limits library for numeric limits

using namespace std;   // use the standard namespace

// Define an enumeration type for vehicle fuel types

enum Type {
    GAS,        // gas (element 0)
    DIESEL,     // diesel (element 1)
    ELECTRIC    // electric (element 2)
};

// Define a base class for vehicles

class Vehicle {
protected:  //protected access modifier (specifier)
    string make;     // the make of the vehicle
    string model;    // the model of the vehicle
    int year;        // the year the vehicle was manufactured
    int odometer;    // the current odometer reading of the vehicle

public:     //public access modifier (specifier)

    // Constructor for the Vehicle class, initializes the make, model, year, and odometer values

    Vehicle(string make_, string model_, int year_, int odometer_)
        : make(make_), model(model_), year(year_), odometer(odometer_) {}

    // Setter method for the make value
    void setMake(string make_) {
        make = make_;
    }

    // Getter method for the make value
    string getMake() const {
        return make;
    }

    // Setter method for the model value
    void setModel(string model_) {
        model = model_;
    }

    // Getter method for the model value
    string getModel() const {
        return model;
    }

    // Setter method for the year value
    void setYear(int year_) {
        year = year_;
    }

    // Getter method for the year value
    int getYear() const {
        return year;
    }

    // Setter method for the odometer value
    void setOdometer(int odometer_) {
        odometer = odometer_;
    }

    // Getter method for the odometer value
    int getOdometer() const {
        return odometer;
    }

    // Pure virtual function to get the vehicle type
    virtual Type getType() = 0;

    // Pure virtual function to check if the vehicle tires need rotation
    virtual void checkTireRotation() = 0;

    // Pure virtual function to get the vehicle information
    virtual void getCarInformation() = 0;

    // Destructor for the Vehicle class
    virtual ~Vehicle() {}
};
// Define a class GasCar that inherits from the Vehicle class

class GasCar : public Vehicle {
public:
    // Constructor for GasCar class that calls the constructor of the parent class and passes the arguments to it
    GasCar(string make_, string model_, int year_, int odometer_)
        : Vehicle(make_, model_, year_, odometer_) {}

    // Function that returns the fuel type of the car as GAS
    Type getType() {
        return GAS;
    }

    // Function that checks if the tires of the car need to be rotated based on the odometer reading
    void checkTireRotation() {
        if (odometer >= 50000) {
            cout << "Time to rotate tires on your gas car.\n";
        } else {
            cout << "Tires are good to go.\n";
        }
    }

    // Function that prints the make, model, year, odometer reading, and fuel type of the car
    void getCarInformation() {
        cout << "Make: " << make << endl
             << "Model: " << model << endl
             << "Year: " << year << endl
             << "Odometer reading: " << odometer << endl
             << "Fuel type: Gas" << endl;
    }
    //  Function to check for oilchange
    void changeOil() {
        int oilLevel;
        cout<<" Enter the level of oil in Ml: ";
        cin>>oilLevel;
        cout<<" checking for oil change \n";
        if (oilLevel>= 1000){
            cout<<"dont need oil change \n";
        }
        else{
            cout<<"car needs oil change.. \n";
        }
    }
};


// This class represents a Diesel Car and inherits from the Vehicle class

class DieselCar : public Vehicle {
public:
    // Constructor for DieselCar class
    DieselCar(string make_, string model_, int year_, int odometer_)
        // Call the constructor of the base class 'Vehicle'
        : Vehicle(make_, model_, year_, odometer_) {}

    // Returns the type of the vehicle, which is Diesel for DieselCar
    Type getType() {
        return DIESEL;
    }

    // Checks if it is time to rotate the tires of the diesel car
    void checkTireRotation() {
        if (odometer >= 50000) {
            cout << "Time to rotate tires on your diesel car.\n";
        } else {
            cout << "Tires are good to go.\n";
        }
    }

    // Prints the information of the diesel car
    void getCarInformation() {
        cout << "Make: " << make << endl
             << "Model: " << model << endl
             << "Year: " << year << endl
             << "Odometer reading: " << odometer << endl
             << "Fuel type: Diesel" << endl;
    }
};


// This class represents an Electric Car and inherits from the Vehicle class

class ElectricCar : public Vehicle {
public:
    // Constructor for ElectricCar class
    ElectricCar(string make_, string model_, int year_, int odometer_)
        // Call the constructor of the base class 'Vehicle'
        : Vehicle(make_, model_, year_, odometer_) {}

    // Returns the type of the vehicle, which is Electric for ElectricCar
    Type getType() {
        return ELECTRIC;
    }

    // Checks if it is time to rotate the tires of the electric car
    void checkTireRotation() {
        if (odometer >= 50000) {
            cout << "Time to rotate tires on your electric car.\n";
        } else {
            cout << "Tires are good to go.\n";
        }
    }

    // Prints the information of the electric car
    void getCarInformation() {
        cout << "Make: " << make << endl
             << "Model: " << model << endl
             << "Year: " << year << endl
             << "Odometer reading: " << odometer << endl
             << "Fuel type: Electric" << endl;
    }

    // Recharge the battery of the electric car
    void recharge() {
        int KM;
        // Ask the user to enter the number of kilometers they want to travel
        cout<<"Enter number of Km ";
        cin>>KM;
        // Check if the battery needs to be recharged based on the distance entered by the user
        cout<<" checking for battery charging... \n";
        if (KM>=400){
            cout<<"battery to be recharged  \n";
        }
        else{
            cout<<"car is good to go.. \n";
        }       
    }
};

// This function creates a new vehicle object based on user input and returns a pointer to that object.

Vehicle* addVehicle() {
    // Declare variables to hold user input
string make;
string model;
int year;
int odometer;
int choice;

// Prompt the user to select a vehicle type
cout << "Select vehicle type:\n"
     << "1. Gas\n"
     << "2. Diesel\n"
     << "3. Electric\n";
cin >> choice;

// Use while loops to validate user input for make, model, year, and odometer reading
// Prompt the user to enter make until a non-empty string is entered
while (true) {
    cout << "Enter make: ";
    getline(cin >> ws, make);
    if (!make.empty()) break;
}

// Prompt the user to enter model until a non-empty string is entered
while (true) {
    cout << "Enter model: ";
    getline(cin >> ws, model);
    if (!model.empty()) break;
}

// Prompt the user to enter year until a valid year between 1900 and 2023 is entered
while (true) {
    cout << "Enter year: ";
    if (cin >> year && year >= 1900 && year <= 2023) break;
    cout << "Invalid input, please try again.\n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Prompt the user to enter odometer reading until a valid non-negative integer is entered
while (true) {
    cout << "Enter odometer reading: ";
    if (cin >> odometer && odometer >= 0) break;
    cout << "Invalid input, please try again.\n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Create a new vehicle object based on user choice and input
switch(choice) {
    case 1:
        return new GasCar(make, model, year, odometer);
    case 2:
        return new DieselCar(make, model, year, odometer);
    case 3:
        return new ElectricCar(make, model, year, odometer);
    default:
        cout << "Invalid choice, returning to main menu.\n";
        return nullptr;
}
}




// This is the main function of the program.
int main() {
// Declare a vector of pointers to Vehicle objects called 'garage'.
vector<Vehicle*> garage;
// Declare a boolean variable 'running' and set it to true.
bool running = true;
// Declare an integer variable 'choice'.
int choice;
// Begin a while loop which continues until the user chooses to quit the program.
while (running) {
    // Display a menu of options for the user to choose from.
    cout << "\nSelect an option:\n"
         << "   1. Add vehicle\n"
         << "   2. List inventory \n"
         << "   3. Update vehicle\n"
         << "   4. Remove vehicle\n"
         << "   5. Tire Rotation\n"
         << "   6. Oil Change\n"
         << "   7. Recharge\n"
         << "   0. Quit\n";
    // Get the user's choice.
    cin >> choice;

    // Use a switch statement to perform the appropriate action based on the user's choice.
    switch (choice) {
            
        case 1: {
            // If the user chooses to add a vehicle, call the addVehicle() function to create a new Vehicle object and add it to the garage.
            Vehicle* vehicle = addVehicle();
            garage.push_back(vehicle);
            break;
         }
            
        case 2:
            // If the user chooses to print the garage, loop through each vehicle in the garage and call its getCarInformation() function to display its information.
            for (Vehicle* vehicle : garage) {
                vehicle->getCarInformation();
         }
         break;
            
            
        case 3: {
            int index;
            cout << "Enter the index of the vehicle you want to update: ";
            cin >> index;
            if (index >= 0 && index < garage.size()) {
            Vehicle* vehicle = garage[index];
            string make;
            string model;
            int year;
            int odometer;
            while (true) {
                 cout << "Enter make: ";
                 getline(cin >> ws, make);
                 if (!make.empty()) break;
             }
                
           while (true) {
              cout << "Enter model: ";
              getline(cin >> ws, model);
              if (!model.empty()) break;
          }
          while (true) {
              cout << "Enter year: ";
              if (cin >> year && year >= 1900 && year <= 2023) break;
              cout << "Invalid input, please try again.\n";
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(), '\n');
         }
        while (true) {
            cout << "Enter odometer reading: ";
            if (cin >> odometer && odometer >= 0) break;
            cout << "Invalid input, please try again.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        vehicle->setMake(make);
        vehicle->setModel(model);
        vehicle->setYear(year);
        vehicle->setOdometer(odometer);
    } else {
        cout << "Invalid index.\n";
    }
    break;
} 

case 4: {
    int index;
    cout << "Enter the index of the vehicle you want to remove: ";
    cin >> index;
    if (index >= 0 && index < garage.size()) {
        delete garage[index];
        garage.erase(garage.begin() + index);
    } else {
        cout << "Invalid index.\n";
    }
    break;
}

case 5: {
    int index;
    cout << "Enter the index of the vehicle you want to check: ";
    cin >> index;
    if (index >= 0 && index < garage.size()) {
        garage[index]->checkTireRotation();
    } else {
        cout << "Invalid index.\n";
    }
    break;
}

// This case allows the user to change oil in a gas vehicle.

case 6: {
       // Declare and initialize a variable to hold the index of the gas vehicle to change oil in.
       int index;
       cout << "Enter the index of the gas vehicle you want to change oil: ";
       // Read in the index entered by the user.
       cin >> index;
       // Check if the index is valid and within the bounds of the vector.
       if (index >= 0 && index < garage.size()) {
       // Check if the vehicle at the given index is of type GAS.
       if (garage[index]->getType() == GAS) {
       // Use dynamic_cast to downcast the Vehicle pointer to a GasCar pointer.
       GasCar* gasCar = dynamic_cast<GasCar*>(garage[index]);
       // Check if the downcast was successful.
      if (gasCar != nullptr) {
       // Call the changeOil() function on the gasCar object.
       gasCar->changeOil();
       } else {
       // If the downcast was not successful, print an error message.
       cout << "Vehicle is not a gas car.\n";
       }
       } else {
       // If the vehicle is not of type GAS, print an error message.
       cout << "Vehicle is not a gas car.\n";
       }
       } else {
       // If the index is not valid, print an error message.
       cout << "Invalid index.\n";
       }
       // Exit the switch statement.
       break;
}

// This case allows the user to recharge an electric vehicle.
case 7: {
       // Declare and initialize a variable to hold the index of the electric vehicle to recharge.
       int index;
       cout << "Enter the index of the electric vehicle you want to recharge: ";
       // Read in the index entered by the user.
       cin >> index;
       // Check if the index is valid and within the bounds of the vector.
       if (index >= 0 && index < garage.size()) {
       // Check if the vehicle at the given index is of type ELECTRIC.
       if (garage[index]->getType() == ELECTRIC) {
       // Use dynamic_cast to downcast the Vehicle pointer to an ElectricCar pointer.
       ElectricCar* electricCar = dynamic_cast<ElectricCar*>(garage[index]);
       // Check if the downcast was successful.
       if (electricCar != nullptr) {
       // Call the recharge() function on the electricCar object.
       electricCar->recharge();
       } else {
       // If the downcast was not successful, print an error message.
       cout << "Vehicle is not an electric car.\n";
       }
       } else {
       // If the vehicle is not of type ELECTRIC, print an error message.
       cout << "Vehicle is not an electric car.\n";
       }
       } else {
       // If the index is not valid, print an error message.
       cout << "Invalid index.\n";
       }
       // Exit the switch statement.
       break;
}

// This case handles the user choosing to exit the program.
  case 0:
      // Print a message indicating the program is exiting.
      cout<<"Exiting.... good bye...";
      running = false; // sets the variable 'running' to false, which will exit the while loop
      break; // breaks out of the switch statement
      default: // this code block executes if the user enters a choice that doesn't match any of the cases above
      cout << "Invalid choice.\n"; // prints an error message
      break; // breaks out of the switch statement
   }

 }

for (Vehicle* vehicle : garage) { // iterates through the 'garage' vector using a range-based for loop and assigns each element to 'vehicle'
    delete vehicle; // deletes each element of 'garage', which must have been dynamically allocated
}

garage.clear(); // removes all elements from the 'garage' vector

return 0; // exits the program with a return value of 0

}

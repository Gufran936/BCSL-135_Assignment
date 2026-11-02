// Enrollment Number : 2552562140
// Name              : Gufran

// Course Code       : BCSL-135
// Course Title      : DBMS and C++ Lab
// Assignment Number : BCA_NEW/BCAOL(III)L-135/Assign/2026-27

// Q1: Project: Vehicle Service Management System
// Section B: C++ Application Development

/*Write a menu-driven C++ program that acts as a console-based interface for the Vehicle Service Management
System. Since this is a standalone C++ application, all records should be managed using classes and file
handling.
Your program must implement the following:
1. Customer Class
Create a class named Customer with private data members to store:
    • Customer ID, Customer Name, Address, Mobile Number, Email Address Include:
    • Constructors, Getter and Setter member functions, Function to display customer information

2. Vehicle Class
Create a class named Vehicle with private data members to store:
    • Vehicle ID, Registration Number, Model, Manufacturer, Year of Manufacture, Fuel Type
      Include appropriate constructors and member functions.

3. Service Class
Create a class named Service with private data members to store:
    • Service ID, Customer ID, Vehicle ID, Mechanic ID, Service Date, Service Type, Labour Charges,
      Spare Parts Cost, Total Bill Amount
      The class should include:
    • Constructors, Member functions to calculate the total bill, Functions to add, modify, search, and
      display service records

4. File Handling
On starting the application, it should load all existing records from the following files:
    • customers.dat, vehicles.dat, services.dat,
    • When the user chooses to exit, all newly added and modified records must be saved back to their
      respective files.

5. Menu-Driven Interface
The program should display a menu with the following options:
    1. Register New Customer, Register New Vehicle, Record Vehicle Service, Search Vehicle by
       Registration Number, Search Customer by Customer ID, Update Vehicle Service Details, Delete a
       Service Record, Display All Customers, Display All Vehicles, Display Complete Service History of a
       Vehicle, Generate Vehicle Service Bill
    2. Exit

6. Input Validation
The program should validate the following conditions:
    • Vehicle Registration Number must be unique.
    • Mobile Number must contain exactly 10 digits. 
    • Labour Charges and Spare Parts Cost should not be negative.
    • Total Bill Amount should be calculated automatically.
    • A service record cannot be created unless both the customer and vehicle are already registered.
    • Display appropriate error messages whenever invalid input is entered.
The program should be robust and handle user input errors gracefully.*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <limits>
#include <cctype>

using namespace std;

class Customer
{
private:
    int customerID;
    string customerName;
    string address;
    string mobileNumber;
    string emailAddress;

public:
    // Default constructor
    Customer()
    {
        customerID = 0;
    }

    // Parameterized constructor
    Customer(int id, string name, string addr,
             string mobile, string email)
    {
        customerID = id;
        customerName = name;
        address = addr;
        mobileNumber = mobile;
        emailAddress = email;
    }

    // Getters
    int getCustomerID() const
    {
        return customerID;
    }

    string getCustomerName() const
    {
        return customerName;
    }

    string getAddress() const
    {
        return address;
    }

    string getMobileNumber() const
    {
        return mobileNumber;
    }

    string getEmailAddress() const
    {
        return emailAddress;
    }

    // Setters
    void setCustomerID(int id)
    {
        customerID = id;
    }

    void setCustomerName(string name)
    {
        customerName = name;
    }

    void setAddress(string addr)
    {
        address = addr;
    }

    void setMobileNumber(string mobile)
    {
        mobileNumber = mobile;
    }

    void setEmailAddress(string email)
    {
        emailAddress = email;
    }

    // Display customer information
    void display() const
    {
        cout << "\nCustomer ID  : " << customerID;
        cout << "\nCustomer Name : " << customerName;
        cout << "\nAddress     : " << address;
        cout << "\nMobile Number : " << mobileNumber;
        cout << "\nEmail Address : " << emailAddress;
        cout << "\n--------------------------------";
    }
};


class Vehicle
{
private:
    int vehicleID;
    int customerID;
    string registrationNumber;
    string model;
    string manufacturer;
    int yearOfManufacture;
    string fuelType;

public:
    Vehicle()
    {
        vehicleID = 0;
        customerID = 0;
        yearOfManufacture = 0;
    }

    Vehicle(int id, int custID, string regNo,
            string mod, string manu, int year,
            string fuel)
    {
        vehicleID = id;
        customerID = custID;
        registrationNumber = regNo;
        model = mod;
        manufacturer = manu;
        yearOfManufacture = year;
        fuelType = fuel;
    }

    // Getters

    int getVehicleID() const
    {
        return vehicleID;
    }

    int getCustomerID() const
    {
        return customerID;
    }

    string getRegistrationNumber() const
    {
        return registrationNumber;
    }

    string getModel() const
    {
        return model;
    }

    string getManufacturer() const
    {
        return manufacturer;
    }

    int getYearOfManufacture() const
    {
        return yearOfManufacture;
    }

    string getFuelType() const
    {
        return fuelType;
    }

    // Setters

    void setVehicleID(int id)
    {
        vehicleID = id;
    }

    void setCustomerID(int id)
    {
        customerID = id;
    }

    void setRegistrationNumber(string reg)
    {
        registrationNumber = reg;
    }

    void setModel(string m)
    {
        model = m;
    }

    void setManufacturer(string m)
    {
        manufacturer = m;
    }

    void setYearOfManufacture(int year)
    {
        yearOfManufacture = year;
    }

    void setFuelType(string fuel)
    {
        fuelType = fuel;
    }

    void display() const
    {
        cout << "\nVehicle ID      : " << vehicleID;
        cout << "\nCustomer ID     : " << customerID;
        cout << "\nRegistration Number : " << registrationNumber;
        cout << "\nModel           : " << model;
        cout << "\nManufacturer    : " << manufacturer;
        cout << "\nYear            : " << yearOfManufacture;
        cout << "\nFuel Type       : " << fuelType;
        cout << "\n--------------------------------";
    }
};


class Service
{
private:
    int serviceID;
    int customerID;
    int vehicleID;
    int mechanicID;

    string serviceDate;
    string serviceType;

    double labourCharges;
    double sparePartsCost;
    double totalBillAmount;

public:
    Service()
    {
        serviceID = 0;
        customerID = 0;
        vehicleID = 0;
        mechanicID = 0;
        labourCharges = 0;
        sparePartsCost = 0;
        totalBillAmount = 0;
    }

    Service(int sid, int cid, int vid, int mid,
            string date, string type,
            double labour, double parts)
    {
        serviceID = sid;
        customerID = cid;
        vehicleID = vid;
        mechanicID = mid;
        serviceDate = date;
        serviceType = type;
        labourCharges = labour;
        sparePartsCost = parts;

        calculateTotalBill();
    }

    // Calculate total bill
    void calculateTotalBill()
    {
        totalBillAmount = labourCharges + sparePartsCost;
    }

    // Getters

    int getServiceID() const
    {
        return serviceID;
    }

    int getCustomerID() const
    {
        return customerID;
    }

    int getVehicleID() const
    {
        return vehicleID;
    }

    int getMechanicID() const
    {
        return mechanicID;
    }

    string getServiceDate() const
    {
        return serviceDate;
    }

    string getServiceType() const
    {
        return serviceType;
    }

    double getLabourCharges() const
    {
        return labourCharges;
    }

    double getSparePartsCost() const
    {
        return sparePartsCost;
    }

    double getTotalBillAmount() const
    {
        return totalBillAmount;
    }

    // Setters

    void setServiceDate(string date)
    {
        serviceDate = date;
    }

    void setServiceType(string type)
    {
        serviceType = type;
    }

    void setLabourCharges(double amount)
    {
        labourCharges = amount;
        calculateTotalBill();
    }

    void setSparePartsCost(double amount)
    {
        sparePartsCost = amount;
        calculateTotalBill();
    }

    void setMechanicID(int id)
    {
        mechanicID = id;
    }

    void display() const
    {
        cout << "\nService ID    : " << serviceID;
        cout << "\nCustomer ID   : " << customerID;
        cout << "\nVehicle ID    : " << vehicleID;
        cout << "\nMechanic ID   : " << mechanicID;
        cout << "\nService Date  : " << serviceDate;
        cout << "\nService Type  : " << serviceType;

        cout << fixed << setprecision(2);

        cout << "\nLabour Charges : Rs. " << labourCharges;
        cout << "\nSpare Parts Cost : Rs. " << sparePartsCost;
        cout << "\nTotal Bill   : Rs. " << totalBillAmount;

        cout << "\n--------------------------------";
    }
};

vector<Customer> customers;
vector<Vehicle> vehicles;
vector<Service> services;

bool validMobile(string mobile)
{
    if (mobile.length() != 10)
        return false;

    for (char c : mobile)
    {
        if (!isdigit(c))
            return false;
    }

    return true;
}

bool customerExists(int id)
{
    for (const auto &c : customers)
    {
        if (c.getCustomerID() == id)
            return true;
    }

    return false;
}

bool vehicleExists(int id)
{
    for (const auto &v : vehicles)
    {
        if (v.getVehicleID() == id)
            return true;
    }

    return false;
}

bool serviceExists(int id)
{
    for (const auto &s : services)
    {
        if (s.getServiceID() == id)
            return true;
    }

    return false;
}

bool registrationExists(string regNo)
{
    for (const auto &v : vehicles)
    {
        if (v.getRegistrationNumber() == regNo)
            return true;
    }

    return false;
}


void saveCustomers()
{
    ofstream file("customers.dat");

    for (const auto &c : customers)
    {
        file << c.getCustomerID() << "|"
             << c.getCustomerName() << "|"
             << c.getAddress() << "|"
             << c.getMobileNumber() << "|"
             << c.getEmailAddress() << endl;
    }

    file.close();
}


void saveVehicles()
{
    ofstream file("vehicles.dat");

    for (const auto &v : vehicles)
    {
        file << v.getVehicleID() << "|"
             << v.getCustomerID() << "|"
             << v.getRegistrationNumber() << "|"
             << v.getModel() << "|"
             << v.getManufacturer() << "|"
             << v.getYearOfManufacture() << "|"
             << v.getFuelType() << endl;
    }

    file.close();
}


void saveServices()
{
    ofstream file("services.dat");

    file << fixed << setprecision(2);

    for (const auto &s : services)
    {
        file << s.getServiceID() << "|"
             << s.getCustomerID() << "|"
             << s.getVehicleID() << "|"
             << s.getMechanicID() << "|"
             << s.getServiceDate() << "|"
             << s.getServiceType() << "|"
             << s.getLabourCharges() << "|"
             << s.getSparePartsCost() << endl;
    }

    file.close();
}


void loadCustomers()
{
    ifstream file("customers.dat");

    if (!file)
        return;

    string line;

    while (getline(file, line))
    {
        stringstream ss(line);

        string id, name, address, mobile, email;

        getline(ss, id, '|');
        getline(ss, name, '|');
        getline(ss, address, '|');
        getline(ss, mobile, '|');
        getline(ss, email, '|');

        if (!id.empty())
        {
            customers.emplace_back(
                stoi(id),
                name,
                address,
                mobile,
                email);
        }
    }

    file.close();
}


void loadVehicles()
{
    ifstream file("vehicles.dat");

    if (!file)
        return;

    string line;

    while (getline(file, line))
    {
        stringstream ss(line);

        string id, cid, reg, model;
        string manufacturer, year, fuel;

        getline(ss, id, '|');
        getline(ss, cid, '|');
        getline(ss, reg, '|');
        getline(ss, model, '|');
        getline(ss, manufacturer, '|');
        getline(ss, year, '|');
        getline(ss, fuel, '|');

        if (!id.empty())
        {
            vehicles.emplace_back(
                stoi(id),
                stoi(cid),
                reg,
                model,
                manufacturer,
                stoi(year),
                fuel);
        }
    }

    file.close();
}


void loadServices()
{
    ifstream file("services.dat");

    if (!file)
        return;

    string line;

    while (getline(file, line))
    {
        stringstream ss(line);

        string sid, cid, vid, mid;
        string date, type, labour, parts;

        getline(ss, sid, '|');
        getline(ss, cid, '|');
        getline(ss, vid, '|');
        getline(ss, mid, '|');
        getline(ss, date, '|');
        getline(ss, type, '|');
        getline(ss, labour, '|');
        getline(ss, parts, '|');

        if (!sid.empty())
        {
            services.emplace_back(
                stoi(sid),
                stoi(cid),
                stoi(vid),
                stoi(mid),
                date,
                type,
                stod(labour),
                stod(parts));
        }
    }

    file.close();
}


void loadAllData()
{
    loadCustomers();
    loadVehicles();
    loadServices();
}


void registerCustomer()
{
    int id;

    cout << "\nEnter Customer ID: ";
    cin >> id;

    if (customerExists(id))
    {
        cout << "Error: Customer ID already exists.\n";
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string name, address, mobile, email;

    cout << "Enter Customer Name: ";
    getline(cin, name);

    cout << "Enter Address: ";
    getline(cin, address);

    cout << "Enter Mobile Number: ";
    getline(cin, mobile);

    if (!validMobile(mobile))
    {
        cout << "Error: Mobile number must contain exactly 10 digits.\n";
        return;
    }

    cout << "Enter Email Address: ";
    getline(cin, email);

    Customer c(id, name, address, mobile, email);

    customers.push_back(c);

    cout << "\nCustomer registered successfully.\n";
}


void registerVehicle()
{
    int vehicleID, customerID, year;

    cout << "\nEnter Vehicle ID: ";
    cin >> vehicleID;

    if (vehicleExists(vehicleID))
    {
        cout << "Error: Vehicle ID already exists.\n";
        return;
    }

    cout << "Enter Customer ID: ";
    cin >> customerID;

    if (!customerExists(customerID))
    {
        cout << "Error: Customer is not registered.\n";
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string regNo, model, manufacturer, fuel;

    cout << "Enter Registration Number: ";
    getline(cin, regNo);

    if (registrationExists(regNo))
    {
        cout << "Error: Registration number already exists.\n";
        return;
    }

    cout << "Enter Model: ";
    getline(cin, model);

    cout << "Enter Manufacturer: ";
    getline(cin, manufacturer);

    cout << "Enter Year of Manufacture: ";
    cin >> year;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Fuel Type: ";
    getline(cin, fuel);

    Vehicle v(
        vehicleID,
        customerID,
        regNo,
        model,
        manufacturer,
        year,
        fuel);

    vehicles.push_back(v);

    cout << "\nVehicle registered successfully.\n";
}


void recordService()
{
    int serviceID, customerID, vehicleID, mechanicID;

    cout << "\nEnter Service ID: ";
    cin >> serviceID;

    if (serviceExists(serviceID))
    {
        cout << "Error: Service ID already exists.\n";
        return;
    }

    cout << "Enter Customer ID: ";
    cin >> customerID;

    if (!customerExists(customerID))
    {
        cout << "Error: Customer is not registered.\n";
        return;
    }

    cout << "Enter Vehicle ID: ";
    cin >> vehicleID;

    if (!vehicleExists(vehicleID))
    {
        cout << "Error: Vehicle is not registered.\n";
        return;
    }

    // Check that vehicle belongs to customer
    bool ownership = false;

    for (const auto &v : vehicles)
    {
        if (v.getVehicleID() == vehicleID &&
            v.getCustomerID() == customerID)
        {
            ownership = true;
            break;
        }
    }

    if (!ownership)
    {
        cout << "Error: Vehicle does not belong to this customer.\n";
        return;
    }

    cout << "Enter Mechanic ID: ";
    cin >> mechanicID;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string date, type;

    cout << "Enter Service Date (YYYY-MM-DD): ";
    getline(cin, date);

    cout << "Enter Service Type: ";
    getline(cin, type);

    double labour, parts;

    cout << "Enter Labour Charges: ";
    cin >> labour;

    if (labour < 0)
    {
        cout << "Error: Labour charges cannot be negative.\n";
        return;
    }

    cout << "Enter Spare Parts Cost: ";
    cin >> parts;

    if (parts < 0)
    {
        cout << "Error: Spare parts cost cannot be negative.\n";
        return;
    }

    Service s(
        serviceID,
        customerID,
        vehicleID,
        mechanicID,
        date,
        type,
        labour,
        parts);

    services.push_back(s);

    cout << "\nService recorded successfully.\n";

    cout << fixed << setprecision(2);
    cout << "Total Bill = Rs. "
         << s.getTotalBillAmount() << endl;
}


void searchVehicleByRegistration()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string regNo;

    cout << "\nEnter Registration Number: ";
    getline(cin, regNo);

    for (const auto &v : vehicles)
    {
        if (v.getRegistrationNumber() == regNo)
        {
            v.display();
            return;
        }
    }

    cout << "Vehicle not found.\n";
}


void searchCustomer()
{
    int id;

    cout << "\nEnter Customer ID: ";
    cin >> id;

    for (const auto &c : customers)
    {
        if (c.getCustomerID() == id)
        {
            c.display();
            return;
        }
    }

    cout << "Customer not found.\n";
}


void updateService()
{
    int id;

    cout << "\nEnter Service ID to update: ";
    cin >> id;

    for (auto &s : services)
    {
        if (s.getServiceID() == id)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            string date, type;
            double labour, parts;
            int mechanic;

            cout << "Enter new Service Date: ";
            getline(cin, date);

            cout << "Enter new Service Type: ";
            getline(cin, type);

            cout << "Enter new Mechanic ID: ";
            cin >> mechanic;

            cout << "Enter new Labour Charges: ";
            cin >> labour;

            if (labour < 0)
            {
                cout << "Invalid labour charges.\n";
                return;
            }

            cout << "Enter new Spare Parts Cost: ";
            cin >> parts;

            if (parts < 0)
            {
                cout << "Invalid spare parts cost.\n";
                return;
            }

            s.setServiceDate(date);
            s.setServiceType(type);
            s.setMechanicID(mechanic);
            s.setLabourCharges(labour);
            s.setSparePartsCost(parts);

            cout << "\nService updated successfully.\n";
            cout << "New Total Bill = Rs. "
                 << s.getTotalBillAmount() << endl;

            return;
        }
    }

    cout << "Service record not found.\n";
}


void deleteService()
{
    int id;

    cout << "\nEnter Service ID to delete: ";
    cin >> id;

    for (auto it = services.begin();
         it != services.end();
         ++it)
    {
        if (it->getServiceID() == id)
        {
            services.erase(it);

            cout << "Service record deleted successfully.\n";
            return;
        }
    }

    cout << "Service record not found.\n";
}


void displayAllCustomers()
{
    if (customers.empty())
    {
        cout << "\nNo customer records available.\n";
        return;
    }

    cout << "\n========== ALL CUSTOMERS ==========\n";

    for (const auto &c : customers)
    {
        c.display();
    }

    cout << endl;
}


void displayAllVehicles()
{
    if (vehicles.empty())
    {
        cout << "\nNo vehicle records available.\n";
        return;
    }

    cout << "\n========== ALL VEHICLES ==========\n";

    for (const auto &v : vehicles)
    {
        v.display();
    }

    cout << endl;
}


void displayServiceHistory()
{
    int vehicleID;

    cout << "\nEnter Vehicle ID: ";
    cin >> vehicleID;

    bool found = false;

    cout << "\n========== SERVICE HISTORY ==========\n";

    for (const auto &s : services)
    {
        if (s.getVehicleID() == vehicleID)
        {
            s.display();
            found = true;
        }
    }

    if (!found)
    {
        cout << "No service history found for this vehicle.\n";
    }
}


void generateBill()
{
    int serviceID;

    cout << "\nEnter Service ID: ";
    cin >> serviceID;

    for (const auto &s : services)
    {
        if (s.getServiceID() == serviceID)
        {
            cout << "\n";
            cout << "========================================\n";
            cout << "*         VEHICLE SERVICE BILL         *\n";
            cout << "========================================\n";

            cout << "Service ID    : "
                 << s.getServiceID() << endl;

            cout << "Customer ID   : "
                 << s.getCustomerID() << endl;

            cout << "Vehicle ID    : "
                 << s.getVehicleID() << endl;

            cout << "Mechanic ID   : "
                 << s.getMechanicID() << endl;

            cout << "Service Date  : "
                 << s.getServiceDate() << endl;

            cout << "Service Type  : "
                 << s.getServiceType() << endl;

            cout << fixed << setprecision(2);

            cout << "Labour Charges : Rs. "
                 << s.getLabourCharges() << endl;

            cout << "Spare Parts Cost : Rs. "
                 << s.getSparePartsCost() << endl;

            cout << "----------------------------------------\n";

            cout << "TOTAL BILL   : Rs. "
                 << s.getTotalBillAmount() << endl;

            cout << "========================================\n";

            return;
        }
    }

    cout << "Service record not found.\n";
}


void displayMenu()
{
    cout << "\n\n";
    cout << "========================================\n";
    cout << "  VEHICLE SERVICE MANAGEMENT SYSTEM\n";
    cout << "========================================\n";

    cout << "1. Register New Customer\n";
    cout << "2. Register New Vehicle\n";
    cout << "3. Record Vehicle Service\n";
    cout << "4. Search Vehicle by Registration Number\n";
    cout << "5. Search Customer by Customer ID\n";
    cout << "6. Update Vehicle Service Details\n";
    cout << "7. Delete a Service Record\n";
    cout << "8. Display All Customers\n";
    cout << "9. Display All Vehicles\n";
    cout << "10. Display Complete Service History\n";
    cout << "11. Generate Vehicle Service Bill\n";
    cout << "12. Exit\n";

    cout << "========================================\n";
    cout << "Enter your choice: ";
}


int main()
{
    // Load existing records when program starts
    loadAllData();

    int choice;

    do
    {
        displayMenu();

        if (!(cin >> choice))
        {
            cout << "\nInvalid input! Please enter a number.\n";

            cin.clear();

            cin.ignore(
                numeric_limits<streamsize>::max(),
                '\n');

            continue;
        }

        switch (choice)
        {
        case 1:
            registerCustomer();
            break;

        case 2:
            registerVehicle();
            break;

        case 3:
            recordService();
            break;

        case 4:
            searchVehicleByRegistration();
            break;

        case 5:
            searchCustomer();
            break;

        case 6:
            updateService();
            break;

        case 7:
            deleteService();
            break;

        case 8:
            displayAllCustomers();
            break;

        case 9:
            displayAllVehicles();
            break;

        case 10:
            displayServiceHistory();
            break;

        case 11:
            generateBill();
            break;

        case 12:
            // Save all data before exiting
            saveCustomers();
            saveVehicles();
            saveServices();

            cout << "\nAll records saved successfully.\n";
            cout << "Thank you for using the system.\n";
            break;

        default:
            cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 12);

    return 0;
}
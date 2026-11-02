-- Enrollment Number : 2552562140
-- Name              : Gufran

-- Course Code       : BCSL-135
-- Course Title      : DBMS and C++ Lab
-- Assignment Number : BCA_NEW/BCAOL(III)L-135/Assign/2026-27

-- SECTION A: Database Schema and Queries
-- (a) Database Schema:

-- Create the necessary tables to store the following information: 
--     • A unique Contact_ID for each contact. 
--     • Customer Name, Address, Mobile Number, and Email Address. 
--     • A unique Vehicle_ID for each vehicle. 
--     • Vehicle Registration Number, Model, Manufacturer, Year of Manufacture, and Fuel
--       Type. 
--     • Each customer may own multiple vehicles. 
--     • A unique Mechanic_ID for each mechanic. 
--     • Mechanic Name, Specialization, Experience, and Contact Number. 
--     • A unique Service_ID for each service transaction. 
--     • Service Date, Service Type (Periodic Service, General Repair, Engine Repair, 
--       Electrical Repair, 
--     • Washing, etc.), Labour Charges, Spare Parts Cost, and Total Bill Amount. 
--     • Each service transaction must be assigned to one mechanic. 
--     • Multiple spare parts may be used during a service. Store the Part_ID, Part Name, 
--       Quantity, and Unit Price for each spare part.

-- SQL to Create Database
CREATE DATABASE VehicleServiceDB;
USE VehicleServiceDB;

-- Customer Table
CREATE TABLE Customer (
    Contact_ID INT PRIMARY KEY,
    Customer_Name VARCHAR(100) NOT NULL,
    Address VARCHAR(255) NOT NULL,
    Mobile_Number VARCHAR(10) NOT NULL UNIQUE,
    Email_Address VARCHAR(100) UNIQUE
);


-- Vehicle Table
CREATE TABLE Vehicle (
    Vehicle_ID INT PRIMARY KEY,
    Contact_ID INT NOT NULL,
    Registration_Number VARCHAR(20) NOT NULL UNIQUE,
    Model VARCHAR(50) NOT NULL,
    Manufacturer VARCHAR(50) NOT NULL,
    Year_of_Manufacture INT NOT NULL,
    Fuel_Type VARCHAR(20) NOT NULL,
    FOREIGN KEY (Contact_ID)
    REFERENCES Customer(Contact_ID)
);

-- Mechanic Table
CREATE TABLE Mechanic (
    Mechanic_ID INT PRIMARY KEY,
    Mechanic_Name VARCHAR(100) NOT NULL,
    Specialization VARCHAR(100) NOT NULL,
    Experience INT NOT NULL,
    Contact_Number VARCHAR(10) NOT NULL
);

-- Service Table
CREATE TABLE Service (
    Service_ID INT PRIMARY KEY,
    Vehicle_ID INT NOT NULL,
    Mechanic_ID INT NOT NULL,
    Service_Date DATE NOT NULL,
    Service_Type VARCHAR(50) NOT NULL,
    Labour_Charges DECIMAL(10,2) NOT NULL,
    Spare_Parts_Cost DECIMAL(10,2) NOT NULL,
    Total_Bill_Amount DECIMAL(10,2) NOT NULL,

    FOREIGN KEY (Vehicle_ID) 
        REFERENCES Vehicle(Vehicle_ID),

    FOREIGN KEY (Mechanic_ID)
        REFERENCES Mechanic(Mechanic_ID)
);

-- Spare Part Table
CREATE TABLE Spare_Part (
    Part_ID INT PRIMARY KEY,
    Part_Name VARCHAR(100) NOT NULL,
    Unit_Price DECIMAL(10,2) NOT NULL
);

-- Service Part Table
CREATE TABLE Service_Part (
    Service_ID INT,
    Part_ID INT,
    Quantity INT NOT NULL,
    Unit_Price DECIMAL(10,2) NOT NULL,
    PRIMARY KEY (Service_ID, Part_ID),
    FOREIGN KEY (Service_ID)
        REFERENCES Service(Service_ID),
    FOREIGN KEY (Part_ID)
        REFERENCES Spare_Part(Part_ID)
);
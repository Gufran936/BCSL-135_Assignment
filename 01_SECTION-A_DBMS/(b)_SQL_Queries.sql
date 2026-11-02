-- Enrollment Number : 2552562140
-- Name              : Gufran

-- Course Code       : BCSL-135
-- Course Title      : DBMS and C++ Lab
-- Assignment Number : BCA_NEW/BCAOL(III)L-135/Assign/2026-27

-- SECTION A: Database Schema and Queries
-- (b) SQL Queries:
-- Write SQL queries for the following operations on the database you designed:


-- 1. Display the customer name, vehicle registration number, service date, and
-- service type for all vehicles serviced during a specified month.
SELECT
    c.Customer_Name,
    v.Registration_Number,
    s.Service_Date,
    s.Service_Type
FROM Customer c
JOIN Vehicle v
    ON c.Contact_ID = v.Contact_ID
JOIN Service s
    ON v.Vehicle_ID = s.Vehicle_ID
WHERE MONTH(s.Service_Date) = 8
    AND YEAR(s.Service_Date) = 2026;


-- 2. List the names of customers who own more than one vehicle.
SELECT
    c.Customer_Name,
    COUNT(v.Vehicle_ID) AS Number_Of_Vehicles
FROM Customer c
JOIN Vehicle v
    ON c.Contact_ID = v.Contact_ID
GROUP BY c.Contact_ID, c.Customer_Name
HAVING COUNT(v.Vehicle_ID) > 1;


-- 3. Display the mechanic name along with the total number of vehicles serviced by
-- each mechanic.
SELECT
    m.Mechanic_Name,
    COUNT(DISTINCT s.Vehicle_ID) AS Vehicles_Serviced
FROM Mechanic m
LEFT JOIN Service s
    ON m.Mechanic_ID = s.Mechanic_ID
GROUP BY m.Mechanic_ID, m.Mechanic_Name;


-- 4. Find the registration numbers and owner names of vehicles that have never
-- undergone servicing.
SELECT
    v.Registration_Number,
    c.Customer_Name
FROM Vehicle v
JOIN Customer c
    ON v.Contact_ID = c.Contact_ID
LEFT JOIN Service s
    ON v.Vehicle_ID = s.Vehicle_ID
WHERE s.Service_ID IS NULL;


-- 5. Display the service history of a specified vehicle in chronological order.
SELECT
    s.Service_ID,
    s.Service_Date,
    s.Service_Type,
    s.Labour_Charges,
    s.Spare_Parts_Cost,
    s.Total_Bill_Amount
FROM Service s
WHERE s.Vehicle_ID = 101
ORDER BY s.Service_Date ASC;


-- 6. Calculate the total service expenditure incurred by each customer.
SELECT
    c.Customer_Name,
    SUM(s.Total_Bill_Amount) AS Total_Expenditure
FROM Customer c
JOIN Vehicle v
    ON c.Contact_ID = v.Contact_ID
JOIN Service s
    ON v.Vehicle_ID = s.Vehicle_ID
GROUP BY c.Contact_ID, c.Customer_Name;


-- 7. Retrieve the details of vehicles whose total service cost exceeds ₹50,000.
SELECT
    v.Registration_Number,
    c.Customer_Name,
    SUM(s.Total_Bill_Amount) AS Total_Service_Cost
FROM Vehicle v
JOIN Customer c
    ON v.Contact_ID = c.Contact_ID
JOIN Service s
    ON v.Vehicle_ID = s.Vehicle_ID
GROUP BY v.Vehicle_ID,
    v.Registration_Number,
    c.Customer_Name
HAVING SUM(s.Total_Bill_Amount) > 50000;


-- 8. Display the average labour charges for each service type.
SELECT
    Service_Type,
    AVG(Labour_Charges) AS Average_Labour_Charges
FROM Service
GROUP BY Service_Type;


-- 9. List the names of spare parts replaced during a specified service transaction.
SELECT
    p.Part_Name,
    sp.Quantity,
    sp.Unit_Price
FROM Service_Part sp
JOIN Spare_Part p
    ON sp.Part_ID = p.Part_ID
WHERE sp.Service_ID = 1001;


-- 10. Display the top five customers based on the highest expenditure on vehicle
-- servicing.
SELECT
c.Customer_Name,
    SUM(s.Total_Bill_Amount) AS Total_Expenditure
FROM Customer c
JOIN Vehicle v
    ON c.Contact_ID = v.Contact_ID
JOIN Service s
    ON v.Vehicle_ID = s.Vehicle_ID
GROUP BY c.Contact_ID, c.Customer_Name
ORDER BY Total_Expenditure DESC
LIMIT 5;
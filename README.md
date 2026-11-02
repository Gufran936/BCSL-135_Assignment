# BCSL-135: DBMS and C++ Lab — Submission Repository

This repository contains the complete source code, queries, official question documents, and structural organization for the **BCSL-135 (DBMS and C++ Lab)** Assignment submission. 

---

## 👨‍🎓 Student Details
- **Name:** Gufran
- **Enrollment Number:** 2552562140
- **Course Code:** BCSL-135
- **Course Title:** DBMS and C++ Lab
- **Assignment Number:** BCA_NEW/BCAOL(III)L-135/Assign/2026-27
- **Semester:** 3

---

## 📁 Repository Structure

```text
BCSL-135_Assignment/
│
├── README.md                                       <-- Repository documentation
│
├── 00_BCSL-135_Assignment_Question_Paper.pdf       <-- Official question paper
│
├── 01_SECTION-A_DBMS/                              <-- Section A: Database Management Systems
│   ├── (a)_Database_Schema.sql                     <-- Database creation and table schemas
│   └── (b)_SQL_Queries.sql                         <-- DML/DDL queries and operations
│
└── 02_SECTION-B_C++/                               <-- Section B: C++ Programming Lab
    └── C++_main_program.cpp                        <-- C++ implementation source code
```
---

## ⚙️ Technical Environment & Notes for Evaluators

* **C++ Programming Environment:**
  * **Language:** Standard ISO C++ (`.cpp`)
  * **Compiler:** GCC (MinGW 32-bit) via Visual Studio Code.
  * **Compatibility:** Adheres to standard C++ guidelines without relying on legacy headers (such as `<conio.h>` or `clrscr()`). Can be compiled and run using:
    ```bash
    g++ C++_main_program.cpp -o main_program
    ./main_program
    ```

* **DBMS / SQL Environment:**
  * **Database System:** MySQL (Compatible with MySQL Workbench and MySQL Command Line Client).
  * **Execution Order:** 
    1. First, run `(a)_Database_Schema.sql` to create the database, tables, and constraints.
    2. Then, execute `(b)_SQL_Queries.sql` to test the required DML/DDL queries and table manipulations.

* **Assumptions & Implementation Details:**
  * Where question descriptions left specific UI formatting, edge cases, or extra attribute fields open, clean and logical parameters have been assumed to ensure data integrity and smooth program flow.
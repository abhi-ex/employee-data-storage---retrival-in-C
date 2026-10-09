# Employee Data Storage and Retrieval

This project is a simple C program for managing employee records in a binary file.

## Features

- Add a new employee record
- Display all saved employee records
- Store employee data permanently in `employee.dat`
- Manage a small employee database from a text-based menu

## Data Stored

Each employee record stores:

- Employee ID
- Employee Name
- Employee Salary

## File Structure

The program writes each employee as a `struct Employee` into `employee.dat`.

## Build

```bash
gcc pr12.c -o pr12
```

## Run

```bash
./pr12
```

## Menu Options

1. Add Employee
2. Display Employees
3. Exit

## Notes

The employee name input accepts a full name with spaces, and the data is saved in binary format for quick storage and retrieval.

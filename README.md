# Bank Application in C++

## Overview

**Bank Application in C++** is a comprehensive C++ project that simulates a simple yet robust banking system, built with strong Object-Oriented Programming (OOP) fundamentals. This application allows users to create accounts, log in, and perform typical banking operations (such as deposits, withdrawals, and balance checks) within a secure and extensible framework.

This project is ideal for demonstrating practical OOP concepts, user authentication, and basic banking logic, making it an excellent learning and assessment tool for students and developers alike.

---

## Key Features

- **User Authentication:**  
  Multiple users can log in using pre-defined usernames and passwords stored securely in a file.
- **Account Management:**  
  Users can create new bank accounts, each with unique account numbers and client information.
- **Deposits and Withdrawals:**  
  Perform secure transactions with balance validation and error checking.
- **Balance Inquiry:**  
  Instantly check your current account balance.
- **Transaction History:**  
  Track and display a user's complete transaction history (if implemented).
- **Data Persistence:**  
  User credentials and account data are saved to files, ensuring information is retained across sessions.
- **Clean OOP Design:**  
  Encapsulation, inheritance, abstraction, and (optionally) polymorphism are used to maintain scalable and organized code.

---

## OOP Concepts Utilized

- **Encapsulation:**  
  Sensitive data (such as user credentials and balances) are made private and accessed via public methods.
- **Inheritance:**  
  Common attributes and methods are implemented in base classes (such as `User` or `Account`) and reused in derived classes.
- **Abstraction:**  
  Complex details (like transaction processing) are hidden behind simple interfaces.
- **Polymorphism (if present):**  
  Enables easy extension for different types of accounts (such as savings, checking, etc.).

---

## How It Works

### 1. User Authentication

Upon startup, the application loads a list of users from a file (e.g., `users.txt`). Each user has a username and password. Only authenticated users can access their bank accounts and perform operations.

**Sample users you can log in with:**

```
username: Rout   password: 1111
username: Voss     password: 1133
```

(These users/passwords are samples—check the `users.txt` file in the repository for the latest credentials.)

### 2. Account and Transaction Management

After logging in, users can:
- **View account details:** See account number, balance, and personal information.
- **Deposit funds:** Add money to your account.
- **Withdraw funds:** Take out money (with balance validation).
- **Check balance:** Display your current balance.
- **View transaction history:** (If implemented) See a record of your deposits and withdrawals.
- **Log out:** Safely end your session.

### 3. Data Storage

- User credentials and account information are stored in text or binary files.
- All changes (such as transactions or new users) are written back to these files, ensuring persistence.

### 4. Security

- Passwords are not displayed on the screen.
- Only authenticated users can access account features.

---

## How to Build & Run

1. **Compile the Application:**
   ```sh
   g++ -std=c++11 -o bank main.cpp
   ```
   *(Modify the compile command according to your file structure if needed.)*

2. **Run the Application:**
   ```sh
   ./bank
   ```

---

## Example Usage

1. **Login with a sample user:**
    - Username: `Rout`
    - Password: `1111`

2. **Menu Options:**
    - 1) Check balance
    - 2) Deposit
    - 3) Withdraw
    - 4) View transaction history (if available)
    - 5) Logout

3. **Try depositing or withdrawing, then check your balance to see updates.**

---

## Project Structure

- `main.cpp` — Entry point and main application logic.
- `User.h/.cpp` — User and authentication logic.
- `Account.h/.cpp` — Bank account management.
- `Transaction.h/.cpp` — (Optional) Transaction history handling.
- `users.txt` — List of sample users and passwords.
- `accounts.txt` — Account data storage.

---

## Extending the Application

- **Add new features:** Such as fund transfers, account types, or admin controls.
- **Improve security:** Implement password hashing and access controls.
- **Enhance UI:** Add a graphical or web-based interface.

---

## License

This project is open for educational and personal use.

---

**Author:** aybouatr

# OOP-Based Supermarket Billing System

A C++ program that implements an **Object-Oriented Billing System** for a supermarket. The system allows users to add items, manage inventory, and calculate total bills with automated updates to the inventory. Designed with simplicity and functionality in mind, this program demonstrates core OOP principles such as encapsulation and abstraction.

---

## Features

- **Add Items**: Add new items to the inventory with details like name, rate, and quantity.
- **Print Bill**: Generate bills for purchased items and update the inventory accordingly.
- **File-Based Storage**: Inventory is saved and updated in a file for persistence.
- **Error Handling**: Handles errors such as unavailable items or insufficient stock.
- **User-Friendly Interface**: Provides clear prompts and feedback.

---

## How It Works

1. **Main Menu**:
   - Add items to the inventory.
   - Generate and print bills for purchased items.
   - Exit the application.

2. **Add Item**:
   - Enter the item's name, rate, and quantity.
   - Save the details to a file (`D:/Bill.txt`).

3. **Print Bill**:
   - Select an item and quantity to purchase.
   - Update inventory and display total bill amount.

---

## Requirements

- **Operating System**: Windows (for `windows.h` functions like `Sleep`).
- **Compiler**: GCC/MinGW or any C++ compiler supporting C++11 or later.

---

## Installation and Execution

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/your-username/oop-billing-system.git
   cd oop-billing-system

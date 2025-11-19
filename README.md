# 📦 Inventory Management System (C)

A simple **Inventory Management System** implemented in **C** using
**file handling**.\
This project manages **Items**, **Purchases**, and **Sales** with full
CRUD operations.

## 📑 Table of Contents

-   [Features](#features)
-   [Project Structure](#project-structure)
-   [Data Files](#data-files)
-   [Item File Structure](#item-file-structure)
-   [Purchase File Structure](#purchase-file-structure)
-   [Sales File Structure](#sales-file-structure)
-   [How to Compile & Run](#how-to-compile--run)
-   [Technologies Used](#technologies-used)
-   [Future Enhancements](#future-enhancements)

## ⭐ Features

### 🔹 Core Operations

Each module supports: - Insert a Record - Edit a Record - Delete a
Record - View Records

### 🔹 Modules

-   Item Module
-   Purchase Module
-   Sales Module

### 🔹 Additional Logic

-   Automatic stock update during purchase and sales
-   Calculation of amount, rate, tax
-   Binary file handling for persistent data

## 🏗 Project Structure

    📁 Inventory-Management-System
    │── main.c
    │── item.c
    │── purchase.c
    │── sales.c
    │── itemfile.dat
    │── purchasefile.dat
    │── salesfile.dat
    │── README.md

## 📁 Data Files Used

-   itemfile.dat -- Stores item details
-   purchasefile.dat -- Stores purchase records
-   salesfile.dat -- Stores sales records

## 📦 Item File Structure

  No   Field           Variable   Type
  ---- --------------- ---------- ------------
  1    Item Code       it_code    int
  2    Item Name       it_name    char\[20\]
  3    Item Price      it_price   int
  4    Opening Stock   it_os      int
  5    Closing Stock   it_cs      int

## 🛒 Purchase File Structure

  No   Field               Variable   Type
  ---- ------------------- ---------- ------------
  1    Purchase Number     p_no       int
  2    Purchase Date       p_date     char\[20\]
  3    Client Code         c_code     int
  4    Client Name         c_name     char\[20\]
  5    Product Code        p_code     int
  6    Purchase Quantity   p_qty      int
  7    Purchase Price      p_price    int
  8    Purchase Amount     p_amt      int

## 🧾 Sales File Structure

  No   Field          Variable   Type
  ---- -------------- ---------- ------------
  1    Bill Number    b_no       int
  2    Bill Date      b_date     char\[10\]
  3    Product Code   p_code     int
  4    Quantity       b_qty      int
  5    Rate           b_rate     int
  6    Tax            b_tax      int
  7    Amount         b_amt      int

## ▶️ How to Compile & Run

### Compile:

    gcc main.c item.c purchase.c sales.c -o inventory

### Run:

    ./inventory

## ⚙️ Technologies Used

-   C Programming Language
-   File Handling (binary)
-   Modular Programming
-   CRUD Operations

## 📊 Stock Update Logic

    closing_stock = opening_stock + purchase_quantity - sales_quantity

## 🚀 Future Enhancements

-   Add login authentication
-   Implement searching & sorting
-   Generate formatted reports
-   Export data to CSV
-   Add GUI version

## 📜 License

Open-source and free to use.

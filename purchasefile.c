#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void addPurchaseItem(); //Arjun Santhosh
void editPurchaseItem(); //Adwaith A
void deletePurchaseItem(); //Anjali Suresh
void viewPurchaseItem(); //Reshmi S

struct purchasefile{
    int p_no;                       //Purchase Number
    char p_date[20];                //Purchase Date
    int c_code;                     //Client code
    char c_name[50];                //Client Name
    int p_code;                     //Product Code
    int p_qty;                      //Product Quantity
    float p_price;                  //Product Price
    float p_amt;                    //Product Amount
};

int main(){

}

//filename = purchasefile.dat ethu venee kodukkan
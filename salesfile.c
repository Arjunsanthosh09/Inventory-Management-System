#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void addSalesItem(); // Shrihan Sajeev
void editSalesItem(); //Joel Thomas Chandy
void deleteSalesItem(); //Chinnu S
void viewSalesItem(); //Nisam Rahman K


struct salesfile{
    int b_no;                       //Bill Number
    char b_date[10];                //Bill Date
    int p_code;                     //Product Code
    int b_qty;                      //Quantity
    float b_rate;                   //Rate
    float b_tax;                    //Tax
    float b_amt;                    //Amount
};

int main(){

}

//filename = salesfile.dat ethu venee kodukkan
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// oroo filesinte menu aanu ethuu
void itemMenu();
void purchaseMenu();
void salesMenu();

// sub functions of main menu

// functions for item file menu

void addItem(); //done [done the logic for that there should be not duplicated item code or item name should be added ]
void editItem(); //done [ done the logic for editing item file based on item code ]
void deleteItem(); //done the logic for deleting item based on item code ( firstly checking the item code is available or not and the  we create a temp file and copy all the data except the deleted item code and then rename the temp file to itemfile.dat)
void viewItem(); //done 

//sub functions of purchase file menu

void addPurchaseItem(); //done [ logic also done the item quantity updating and also checking the product code and also checking the purchase number is duplicated or not ]
void editPurchaseItem();
void deletePurchaseItem();
void viewPurchaseItem(); //done

// sub functions of sales file menu

void addSalesItem(); //done [ logic also done the checking of duplicated bill number ]
void editSalesItem();
void deleteSalesItem();
void viewSalesItem(); //done

//---------------------------------------------------------------------------------------------------------------------------------------------------------------
//Extra functions for checking validation, stock update, stop duplication data 

int checkProductCode(int p_code); //for checking the product code is already available in the itemfile or not
int CheckitemcodeName(int item_code,char item_name[]); // For checking the item code and item name is already in the item name or not 
int updateStock(int quantity, int p_code); // after purchasing item the stock should be updated in the itemfile
int CheckPurchaseNumber(int p_no); // to check where the purchase number is already present in the purchase file or not
int CheckBillNumber(int b_no); // to check  whether the bill number  is already present in the sales fieles or not 
int RetrievePrice(int p_code, float *price); // to retrieve the price from itemfile based on product code
int CheckProductQuantity(int p_code, int quantity); // to check whether the available stock is sufficient for selling or not
void UpdateStockAfterSale(int p_code, int qty); // to update the stock after selling the item
//--------------------------------------------------------------------------------------------------------------------------------------------------/
// structure definitions for three files 

struct itemfile{
    int item_code;                   //Item Code
    char item_name[50];              //Item Name
    float it_price;                  //Item Price
    int it_os;                       //Opening Stock
    int it_cs;                       //Closing Stock
    //opening stock and closing stockum same value venam enter cheyyan 
};

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

struct salesfile{
    int b_no;                       //Bill Number
    char b_date[10];                //Bill Date
    int p_code;                     //Product Code
    int b_qty;                      //Quantity
    float b_rate;                   //Rate
    float b_tax;                    //Tax
    float b_amt;                    //Amount
};

//--------------------------------------------------------------------------------------------------------------------------------------------------/

int main(){
    struct itemfile item;                         //itemfile variable
    struct purchasefile purchase;                 //purchasefile variable    
    struct salesfile sales;                       //salesfile variable
    int choice;
    while (1){
         printf("\n\n----------------------------------------------------------------\n");
         printf("        Welcome to Inventory Management System        ");
         printf("\n----------------------------------------------------------------\n");

         printf("*******************************************\n");
         printf("               Main Menu               \n");
         printf("*******************************************\n");

         printf("\n\n Please select from the following options:");
         printf("\n----------------------------------------");

         printf("\n\n 1. Item File Management File");
         printf("\n 2. Purchase File Management File");
         printf("\n 3. Sales File Management File");
         printf("\n 4. Exit");
         printf("\n\n----------------------------------------\n\n");

         printf("Enter your choice:");
         scanf("%d",&choice);
         
         switch(choice){

            case 1:
                itemMenu();
                break;
            
            case 2:
                purchaseMenu();
                break;
            
            case 3:
                salesMenu();
                break;
            
            case 4:
                printf("\nExiting the program. Goodbye!\n");
                return 0;
            
            default:
                printf("\nInvalid choice. Please try again.\n");

         } //switch case closing

    } // while loop closing
    
   
                           
} // main function closing

//****************************SUB FUNCTIONS OF MAIN MENU******************************************** 

void itemMenu(){
    printf("\n**********************  ITEM FILE MENU **********************\n");
    int choice;
    printf("\n 1. Add New item");
    printf("\n 2. Edit Item FIle");
    printf("\n 3. Delete Item File");
    printf("\n 4. View Item File");
    printf("\n 5. Return to Main Menu");
    printf("\n Enter your choice : ");
    scanf("%d",&choice);

    switch (choice)
    {
        case 1:
            printf("\n -------------- Add New Items --------------");
            addItem();
            break;
        case 2:
            printf("\n -------------- Edit Items --------------");
            editItem();
            break;
        case 3:
            printf("\n -------------- Delete Items --------------");
            deleteItem();
            break;
        case 4:
            printf("\n -------------- View Items --------------");
            viewItem();
            break;
        case 5:
            printf("\n Returning to Main Menu...");
            return;
            break;
    default:
        printf("\nInvalid choice. Please try again.\n");
        break;
    }
}

void purchaseMenu(){
    printf("\n**********************  ITEM FILE MENU **********************\n");
    int choice;
    printf("\n 1. Add New Purchase Item");
    printf("\n 2. Edit Purchase  FIle");
    printf("\n 3. Delete Purchase File");
    printf("\n 4. View Purchase File");
    printf("\n 5. Return to Main Menu");
    printf("\n Enter your choice : ");
    scanf("%d",&choice);

    switch (choice)
    {
        case 1:
            printf("\n -------------- Add New Purchase Item --------------");
            addPurchaseItem();
            break;
        case 2:
            printf("\n -------------- Edit Purchase Item --------------");
            break;
        case 3:
            printf("\n -------------- Delete Purchase Items --------------");
            break;
        case 4:
            printf("\n -------------- View Purchase Items --------------");
            viewPurchaseItem();
            break;
        case 5:
            printf("\n Returning to Main Menu...");
            return;
            break;
    default:
        printf("\nInvalid choice. Please try again.\n");
        break;
    }
}

void salesMenu(){
    printf("\n**********************  ITEM FILE MENU **********************\n");
    int choice;
    printf("\n 1. Add New Sale's Item");
    printf("\n 2. Edit Sale's  FIle");
    printf("\n 3. Delete Sale's File");
    printf("\n 4. View Sale's File");
    printf("\n 5. Return to Main Menu");
    printf("\n Enter your choice : ");
    scanf("%d",&choice);

    switch (choice)
    {
        case 1:
            printf("\n -------------- Add New Sale's Item --------------");
            addSalesItem();
            break;
        case 2:
            printf("\n -------------- Edit Sale's Item --------------");
            break;
        case 3:
            printf("\n -------------- Delete Sale's Items --------------");
            break;
        case 4:
            printf("\n -------------- View Sale's Items --------------");
            viewSalesItem();
            break;
        case 5:
            printf("\n Returning to Main Menu...");
            return;
            break;
    default:
        printf("\nInvalid choice. Please try again.\n");
        break;
    }
}

//sub function definitions of item menu

void addItem() {
    FILE *fp;
    struct itemfile item;
    printf("\n Enter Item Code: ");
    scanf("%d", &item.item_code);
    
    printf("\n Enter the Item Name: ");
    scanf("%s", item.item_name); 
    
    printf("\n Enter the Item Price: ");
    scanf("%f", &item.it_price);
    
    printf("\n Enter the Opening Stock: ");
    scanf("%d", &item.it_os);
    
    item.it_cs = item.it_os;
    if (CheckitemcodeName(item.item_code, item.item_name)) {
        printf("\n Error: Item Code or Name already exists!");
        return;
    }
    fp = fopen("itemfile.dat", "ab+");
    if (fp == NULL) {
        printf("\n Error opening the file..");
        return;
    }
    fwrite(&item, sizeof(item), 1, fp);
    printf("\n Item added successfully!");
    fclose(fp);
}
void editItem(){
    FILE *fp;
    fp=fopen("itemfile.dat","rb+");
    if (fp==NULL){
        printf("\n Error opening th file..");
        return;
    }   
    struct itemfile item;
    int items_code,found=0;
    printf("\n Enter the Item Code to edit:");
    scanf("%d",&items_code);
    while (fread(&item,sizeof(item),1,fp)) {
        if (item.item_code==items_code){
            found=1;
            printf("\n Enter the new Item Name:");
            scanf("%s",item.item_name);
            printf("\n Enter the new Item Price:");
            scanf("%f",&item.it_price);
            printf("\n Enter the new Opening Stock:");
            scanf("%d",&item.it_os);
            item.it_cs=item.it_os; //updating closing stock as opening stock
            fseek(fp,-sizeof(item),SEEK_CUR);
            fwrite(&item,sizeof(item),1,fp);
            printf("\n Item updated successfully!");
            break;
        }
    }
    if (found==0){
        printf("\n Item with code %d not found.",items_code);
    }

}

void deleteItem(){
    FILE *fp;
    int item_code, found = 0;

    fp = fopen("itemfile.dat", "rb");
    if(fp == NULL){
        printf("\n Error opening the file..");
        return;
    }

    printf("\n Enter the Item code to delete:");
    scanf("%d", &item_code);

    FILE *temp_fp = fopen("temp.dat", "wb");
    if(temp_fp == NULL){
        printf("\n Error opening temp file..");
        fclose(fp);
        return;
    }

    struct itemfile item;

    while(fread(&item, sizeof(item), 1, fp)){
        if(item.item_code == item_code){
            found = 1;
            printf("\n Item with code %d deleted successfully!", item_code);
            continue;  
        }
        fwrite(&item, sizeof(item), 1, temp_fp);
    }

    fclose(fp);
    fclose(temp_fp);

    if(found == 0){
        printf("\n Item with code %d not found.", item_code);
        remove("temp.dat");
    } 
    else {
        remove("itemfile.dat");
        rename("temp.dat", "itemfile.dat");
    }
}


void viewItem(){
    FILE *fp;
    struct itemfile item;
    fp=fopen("itemfile.dat","rb");
    if (fp==NULL){
        printf("\n Error opening the file..");
        return;
    }
    
    printf("\n------------------ Item List ------------------\n");
    printf("\n%-12s %-15s %-12s %-15s %-15s\n", 
           "Item Code", "Item Name", "Item Price", "Opening Stock", "Closing Stock");
    printf("-----------------------------------------------------------------------------\n");
    
    while (fread(&item,sizeof(item),1,fp)){
        printf("%-12d %-15s %-12.2f %-15d %-15d\n",
               item.item_code, item.item_name, item.it_price, item.it_os, item.it_cs);
    }
    fclose(fp);
}

//sub function definitions of Purchase file menu

void addPurchaseItem(){

    FILE *fp;
    struct purchasefile pur;

    printf("\n Enter the Product Code:");
    scanf("%d",&pur.p_code);

    if (checkProductCode(pur.p_code) == 0){
        printf("\n ERROR: Product Code does not exist in Item File!");
        printf("\n Purchase Cancelled.\n");
        return;  
    }
    fp=fopen("purchasefile.dat","ab+");
    if (fp==NULL){
        printf("\n Error opening the file..");
        return;
    }
    printf("\n Enter the Purchase Number:");
    scanf("%d",&pur.p_no);
    if (CheckPurchaseNumber(pur.p_no==0))
    {
        printf("\n ERROR: Purchase Number already exists!");
        fclose(fp);
        return;
    }
    printf("\n Enter the purchase date (in DD-MM-YYYY):");
    scanf("%s",pur.p_date);
    printf("\n Enter the Client Code:");
    scanf("%d",&pur.c_code);
    printf("\n Enter the client Name:");
    scanf(" %[^\n]", pur.c_name);
    printf("\n Enter the Product Quantity:");
    scanf("%d",&pur.p_qty);
    printf("\n Enter the product Price:");
    scanf("%f",&pur.p_price);
    pur.p_amt = pur.p_qty * pur.p_price;
    fwrite(&pur, sizeof(pur), 1, fp);
    fclose(fp);
    printf("\n Purchase Item added successfully!");
    int found = updateStock(pur.p_qty, pur.p_code);
    if (found == 1){
        printf("\n Stock Updated Successfully!\n");
    } else {
        printf("\n Warning: Stock update failed.\n");
    }
}

void viewPurchaseItem() {
    FILE *fp;
    struct purchasefile pur;

    fp = fopen("purchasefile.dat", "rb");
    if (fp == NULL) {
        printf("\n Error opening the file..\n");
        return;
    }
    printf("\n------------------ Purchase Item List ------------------\n");
    printf("\n%-15s %-15s %-15s %-20s %-15s %-10s %-12s %-12s\n",
           "Purchase No", "Purchase Date", "Client Code", "Client Name",
           "Product Code", "Quantity", "Price", "Amount");
    printf("---------------------------------------------------------------------------------------------------------------\n");
    while (fread(&pur, sizeof(pur), 1, fp)) {
        printf("%-15d %-15s %-15d %-20s %-15d %-10d %-12.2f %-12.2f\n",
               pur.p_no,pur.p_date,pur.c_code,pur.c_name,pur.p_code,pur.p_qty,pur.p_price,pur.p_amt);
    }

    fclose(fp);
}

//sub function definitions of sales file menu

void addSalesItem(){
    FILE *fp;
    struct salesfile sales;
    float price;
    fp = fopen("salesfile.dat", "ab+");
    
    if (fp == NULL){
        printf("\n Error opening the file..");
        return;
    }

    printf("\n Enter the Bill Number:");
    scanf("%d", &sales.b_no);

    if (CheckBillNumber(sales.b_no) == 1){
        printf("\n ERROR: Bill Number already exists!");
        fclose(fp);
        return;
    }

    printf("\n Enter the Bill Date (DD-MM-YYYY):");
    scanf("%s", sales.b_date);

    printf("\n Enter the Product Code:");
    scanf("%d", &sales.p_code);

    if (checkProductCode(sales.p_code) == 0){
        printf("\n ERROR: Product Code does not exist!");
        printf("\n Sales Cancelled.\n");
        fclose(fp);
        return;
    }

    if (RetrievePrice(sales.p_code, &price) == 0){
        printf("\n ERROR: Unable to retrieve product price!");
        fclose(fp);
        return;
    }

    printf("\n Product Price Retrieved Automatically: %.2f", price);
    sales.b_rate = price;     

    printf("\n Enter the Product Quantity:");
    scanf("%d", &sales.b_qty);

    if (CheckProductQuantity(sales.p_code, sales.b_qty) == 0){
        printf("\n ERROR: Insufficient stock OR stock is zero!");
        printf("\n Sales Cancelled.\n");
        fclose(fp);
        return;
    }

    printf("\n Enter the Product Tax in percentage:");
    scanf("%f", &sales.b_tax);

    sales.b_amt = (sales.b_qty * sales.b_rate) + 
                  ((sales.b_qty * sales.b_rate) * (sales.b_tax / 100));

    fwrite(&sales, sizeof(sales), 1, fp);
    fclose(fp);

    printf("\n Sales Item added successfully!");

    UpdateStockAfterSale(sales.p_code, sales.b_qty);
}


void viewSalesItem() {
    FILE *fp;
    struct salesfile sales;

    fp = fopen("salesfile.dat", "rb");
    if (fp == NULL) {
        printf("\n Error opening the file..\n");
        return;
    }
    printf("\n----------------------- Sales Item List -----------------------\n");
    printf("\n%-15s %-15s %-15s %-12s %-12s %-10s %-12s\n",
           "Bill No", "Bill Date", "Product Code",
           "Quantity", "Rate", "Tax", "Amount");

    printf("-------------------------------------------------------------------------------\n");

    while (fread(&sales, sizeof(sales), 1, fp)) {
        printf("%-15d %-15s %-15d %-12d %-12.2f %-10.2f %-12.2f\n",
               sales.b_no, sales.b_date, sales.p_code,
               sales.b_qty, sales.b_rate, sales.b_tax, sales.b_amt);
    }

    fclose(fp);
}


//***************************************************************************************************************************** */

//Extra functions needed for validation ,stock update , duplication check etc.

//we have to check the product code is available in itemfile or not before adding purchase item

int checkProductCode(int p_code){
    FILE *fp;
    struct itemfile item;
    int found=0;
    fp=fopen("itemfile.dat","rb");
    if (fp==NULL){
        printf("\n Error opening the file..");
        return 0;
    }
    while (fread(&item,sizeof(item),1,fp)){
        if (item.item_code==p_code){
            found=1;
            break;
        }
    }
    fclose(fp);
    return found;
}

// we also need to update the closing stock in itemfile after adding purchase item

int updateStock(int quantity, int p_code){
    FILE *fp, *temp_fp;
    struct itemfile item;
    int found=0;
    fp=fopen("itemfile.dat","rb");
    temp_fp=fopen("temp.dat","wb");
    if (fp==NULL || temp_fp==NULL){
        printf("\n Error opening the file..");
        return 0;
    }
    while (fread(&item,sizeof(item),1,fp)){
        if (item.item_code==p_code){
            item.it_cs += quantity;
            found=1;
        }
        fwrite(&item,sizeof(item),1,temp_fp);
    }
    fclose(fp);
    fclose(temp_fp);
    remove("itemfile.dat");
    rename("temp.dat","itemfile.dat");
    return found;
}

// we must ensure that no duplicated item code or item name should be added to the file so that it should be more reliable

int CheckitemcodeName(int item_code, char item_name[]) {
    FILE *fp;
    struct itemfile item;
    int found = 0;
    fp = fopen("itemfile.dat", "rb");
    if (fp == NULL) {
        printf("\n Error opening the file..");
        return 0;
    }
    while (fread(&item, sizeof(item), 1, fp)) {
        if (item.item_code == item_code || strcmp(item.item_name, item_name) == 0) {
            found = 1;
            break;
        }
    }
    fclose(fp);
    return found;
}

// we must ensure that no duplicate purchase numbeer should be added to the file so that it should be more reliable

int CheckPurchaseNumber(int p_no){
    FILE *fp;
    struct purchasefile pur;
    int found=0;
    fp=fopen("purchasefile.dat","rb");
    if (fp==NULL){
        printf("\n Error opening the file..");
        return 0;
    }
    while (fread(&pur,sizeof(pur),1,fp)){
        if (pur.p_no==p_no){
            found=1;
            break;
        }
    }
    fclose(fp);
    return found;
}

// we must ensure that no duplicate Bill  numbeer should be added to the file so that it should be more reliable

int CheckBillNumber(int b_no){
    FILE *fp;
    struct salesfile sales;
    int found=0;
    fp=fopen("salesfile.dat","rb");
    if (fp==NULL){
        printf("\n Error opening the file..");
        return 0;
    }
    while (fread(&sales,sizeof(sales),1,fp)){
        if (sales.b_no==b_no){
            found=1;
            break;
        }
    }
    fclose(fp);
    return found;
}

int RetrievePrice(int p_code, float *price){
    FILE *fp;
    struct itemfile item;
    fp = fopen("itemfile.dat", "rb");
    if(fp == NULL){
        printf("\n Error opening the file...");
        return 0;
    }
    while(fread(&item, sizeof(item), 1, fp)){
        if(item.item_code == p_code){
            *price = item.it_price;
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

int CheckProductQuantity(int p_code, int quantity){
    FILE *fp;
    struct itemfile item;
    fp = fopen("itemfile.dat", "rb");
    if(fp == NULL){
        printf("\n Error opening the file...");
        return 0;
    }
    while(fread(&item, sizeof(item), 1, fp)){
        if(item.item_code == p_code){
            fclose(fp);
            return (item.it_cs >= quantity);  
        }
    }
    fclose(fp);
    return 0;
}

// Function to update the stock after a sale has been made
void UpdateStockAfterSale(int p_code, int qty){
    FILE *fp;
    struct itemfile item;

    fp = fopen("itemfile.dat", "rb+");
    if(fp == NULL){
        printf("\n Error opening item file...");
        return;
    }

    while(fread(&item, sizeof(item), 1, fp)){
        if(item.item_code == p_code){
            item.it_cs -= qty;   // reduce closing stock
            fseek(fp, -sizeof(item), SEEK_CUR);
            fwrite(&item, sizeof(item), 1, fp);
            break;
        }
    }

    fclose(fp);
}


//************************************************************************************************************************************************* */
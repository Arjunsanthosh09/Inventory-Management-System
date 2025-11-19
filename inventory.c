#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// oroo filesinte menu aanu ethuu
void itemMenu();
void purchaseMenu();
void salesMenu();

// sub functions of main menu

void addItem();
void editItem();
void deleteItem();
void viewItem();

void addPurchaseItem();
void editPurchaseItem();
void deletePurchaseItem();
void viewPurchaseItem();

void addSalesItem();
void editSalesItem();
void deleteSalesItem();
void viewSalesItem();

int checkProductCode(int p_code);
int CheckitemcodeName(int item_code,char item_name[]);
int updateStock(int quantity, int p_code);

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
            break;
        case 3:
            printf("\n -------------- Delete Items --------------");
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
            break;
        case 2:
            printf("\n -------------- Edit Purchase Item --------------");
            break;
        case 3:
            printf("\n -------------- Delete Purchase Items --------------");
            break;
        case 4:
            printf("\n -------------- View Purchase Items --------------");
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
            addItem();
            break;
        case 2:
            printf("\n -------------- Edit Sale's Item --------------");
            break;
        case 3:
            printf("\n -------------- Delete Sale's Items --------------");
            break;
        case 4:
            printf("\n -------------- View Sale's Items --------------");
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
    printf("\n Enter the purchase date:");
    scanf("%s",pur.p_date);
    printf("\n Enter the Client Code:");
    scanf("%d",&pur.c_code);
    printf("\n Enter the client Name:");
    scanf("%s",pur.c_name);
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

//sub function definitions of sales file menu

void addSalesItem(){
    FILE *fp;
    struct salesfile sales;
    fp=fopen("salesfile.dat","ab+");
    if (fp==NULL){
        printf("\n Error opening the file..");
        return;
    }
    printf("\n Enter the Bill Number:");
    scanf("%d",&sales.b_no);
    printf("\n Enter the Bill Date:");
    scanf("%s",sales.b_date);
    printf("\n Enter the product Code:");
    scanf("%d",&sales.p_code);
    printf("\n Enter the Product Quantity:");
    scanf("%d",&sales.b_qty);
    printf("\n Enter the product Rate:");
    scanf("%f",&sales.b_rate);
    printf("\n Enter the Product Tax:");
    scanf("%f",&sales.b_tax);
    sales.b_amt=(sales.b_qty * sales.b_rate) + sales.b_tax;
    fwrite(&sales,sizeof(sales),1,fp);
    printf("\n Sales Item added successfully!");
    fclose(fp);
}

//sub function of addPurchaseItem()

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



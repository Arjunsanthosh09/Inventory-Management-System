#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void addItem();  // Gowtham Thulasi
void editItem(); //Vikhnesh S
void deleteItem(); //Akshay Prasad
void viewItem(); //Lakshmi Anil
int CheckitemcodeName(int item_code,char item_name[]); //Gowtham Thulasi



struct itemfile{
    int item_code;                   //Item Code
    char item_name[50];              //Item Name
    float it_price;                  //Item Price
    int it_os;                       //Opening Stock
    int it_cs;                       //Closing Stock

    //opening stock and closing stockum same value venam enter cheyyan 
};

int main(){

    
}




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

// filename = itemfile.dat ethu venee kodukkan

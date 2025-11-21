#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void addPurchaseItem(); //Arjun Santhosh
void editPurchaseItem(); //Adwaith A
void deletePurchaseItem(); //Anjali Suresh
void viewPurchaseItem(); //Reshmi S

//sub function addpurchasefile

int checkProductCode(int p_code); //Arjun Santhosh
int updateStock(int quantity, int p_code); //Arjun Santhosh
int CheckPurchaseNumber(int p_no); //Arjun Santhosh

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

//filename = purchasefile.dat ethu venee kodukkan
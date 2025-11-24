#include<stdio.h>
#include<stdlib.h>
void addItem();

struct itemfile{
    int item_code;                   //Item Code
    char item_name[50];              //Item Name
    float it_price;                  //Item Price
    int it_os;                       //Opening Stock
    int it_cs;                       //Closing Stock
    //opening stock and closing stockum same value venam enter cheyyan 
};
int main(){
    addItem();
}
void addItem(){
    FILE *fp;
    if fp==NULL{
        printf("error");
        return;
    }
    fp=fopen("itemfile.data","ab+");
    struct itemfile item;
    
 printf("enter the item code:");
    scanf("%d",&item.item_code);
    printf("enter the item name:");
    scanf("%s",item.item_name);
    printf("enter the item price:");
    scanf("%f",&item.it_price);
    printf("enter the opening stock:");
    scanf("%d",&item.it_os);
    printf("enter the closing stock:");
    scanf("%d",&item.it_cs);

}
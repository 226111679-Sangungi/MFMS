#include <stdio.h>
#include <string.h>




int searchAsset();
int displayAsset();

   int AssetID[10]= {0,1,2,3,4,5,6,7,8,9};
    char AssetName[10][50]={"2026 Audi Q2","2023 Iveco Daily", "Toshiba Qosmio", "Asus Tuff", "TGF 10400TGF 10400", 
                           "Tigre 4000F","Lenny Draughtsman Chair", "Orion Draughtsman Chair", "Einhell Li 18 V", "Ryobi 1250 W SDS-Plus Rotary Hammer"};
  char AssetType[10][50]={"Vehicle","Vehicle","Computer","Computer","Equipment","Equipment","Furniture","Furniture","Equipment","Equipment"};
 double PurchaseValue[10]={60000.00, 36000.00, 4000.00, 12000.00 , 9000.00 , 1100.00 ,400.00 ,200.00 , 2000.00, 4150.00};
 char Department[10][50]={"transport","transport","finance","finance","agriculture","agriculture","hr","hr","rnd","rnd"};
 char Condition[10][5]={"good","poor","poor","good","poor","good","good","good","good","poor"};


// call this function from the main menu to start asset managemnet
int assetManagement() {
   int done=0;
   int choice;
    

    printf("\n----Asset Management----\n");
    while (done == 0) {
    printf("Search or Display Asset details\n 1.Search 2.Display 3.Exit\n");
   scanf("%d", &choice);
      switch(choice){
         case 1:
         searchAsset();
         break;
         case 2:
         displayAsset();
         break;
         case 3:
         done = 1;
         
      }
    }
    return 0;  
}

   int searchAsset(){
      int found = 0;
      int searchID;
      printf("Enter ID of asset to be searched for:  ");
      scanf("%d", &searchID);
      for (int i = 0; i <= 9; i++) {
         if (searchID == AssetID[i]) {
            found = 1;
            
            
         }

      }
      if (found == 1){
         printf("Asset found\n");
      } else
       { printf("Asset not found\n");}
      return 0;
   }

   int displayAsset(){
     int displayID;
      printf("\n--Asset Display--\n");
      printf("Enter ID of asset to be displayed:  ");
      scanf("%d", &displayID);
      printf("\nAsset ID: %d\n", AssetID[displayID]);
      printf("Asset Name: %s\n", AssetName[displayID]);
       printf("Asset Type: %s\n", AssetType[displayID]);
       printf("Purchase Value: %f\n", PurchaseValue[displayID]);
        printf("Department: %s\n", Department[displayID]);
        printf("Condition: %s\n", Condition[displayID]);
    
   return 0;
   }

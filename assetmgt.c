#include <stdio.h>
#include "asset.h"





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

#include <stdio.h>
#include "asset.h"
#include <string.h>




// call this function from the main menu to start asset managemnet
int assetManagement() {
   int done=0;
   int choice;
    

    printf("\n----Asset Management----\n");
    while (done == 0) {
    printf("Search, Display or add an Asset details\n 1.Search 2.Display 3.Add 4. Exit:  ");
   scanf("%d", &choice);
      switch(choice){
         case 1:
         searchAsset();
         break;
         case 2:
         displayAsset();
         break;
         case 4:
         done = 1;
         break;
         case 3:
         addAsset();
         break;
         default:
         printf("Invalid option picked");
         
      }
    }
    return 0;  
}

 int addAsset(){
   
   for ( int i = 0; i < 4; i++){
      if (assetCouner < 10){
         printf("\nEnter asset name:  ");
         scanf("%s" , AssetName[assetCouner]);

         printf("\nEnter asset PurchaseValue:  ");
         scanf("%lf", &PurchaseValue[assetCouner]);

         printf("\nEnter asset Department:  ");
         scanf("%s", Department[assetCouner]);

         printf("\nEnter asset type:  ");
         scanf("%s" , AssetType[assetCouner]);

         printf("\nEnter asset Condition:  ");
         scanf("%s", Condition[assetCouner]);

       assetCouner = assetCouner+1;
       AssetID[assetCouner-1] = assetCouner-1;

       printf("\nAssets entered: %d/10\n", assetCouner);


      }else{
         printf("\nArray is full\n");

      }

   }
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

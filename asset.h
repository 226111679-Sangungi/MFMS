#ifndef ASSET_H
#define ASSET_H



int searchAsset();
int displayAsset();
   int assetCouner = 0;
   int AssetID[10];
    char AssetName[10][50];
  char AssetType[10][50];
 double PurchaseValue[10];
 char Department[10][50];
 char Condition[10][5];


// call this function from the main menu to start asset managemnet

   int assetManagement();
   int searchAsset();
   int addAsset();

   int displayAsset();
    
#endif
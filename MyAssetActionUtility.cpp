// Fill out your copyright notice in the Description page of Project Settings.

#include "MyAssetActionUtility.h"
#include "EditorUtilityLibrary.h"
#include "Engine/Texture.h"

#pragma region ReanmeSelectedAssets

void UMyAssetActionUtility::RenameSelectedAssets(FString SearchPattern, FString ReplacePattern, ESearchCase::Type SearchCase)
{
   // Check if something needs to be done
   if (SearchPattern.IsEmpty() || SearchPattern.Equals(ReplacePattern, SearchCase))
   {
      return;
   }

   // Get the selected objects
   TArray<UObject*> SelectedObjects = UEditorUtilityLibrary::GetSelectedAssets();

   uint32 Counter = 0;

   //Check each asset if it needs to be renamed
   for (UObject* SelectedObject : SelectedObjects)
   {
      if (ensure(SelectedObject))
      {
         FString AssetName = SelectedObject->GetName();
         if (AssetName.Contains(SearchPattern, SearchCase))
         {
            FString NewName = AssetName.Replace(*SearchPattern, *ReplacePattern, SearchCase);
            UEditorUtilityLibrary::RenameAsset(SelectedObject, NewName);
            ++Counter;
         }
      }
   }

   GiveFeedback(TEXT("Renamed"), Counter);
}

#pragma endregion

#pragma region CheckPowerofTwo

void UMyAssetActionUtility::CheckPowerOfTwo()
{
   //Get all selected assets
   TArray<UObject*> SelectedObjects = UEditorUtilityLibrary::GetSelectedAssets();
   uint32 Counter = 0;

   for (UObject* SelectedObject : SelectedObjects)
   {
      if (ensure(SelectedObject))
      {
         UTexture* Texture = dynamic_cast<UTexture*>(SelectedObject);
         if (ensure(Texture))
         {
            int32 Width = static_cast<int32>(Texture->GetSurfaceWidth());
            int32 Height = static_cast<int32>(Texture->GetSurfaceHeight());
            if (!IsPowerofTwo(Width) || (!IsPowerofTwo(Height)))
            {
               PrintToScreen(SelectedObject->GetPathName() + " is not a power of 2 texture", FColor::Red);
            }
            else
            {
               ++Counter;
            }
         }
         else
         {
            PrintToScreen(SelectedObject->GetPathName() + " is not a texture", FColor::Red);
         }
      }
   }

   GiveFeedback("Power of two ", Counter);
}

#pragma endregion

#pragma region Helper

bool UMyAssetActionUtility::IsPowerofTwo(int32 NumberToCheck)
{
   if (NumberToCheck == 0)
   {
      return false;
   }
   return(NumberToCheck & (NumberToCheck - 1)) == 0;
}

void UMyAssetActionUtility::PrintToScreen(FString Message, FColor Color)
{
   if (ensure(GEngine))
   {
      GEngine->AddOnScreenDebugMessage(-1, 2.5f, Color, Message);
   }
}

void UMyAssetActionUtility::GiveFeedback(FString Method, uint32 Counter)
{
   FString Message = FString("No matching files found");
   FColor Color = Counter > 0 ? FColor::Green : FColor::Red;
   if (Counter > 0)
   {
      Message = Method.AppendChar(' ');
      Message.AppendInt(Counter);
      Message.Append(Counter == 1 ? TEXT(" file") : TEXT(" files"));
   }
   PrintToScreen(Message, Color);
}

#pragma endregion
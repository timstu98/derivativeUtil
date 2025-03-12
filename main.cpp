#include <iostream>
#include <memory>
#include "src/AssetPriceManager.h"
#include "src/derivatives/Derivative.h"
#include "src/factorys/FutureFactory.h"
#include "src/factorys/CallOptionFactory.h"
#include "src/factorys/PutOptionFactory.h"

int main() {
  // Get the singleton instance (reference, not pointer)
  AssetPriceManager& assetPriceManager = AssetPriceManager::GetInstance();
  
  // Create factories
  FutureFactory futureFactory;
  CallOptionFactory callOptionFactory;
  PutOptionFactory putOptionFactory;

  // Create derivatives using factories
  std::shared_ptr<Derivative> oilFuture = futureFactory.CreateDerivative("OIL", 150.0);
  std::shared_ptr<Derivative> goldCallOption = callOptionFactory.CreateDerivative("GOLD", 2000.0);
  std::shared_ptr<Derivative> silverPutOption = putOptionFactory.CreateDerivative("SILVER", 25.0);
  
  // Note: Registration is now done in the factory
  
  // Set price for assets
  assetPriceManager.SetPrice("OIL", 155.0);
  assetPriceManager.SetPrice("GOLD", 2050.0);
  assetPriceManager.SetPrice("SILVER", 23.0);
  
  // Display current prices
  std::cout << "Oil Future Price: " << oilFuture->GetPrice() << std::endl;
  std::cout << "Gold Call Option Price: " << goldCallOption->GetPrice() << std::endl;
  std::cout << "Silver Put Option Price: " << silverPutOption->GetPrice() << std::endl;

  std::cout << "Program executed successfully." << std::endl;
  
  return 0;
}
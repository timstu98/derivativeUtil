#include "PutOptionFactory.h"
#include <memory>
#include "../derivatives/PutOption.h"

std::shared_ptr<Derivative> PutOptionFactory::CreateDerivative(const std::string& asset, double price) {
    // Default strike price and expiry date
    double strikePrice = price * 0.9; // 10% lower than current price
    std::string expiryDate = "2025-12-31";
    
    return CreateDerivative(asset, price, strikePrice, expiryDate);
}

std::shared_ptr<Derivative> PutOptionFactory::CreateDerivative(const std::string& asset, double price,
                                                             double strikePrice, const std::string& expiryDate) {
    auto putOption = std::make_shared<PutOption>(asset, price, strikePrice, expiryDate);
    
    // Register with the AssetPriceManager
    RegisterWithManager(putOption);
    
    return putOption;
}
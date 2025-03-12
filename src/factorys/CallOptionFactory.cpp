#include "CallOptionFactory.h"
#include <memory>
#include "../derivatives/CallOption.h"

std::shared_ptr<Derivative> CallOptionFactory::CreateDerivative(const std::string& asset, double price) {
    // Default strike price and expiry date
    double strikePrice = price * 1.1; // 10% higher than current price
    std::string expiryDate = "2025-12-31";
    
    return CreateDerivative(asset, price, strikePrice, expiryDate);
}

std::shared_ptr<Derivative> CallOptionFactory::CreateDerivative(const std::string& asset, double price,
                                                              double strikePrice, const std::string& expiryDate) {
    auto callOption = std::make_shared<CallOption>(asset, price, strikePrice, expiryDate);
    
    // Register with the AssetPriceManager
    RegisterWithManager(callOption);
    
    return callOption;
}
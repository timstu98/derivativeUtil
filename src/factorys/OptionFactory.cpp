#include "OptionFactory.h"
#include <memory>
#include "../derivatives/Option.h"

std::shared_ptr<Derivative> OptionFactory::CreateDerivative(const std::string& asset, double price) {
    // Default strike price and expiry date - these could be parameters
    double strikePrice = price * 1.1; // 10% higher than current price
    std::string expiryDate = "2025-12-31";
    
    return std::make_shared<Option>(asset, price, strikePrice, expiryDate);
}
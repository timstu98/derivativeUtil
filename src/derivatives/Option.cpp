#include "Option.h"
#include <algorithm>

Option::Option(const std::string& asset, double price, double strikePrice, const std::string& expiryDate)
    : Derivative(asset, price), strikePrice_(strikePrice), expiryDate_(expiryDate) {
}

double Option::GetStrikePrice() const {
    return strikePrice_;
}

const std::string& Option::GetExpiryDate() const {
    return expiryDate_;
}

double Option::Payoff() const {
    // Basic implementation for a call option
    // For a real implementation, you'd need option type (call/put) and more logic
    return std::max(0.0, GetPrice() - strikePrice_);
}
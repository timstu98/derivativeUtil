#include "CallOption.h"
#include <algorithm>

CallOption::CallOption(const std::string& asset, double price, double strikePrice, 
                       const std::string& expiryDate)
    : Option(asset, price, strikePrice, expiryDate, OptionType::CALL) {
}

double CallOption::Payoff() const {
    // Call option payoff: max(0, current price - strike price)
    return std::max(0.0, GetPrice() - GetStrikePrice());
}
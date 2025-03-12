#include "PutOption.h"
#include <algorithm>

PutOption::PutOption(const std::string& asset, double price, double strikePrice, 
                     const std::string& expiryDate)
    : Option(asset, price, strikePrice, expiryDate, OptionType::PUT) {
}

double PutOption::Payoff() const {
    // Put option payoff: max(0, strike price - current price)
    return std::max(0.0, GetStrikePrice() - GetPrice());
}
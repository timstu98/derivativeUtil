#include "Future.h"

Future::Future(const std::string& asset, double price, double contractSize, const std::string& deliveryDate)
    : Derivative(asset, price), contractSize_(contractSize), deliveryDate_(deliveryDate) {
}

double Future::GetContractSize() const {
    return contractSize_;
}

const std::string& Future::GetDeliveryDate() const {
    return deliveryDate_;
}
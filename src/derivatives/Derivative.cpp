#include "Derivative.h"
#include <iostream>
#include <string>
#include "../AssetPriceManager.h"

Derivative::Derivative(const std::string& asset, double price)
    : asset_(asset), price_(price) {
  // Constructor no longer auto-registers with AssetPriceManager
  // Use RegisterWithManager instead
}

double Derivative::GetPrice() const {
  return price_;
}

const std::string& Derivative::GetAsset() const {
  return asset_;
}

void Derivative::OnPriceUpdate(const std::string& asset, double price) {
  if (asset_ == asset) {
    price_ = price;
  }
}

void Derivative::RegisterWithManager(AssetPriceManager& manager) {
  // This is safe because of enable_shared_from_this
  manager.RegisterObserver(shared_from_this());
}
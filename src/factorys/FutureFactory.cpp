#include "FutureFactory.h"
#include <memory>
#include "../derivatives/Future.h"

std::shared_ptr<Derivative> FutureFactory::CreateDerivative(const std::string& asset, double price) {
    // Default contract size and delivery date
    double contractSize = 100.0;
    std::string deliveryDate = "2025-12-31";
    
    return CreateDerivative(asset, price, contractSize, deliveryDate);
}

std::shared_ptr<Derivative> FutureFactory::CreateDerivative(const std::string& asset, double price,
                                                          double contractSize, const std::string& deliveryDate) {
    auto future = std::make_shared<Future>(asset, price, contractSize, deliveryDate);
    
    // Register with the AssetPriceManager
    RegisterWithManager(future);
    
    return future;
}
#include "DerivativeFactory.h"
#include "../AssetPriceManager.h"

DerivativeFactory::DerivativeFactory() 
    : assetManager_(AssetPriceManager::GetInstance()) {
}

void DerivativeFactory::RegisterWithManager(std::shared_ptr<Derivative> derivative) {
    assetManager_.RegisterObserver(derivative);
}
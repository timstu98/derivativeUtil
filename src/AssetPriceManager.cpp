#include "AssetPriceManager.h"
#include <algorithm>
#include <map>
#include <memory>
#include <optional>
#include "IPriceObserver.h"

// Singleton implementation
AssetPriceManager::AssetPriceManager() = default;

AssetPriceManager& AssetPriceManager::GetInstance() {
  // Lazy initialization to create the instance only when first needed
  if (!instance_) {
    instance_ = std::unique_ptr<AssetPriceManager>(new AssetPriceManager());
  }
  return *instance_;
}

void AssetPriceManager::NotifyObservers(const std::string& asset, double price) {
  for (const auto& observer : observers_) {
    observer->OnPriceUpdate(asset, price);
  }
}

std::optional<double> AssetPriceManager::GetPrice(const std::string& asset) {
  auto it = prices_.find(asset);
  if (it != prices_.end()) {
    return it->second;
  }
  return std::nullopt;  // Indicates missing asset
}

void AssetPriceManager::SetPrice(const std::string& asset, double price) {
  prices_[asset] = price;
  // Notify observers about the price change
  NotifyObservers(asset, price);
}

void AssetPriceManager::RegisterObserver(std::shared_ptr<IPriceObserver> observer) {
  observers_.push_back(observer);
}

void AssetPriceManager::UnregisterObserver(std::shared_ptr<IPriceObserver> observer) {
  // Remove observer from the collection
  observers_.erase(
      std::remove_if(observers_.begin(), observers_.end(),
                    [&observer](const auto& obs) { return obs.get() == observer.get(); }),
      observers_.end());
}

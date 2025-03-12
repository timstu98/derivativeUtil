#ifndef F46C1ACC_B84C_4119_9BDF_2E6DED1A8A05
#define F46C1ACC_B84C_4119_9BDF_2E6DED1A8A05

#include <map>
#include <memory>
#include <mutex>
#include <optional>
#include <string>
#include <vector>

class IPriceObserver;  // Forward declaration for the observer interface

class AssetPriceManager {
  // Implemented as Singleton with proper memory management
 private:
  // Using smart pointer for instance to avoid memory leaks
  inline static std::unique_ptr<AssetPriceManager> instance_ = nullptr;
  // Mutex for thread safety
  inline static std::mutex instance_mutex_;
  
  std::map<std::string, double> prices_;
  std::vector<std::shared_ptr<IPriceObserver>> observers_;
  
  AssetPriceManager(); // Private constructor
  void NotifyObservers(const std::string& asset, double price);

 public:
  // Delete copy constructor and assignment operator
  AssetPriceManager(const AssetPriceManager&) = delete;
  AssetPriceManager& operator=(const AssetPriceManager&) = delete;
  
  // Singleton access method with lazy initialization
  static AssetPriceManager& GetInstance();
  
  std::optional<double> GetPrice(const std::string& asset);
  void SetPrice(const std::string& asset, double price);
  void RegisterObserver(std::shared_ptr<IPriceObserver> observer);
  void UnregisterObserver(std::shared_ptr<IPriceObserver> observer);
};

#endif /* F46C1ACC_B84C_4119_9BDF_2E6DED1A8A05 */

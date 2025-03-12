#ifndef B92009A1_C0E8_4A7E_A742_34E9F955E1D1
#define B92009A1_C0E8_4A7E_A742_34E9F955E1D1

#include <memory>
#include <string>
#include "../IPriceObserver.h"

class AssetPriceManager;

class Derivative : public IPriceObserver, public std::enable_shared_from_this<Derivative> {
 protected:
  std::string asset_;
  double price_;
  
  Derivative(const std::string& asset, double price);

 public:
  virtual ~Derivative() = default;

  void OnPriceUpdate(const std::string& asset, double price) override;
  void RegisterWithManager(AssetPriceManager& manager);
  
  double GetPrice() const;
  const std::string& GetAsset() const;
};
#endif /* B92009A1_C0E8_4A7E_A742_34E9F955E1D1 */

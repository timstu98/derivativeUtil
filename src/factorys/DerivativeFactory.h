#ifndef B8366E68_7B81_485C_AA78_0EDBCB813D86
#define B8366E68_7B81_485C_AA78_0EDBCB813D86

#include <memory>
#include <string>
#include "../derivatives/Derivative.h"
#include "../AssetPriceManager.h"

class DerivativeFactory {
 protected:
  AssetPriceManager& assetManager_;
  
 public:
  DerivativeFactory();
  virtual ~DerivativeFactory() = default;
  
  // Creates a derivative and registers it with the AssetPriceManager
  virtual std::shared_ptr<Derivative> CreateDerivative(const std::string& asset, double price) = 0;
  
 protected:
  // Helper method to register derivatives with the manager
  void RegisterWithManager(std::shared_ptr<Derivative> derivative);
};

#endif /* B8366E68_7B81_485C_AA78_0EDBCB813D86 */

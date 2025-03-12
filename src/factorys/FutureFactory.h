#ifndef B9EEEA37_5360_44DE_8DCC_6F9EFCC4656D
#define B9EEEA37_5360_44DE_8DCC_6F9EFCC4656D

#include "DerivativeFactory.h"
#include "../derivatives/Future.h"

class FutureFactory : public DerivativeFactory {
 public:
  // Basic factory method
  std::shared_ptr<Derivative> CreateDerivative(const std::string& asset, double price) override;
  
  // Enhanced factory method with additional parameters
  std::shared_ptr<Derivative> CreateDerivative(const std::string& asset, double price,
                                               double contractSize, const std::string& deliveryDate);
};

#endif /* B9EEEA37_5360_44DE_8DCC_6F9EFCC4656D */

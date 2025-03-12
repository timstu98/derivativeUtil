#ifndef E6C1898B_76CA_4556_A4C6_0D1A485C2A5F
#define E6C1898B_76CA_4556_A4C6_0D1A485C2A5F

#include "DerivativeFactory.h"
#include "../derivatives/PutOption.h"

class PutOptionFactory : public DerivativeFactory {
 public:
  // Basic factory method
  std::shared_ptr<Derivative> CreateDerivative(const std::string& asset, double price) override;
  
  // Enhanced factory method with additional parameters
  std::shared_ptr<Derivative> CreateDerivative(const std::string& asset, double price,
                                               double strikePrice, const std::string& expiryDate);
};

#endif /* E6C1898B_76CA_4556_A4C6_0D1A485C2A5F */
#ifndef D5C1898B_76CA_4556_A4C6_0D1A485C2A5F
#define D5C1898B_76CA_4556_A4C6_0D1A485C2A5F

#include "DerivativeFactory.h"
#include "../derivatives/CallOption.h"

class CallOptionFactory : public DerivativeFactory {
 public:
  // Basic factory method
  std::shared_ptr<Derivative> CreateDerivative(const std::string& asset, double price) override;
  
  // Enhanced factory method with additional parameters
  std::shared_ptr<Derivative> CreateDerivative(const std::string& asset, double price, 
                                               double strikePrice, const std::string& expiryDate);
};

#endif /* D5C1898B_76CA_4556_A4C6_0D1A485C2A5F */
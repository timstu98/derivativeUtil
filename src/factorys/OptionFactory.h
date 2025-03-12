#ifndef ABC1898B_76CA_4556_A4C6_0D1A485C2A5F
#define ABC1898B_76CA_4556_A4C6_0D1A485C2A5F

#include "DerivativeFactory.h"
#include "../derivatives/Option.h"
#include "../derivatives/CallOption.h"
#include "../derivatives/PutOption.h"

class OptionFactory : public DerivativeFactory {
 public:
  // Default option factory creates a call option
  std::shared_ptr<Derivative> CreateDerivative(const std::string& asset, double price) override;
  
  // Create specific option types
  std::shared_ptr<CallOption> CreateCallOption(const std::string& asset, double price, 
                                              double strikePrice, const std::string& expiryDate);
  
  std::shared_ptr<PutOption> CreatePutOption(const std::string& asset, double price, 
                                            double strikePrice, const std::string& expiryDate);
};

#endif /* ABC1898B_76CA_4556_A4C6_0D1A485C2A5F */

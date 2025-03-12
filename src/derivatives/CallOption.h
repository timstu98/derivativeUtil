#ifndef C37F5072_7F9C_45C4_BC49_ECDCB01757AE
#define C37F5072_7F9C_45C4_BC49_ECDCB01757AE

#include "Option.h"

class CallOption : public Option {
 public:
  CallOption(const std::string& asset, double price, double strikePrice, 
             const std::string& expiryDate);
  
  double Payoff() const override;
};

#endif /* C37F5072_7F9C_45C4_BC49_ECDCB01757AE */
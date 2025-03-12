#ifndef EE543A2D_D762_4BD8_BC10_5BC37ECB4577
#define EE543A2D_D762_4BD8_BC10_5BC37ECB4577

#include "Option.h"

class PutOption : public Option {
 public:
  PutOption(const std::string& asset, double price, double strikePrice, 
            const std::string& expiryDate);
  
  double Payoff() const override;
};

#endif /* EE543A2D_D762_4BD8_BC10_5BC37ECB4577 */

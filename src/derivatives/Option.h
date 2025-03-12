#ifndef A37F5072_7F9C_45C4_BC49_ECDCB01757AE
#define A37F5072_7F9C_45C4_BC49_ECDCB01757AE

#include "Derivative.h"

enum class OptionType {
  CALL,
  PUT
};

class Option : public Derivative {
 private:
  double strikePrice_;
  std::string expiryDate_;
  OptionType type_;

 public:
  Option(const std::string& asset, double price, double strikePrice, 
         const std::string& expiryDate, OptionType type = OptionType::CALL);
  
  double GetStrikePrice() const;
  const std::string& GetExpiryDate() const;
  OptionType GetOptionType() const;
  
  virtual double Payoff() const;
};

#endif /* A37F5072_7F9C_45C4_BC49_ECDCB01757AE */

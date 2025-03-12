#ifndef E962145E_E3EA_4C17_828C_78A1ACFBA488
#define E962145E_E3EA_4C17_828C_78A1ACFBA488
#include "Derivative.h"

class Future : public Derivative {
 private:
  double contractSize_;
  std::string deliveryDate_;

 public:
  Future(const std::string& asset, double price, double contractSize, const std::string& deliveryDate);
  
  double GetContractSize() const;
  const std::string& GetDeliveryDate() const;
};

#endif /* E962145E_E3EA_4C17_828C_78A1ACFBA488 */

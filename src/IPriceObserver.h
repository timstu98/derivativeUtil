#ifndef A934DD3C_C9AC_4752_9280_8DA9BD5DD422
#define A934DD3C_C9AC_4752_9280_8DA9BD5DD422
#include <string>

class IPriceObserver {
 public:
  virtual ~IPriceObserver() = default;
  virtual void OnPriceUpdate(const std::string& asset, double price) = 0;
};

#endif /* A934DD3C_C9AC_4752_9280_8DA9BD5DD422 */

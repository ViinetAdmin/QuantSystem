/*
 * \copyright Copyright 2015 All Rights Reserved.
 * \license @{
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * @}
 */

#include <string>
using std::to_string;
#include "quantsystem/indicators/exponential_indicator.h"
namespace quantsystem {
namespace indicators {
ExponentialMovingAverage::ExponentialMovingAverage(
    const string& name, int period)
    : Indicator(name),
      period_(period),
      k_(2.0 / (period + 1)) {
}

ExponentialMovingAverage::ExponentialMovingAverage(
    const string& name, int period,
    double smoothing_factor)
    : Indicator(name),
      period_(period),
      k_(smoothing_factor) {
}

ExponentialMovingAverage::ExponentialMovingAverage(int period)
    : Indicator("EMA" + to_string(period)),
      period_(period),
      k_(2.0 / (period + 1)) {
}

ExponentialMovingAverage::ExponentialMovingAverage(
    int period, double smoothing_factor)
    : Indicator("EMA" + to_string(period)),
      period_(period),
      k_(smoothing_factor) {
}

double ExponentialMovingAverage::ComputeNextValue(
    const IndicatorDataPoint& input) {
  if (samples() == 1) {
    return input.value();
  }
  return input.value() * k_ + current().value() * (1 - k_);
}
}  // namespace indicators
}  // namespace quantsystem

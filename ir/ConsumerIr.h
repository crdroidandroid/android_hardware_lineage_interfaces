/*
 * SPDX-FileCopyrightText: 2024 The LineageOS Project
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include <aidl/android/hardware/ir/BnConsumerIr.h>

namespace aidl {
namespace android {
namespace hardware {
namespace ir {

class ConsumerIr : public BnConsumerIr {
  public:
    ConsumerIr();
    ::ndk::ScopedAStatus getCarrierFreqs(
            ::std::vector<::aidl::android::hardware::ir::ConsumerIrFreqRange>* _aidl_return)
            override;
    ::ndk::ScopedAStatus transmit(int32_t carrierFreqHz,
                                  const ::std::vector<int32_t>& pattern) override;

  private:
    std::vector<ConsumerIrFreqRange> kRangeVec;
    bool isInRange(int32_t carrierFreqHz);
};

}  // namespace ir
}  // namespace hardware
}  // namespace android
}  // namespace aidl

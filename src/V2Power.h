// © Kay Sievers <kay@vrfy.org>, 2020-2021
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include <Arduino.h>

class V2Power {
public:
  enum Mode { Idle };

  static void setSleepMode(V2Power::Mode mode) {
    switch (mode) {
      case Mode::Idle:
        // Sleep mode IDLE, calling __WFI() stops the CPU, peripherals are still running.
        PM->SLEEPCFG.bit.SLEEPMODE = 0x02;
        while (PM->SLEEPCFG.bit.SLEEPMODE != 0x02)
          ;
        break;
    }
  }

  static void sleep() {
    __WFI();
  }
};

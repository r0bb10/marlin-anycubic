/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

/**
 * Arduino Mega with RAMPS v1.4 for Anycubic
 */

#define BOARD_INFO_NAME "Anycubic RAMPS 1.4"

//
// Heaters
//
#define TG_HEATER_BED_PIN                    8
#define TG_HEATER_0_PIN                     10
#define TG_HEATER_1_PIN                     45

//
// Temp Sensors
//
#define TEMP_0_PIN                          13
#define TEMP_1_PIN                          15
#define TEMP_2_PIN                          12
#define TEMP_BED_PIN                        14

//
// Fans
//
#define TG_FAN0_PIN                          9
#define TG_FAN1_PIN                          7
#define TG_FAN2_PIN                         44
#define RAMPS_D8_PIN         TG_HEATER_BED_PIN
#define RAMPS_D9_PIN               TG_FAN0_PIN
#define CONTROLLER_FAN_PIN         TG_FAN1_PIN
#define RAMPS_D10_PIN          TG_HEATER_0_PIN
#ifndef E0_AUTO_FAN_PIN
  #define E0_AUTO_FAN_PIN          TG_FAN2_PIN
#endif

//
// Steppers
//
#define X_STEP_PIN                          54
#define X_DIR_PIN                           55
#define X_ENABLE_PIN                        38
#define Y_STEP_PIN                          60
#define Y_DIR_PIN                           61
#define Y_ENABLE_PIN                        56
#define Y2_STEP_PIN                         36
#define Y2_DIR_PIN                          34
#define Y2_ENABLE_PIN                       30
#define Z_STEP_PIN                          46
#define Z_DIR_PIN                           48
#define Z_ENABLE_PIN                        62
#define Z2_STEP_PIN                         36
#define Z2_DIR_PIN                          34
#define Z2_ENABLE_PIN                       30
#define E0_STEP_PIN                         26
#define E0_DIR_PIN                          28
#define E0_ENABLE_PIN                       24

//
// Limit Switches
//
#define X_MIN_PIN                            3
#define Y_MIN_PIN                           42
#define Z_MIN_PIN                           18
#define Z2_MIN_PIN                          -1
#ifndef Z_MIN_PROBE_PIN
  #define Z_MIN_PROBE_PIN                    2
#endif
#define X_MAX_PIN                           -1
#define Y_MAX_PIN                           -1
#define Z_MAX_PIN                           -1
#ifndef FIL_RUNOUT_PIN
  #define FIL_RUNOUT_PIN                    19
#endif

//
// Servos
//
#if MB(TRIGORILLA_14)
  #define SERVO0_PIN                         6
  #define SERVO1_PIN                        -1
  #define SERVO2_PIN                        -1
  #define SERVO3_PIN                        -1
#endif

//
// Other PINs
//
//#define BEEPER_PIN                          31
#define SD_DETECT_PIN                       49


#include "pins_RAMPS.h"

//
// AnyCubic made the following changes to 1.1.0-RC8
// If these are appropriate for your LCD let us know.
//
#if 0 && HAS_WIRED_LCD

  // LCD Display output pins
  #if BOTH(NEWPANEL, PANEL_ONE)
    #undef LCD_PINS_D6
    #define LCD_PINS_D6                       57
  #endif

  // LCD Display input pins
  #if ENABLED(NEWPANEL)
    #if ANY(VIKI2, miniVIKI)
      #undef DOGLCD_A0
      #define DOGLCD_A0                       23
    #elif ENABLED(ELB_FULL_GRAPHIC_CONTROLLER)
      #undef BEEPER_PIN
      #define BEEPER_PIN                      33
      #undef LCD_BACKLIGHT_PIN
      #define LCD_BACKLIGHT_PIN               67
    #endif
  #elif ENABLED(MINIPANEL)
    #undef BEEPER_PIN
    #define BEEPER_PIN                        33
    #undef DOGLCD_A0
    #define DOGLCD_A0                         42
  #endif

#endif // HAS_WIRED_LCD

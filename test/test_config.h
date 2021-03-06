/* Copyright (c) 2013 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/* Per-test config flags */

#ifndef __TEST_TEST_CONFIG_H
#define __TEST_TEST_CONFIG_H

/* Test config flags only apply for test builds */
#ifdef TEST_BUILD

/* Don't compile vboot hash support unless specifically testing for it */
#undef CONFIG_VBOOT_HASH
/* Don't compile PD logging unless specifically testing for it */
#undef CONFIG_USB_PD_LOGGING

#ifdef TEST_BKLIGHT_LID
#define CONFIG_BACKLIGHT_LID
#endif

#ifdef TEST_BKLIGHT_PASSTHRU
#define CONFIG_BACKLIGHT_LID
#define CONFIG_BACKLIGHT_REQ_GPIO GPIO_PCH_BKLTEN
#endif

#ifdef TEST_KB_8042
#define CONFIG_KEYBOARD_PROTOCOL_8042
#endif

#ifdef TEST_KB_MKBP
#define CONFIG_KEYBOARD_PROTOCOL_MKBP
#endif

#ifdef TEST_KB_SCAN
#define CONFIG_KEYBOARD_PROTOCOL_MKBP
#endif

#ifdef TEST_MATH_UTIL
#define CONFIG_MATH_UTIL
#endif

#ifdef TEST_MOTION_LID
#define CONFIG_ACCEL_STD_REF_FRAME_OLD
#define CONFIG_LID_ANGLE
#define CONFIG_LID_ANGLE_SENSOR_BASE 0
#define CONFIG_LID_ANGLE_SENSOR_LID 1
#endif

#ifdef TEST_SBS_CHARGING
#define CONFIG_BATTERY_MOCK
#define CONFIG_BATTERY_SMART
#define CONFIG_CHARGER
#define CONFIG_CHARGER_V1
#define CONFIG_CHARGER_INPUT_CURRENT 4032
#define CONFIG_CHARGER_DISCHARGE_ON_AC
#define CONFIG_CHARGER_DISCHARGE_ON_AC_CUSTOM
#define CONFIG_I2C
int board_discharge_on_ac(int enabled);
#define I2C_PORT_MASTER 0
#define I2C_PORT_BATTERY 0
#define I2C_PORT_CHARGER 0
#endif

#ifdef TEST_SBS_CHARGING_V2
#define CONFIG_BATTERY_MOCK
#define CONFIG_BATTERY_SMART
#define CONFIG_CHARGER
#define CONFIG_CHARGER_V2
#define CONFIG_CHARGER_PROFILE_OVERRIDE
#define CONFIG_CHARGER_INPUT_CURRENT 4032
#define CONFIG_CHARGER_DISCHARGE_ON_AC
#define CONFIG_CHARGER_DISCHARGE_ON_AC_CUSTOM
#define CONFIG_I2C
int board_discharge_on_ac(int enabled);
#define I2C_PORT_MASTER 0
#define I2C_PORT_BATTERY 0
#define I2C_PORT_CHARGER 0
#endif

#ifdef TEST_THERMAL
#define CONFIG_CHIPSET_CAN_THROTTLE
#define CONFIG_FANS 1
#define CONFIG_I2C
#define CONFIG_TEMP_SENSOR
#define CONFIG_THERMISTOR_NCP15WB
#define I2C_PORT_THERMAL 0
int ncp15wb_calculate_temp(uint16_t adc);
#endif

#ifdef TEST_FAN
#define CONFIG_FANS 1
#endif

#ifdef TEST_BUTTON
#define CONFIG_BUTTON_COUNT 2
#define CONFIG_KEYBOARD_PROTOCOL_8042
#endif

#ifdef TEST_BATTERY_GET_PARAMS_SMART
#define CONFIG_BATTERY_MOCK
#define CONFIG_BATTERY_SMART
#define CONFIG_CHARGER_INPUT_CURRENT 4032
#define CONFIG_I2C
#define I2C_PORT_MASTER 0
#define I2C_PORT_BATTERY 0
#define I2C_PORT_CHARGER 0
#endif

#ifdef TEST_LIGHTBAR
#define CONFIG_I2C
#define I2C_PORT_LIGHTBAR 0
#define CONFIG_ALS_LIGHTBAR_DIMMING 0
#endif

#ifdef TEST_USB_PD
#define CONFIG_USB_POWER_DELIVERY
#define CONFIG_USB_PD_CUSTOM_VDM
#define CONFIG_USB_PD_DUAL_ROLE
#define CONFIG_USB_PD_PORT_COUNT 2
#define CONFIG_USB_PD_TCPC
#define CONFIG_USB_PD_TCPM_STUB
#define CONFIG_SHA256
#define CONFIG_SW_CRC
#endif

#ifdef TEST_CHARGE_MANAGER
#define CONFIG_CHARGE_MANAGER
#undef CONFIG_CHARGE_MANAGER_DRP_CHARGING
#define CONFIG_USB_PD_DUAL_ROLE
#define CONFIG_USB_PD_PORT_COUNT 2
#endif

#ifdef TEST_CHARGE_MANAGER_DRP_CHARGING
#define CONFIG_CHARGE_MANAGER
#define CONFIG_CHARGE_MANAGER_DRP_CHARGING
#define CONFIG_USB_PD_DUAL_ROLE
#define CONFIG_USB_PD_PORT_COUNT 2
#endif

#ifdef TEST_CHARGE_RAMP
#define CONFIG_CHARGE_RAMP
#define CONFIG_USB_PD_PORT_COUNT 2
#endif

#endif  /* TEST_BUILD */
#endif  /* __TEST_TEST_CONFIG_H */

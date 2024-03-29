#ifndef XY6020_H
#define XY6020_H
#include "settings.h"
#include <ModbusRTU.h>
#include <SoftwareSerial.h>

#define MAX_REGISTER_COUNT 19

class Xy6020 {
protected:
  enum Register {
    TargetVoltage = 0,
    MaxCurrent,
    ActualVoltage,
    ActualCurrent,
    ActualPower,
    InputVoltage,
    OutputCharge,
    OutputChargeHigh,
    OutputEnergy,
    OutputEnergyHigh,
    OnTimeHours,
    OnTimeMinutes,
    OnTimeSeconds,
    Temperature = 13,
    OutputState = 18
  };

  uint8_t mSlaveAddr;
  SoftwareSerial mSoftSerial;
  ModbusRTU mModBus;
  uint16_t mRegisters[MAX_REGISTER_COUNT];
  bool mConnectionStatus;
  SettingsData &mCfg;
  unsigned long mTs;

  bool readHregCb(Modbus::ResultCode event, uint16_t transactionId, void *data);
  bool writeCb(Modbus::ResultCode event, uint16_t transactionId, void *data);

  void waitForTransactionDone();
  void setRegister(Register reg, uint16_t value);

public:
  Xy6020(SettingsData &cfg, int8_t rx_pin, int8_t tx_pin,
         uint8_t slave_address = 1);
  void task();

  bool isConnected() { return mConnectionStatus; }

  bool setTargetVoltage(float voltage);
  bool setMaxCurrent(float current);

  float inputVoltage() { return mRegisters[InputVoltage] / 100.0; }

  float actualVoltage() { return mRegisters[ActualVoltage] / 100.0; }
  float actualCurrent() { return mRegisters[ActualCurrent] / 100.0; }
  float actualPower() { return mRegisters[ActualPower] / 10.0; }

  float targetVoltage() { return mRegisters[TargetVoltage] / 100.0; }
  float targetCurrent() { return mRegisters[MaxCurrent] / 100.0; }
  bool setMaxPower(float power);
  float maxPower() { return mCfg.max_power; }

  void setOutputEnabled(bool state);
  bool outputEnabled() { return mRegisters[OutputState]; }
};

#endif // XY6020_H
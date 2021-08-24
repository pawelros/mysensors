/**
 * @file Automation.hpp
 * @author Grzegorz Krajewski
 *
 * Automation for buttons & sensors.
 *
 * @license GPL V2
 */

#pragma once

#include "../Mapping/Mapping.hpp"

void setOutput(const uint8_t& sensorId, const uint8_t& cmd = Relay::FLIP) {
  // test whether sensor with given ID exists and get it's index in container
  // TODO: Add debug message when idx is wrong & in any other places where: Sensors[idx]
  uint8_t idx = getIdx(sensorId);
  auto sensor = Sensors[idx];

  // check whether flip state of sensor
  const uint8_t state = (cmd == Relay::FLIP) ? !loadState(sensor.id) : cmd;
  saveState(sensor.id, state);

  // inverse state if sensors is Active Low
  bool bState = static_cast<bool>(state);
  bState = (ActiveLow == sensor.activelow) ? !bState : bState;

  digitalWrite(sensor.pin, bState);
  send(msgs[idx].set(state));
}

void clickCallback(void* pSensorId) {
  // TODO: Test whether this can be null or nullptr or unexpected value
  const uint8_t sensorId = static_cast<uint8_t>(reinterpret_cast<intptr_t>(pSensorId));
  setOutput(sensorId);
}

void kuchniaClick() {
  setOutput(KUCHNIA_OSWIETLENIE_TUBY);
  setOutput(KUCHNIA_OSWIETLENIE_WYSPA);
}

void kuchniaOff() {
  setOutput(KUCHNIA_OSWIETLENIE_WYSPA, Relay::OFF);
  setOutput(KUCHNIA_OSWIETLENIE_TUBY, Relay::OFF);
}

void jadalniaClick() {
  setOutput(JADALNIA_OSWIETLENIE);
}

void salonClick() {
  setOutput(SALON_ZYRANDOL);
}

void biuroClick() {
  setOutput(BIURO_OSWIETLENIE_L1);
}

void biuroOff() {
  setOutput(BIURO_OSWIETLENIE_L1, Relay::OFF);
  setOutput(BIURO_OSWIETLENIE_L2, Relay::OFF);
}

void przedpokojClick() {
  setOutput(PRZEDPOKOJ_OSWIETLENIE);
}

void balkonClick() {
  setOutput(BALKON_OSWIETLENIE);
}

void poddaszeClick() {
  setOutput(PODDASZE_OSWIETLENIE);
}

void sypialniaClick() {
  setOutput(SYPIALNIA_OSWIETLENIE);
}

void stasiuClick() {
  setOutput(STASIU_OSWIETLENIE_L1);
}

void stasiuOff() {
  setOutput(STASIU_OSWIETLENIE_L1, Relay::OFF);
  setOutput(STASIU_OSWIETLENIE_L2, Relay::OFF);
}

void setupButtons() {
  // Setup the button.
  kuchnia.attachClick(kuchniaClick);
  kuchnia.attachLongPressStop(kuchniaOff);
  kuchnia.attachDoubleClick(clickCallback, KUCHNIA_OSWIETLENIE_TUBY);

  jadalnia.attachClick(jadalniaClick);

  salon1.attachClick(salonClick);
  salon2.attachClick(clickCallback, JADALNIA_OSWIETLENIE);
  salon3.attachClick(clickCallback, PRZEDPOKOJ_OSWIETLENIE);

  biuro.attachClick(biuroClick);
  biuro.attachLongPressStop(biuroOff);
  biuro.attachDoubleClick(clickCallback, BIURO_OSWIETLENIE_L2);

  przedpokoj1.attachClick(przedpokojClick);
  przedpokoj2.attachClick(przedpokojClick);

  balkon.attachClick(balkonClick);

  poddasze.attachClick(poddaszeClick);

  sypialnia.attachClick(sypialniaClick);

  stasiu.attachClick(stasiuClick);
  stasiu.attachLongPressStop(stasiuOff);
  stasiu.attachDoubleClick(clickCallback, STASIU_OSWIETLENIE_L2);
  }

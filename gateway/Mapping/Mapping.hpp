/**
 * @file Mapping.hpp
 * @author Grzegorz Krajewski
 *
 * Mappings.
 *
 * @license GPL V2
 */

#pragma once

#include <OneButton.h>

namespace Relay {
  const uint8_t OFF  = 0;
  const uint8_t ON   = 1;
  const uint8_t FLIP = 2;
}
const bool ActiveLow = true;

// Child ID declaration of relays
const uint8_t KUCHNIA_OSWIETLENIE_TUBY        = 1;
const uint8_t KUCHNIA_OSWIETLENIE_WYSPA       = 2;
const uint8_t JADALNIA_OSWIETLENIE            = 3;
const uint8_t SALON_ZYRANDOL                  = 4;
const uint8_t BIURO_OSWIETLENIE_L1            = 5;
const uint8_t BIURO_OSWIETLENIE_L2            = 6;
const uint8_t PRZEDPOKOJ_OSWIETLENIE          = 7;
const uint8_t BALKON_OSWIETLENIE              = 8;
const uint8_t PODDASZE_OSWIETLENIE            = 9;
const uint8_t SYPIALNIA_OSWIETLENIE           = 10;
const uint8_t STASIU_OSWIETLENIE_L1           = 11;
const uint8_t STASIU_OSWIETLENIE_L2           = 12;
typedef struct {
  const uint8_t id;
  const char* description;
  const uint8_t pin;
  bool activelow;
} SensorsStruct;

SensorsStruct Sensors [] = {
//  Child ID                     description                       pin activelow
  { KUCHNIA_OSWIETLENIE_TUBY,    "Kuchnia oswietlenie tuby",       1, false },
  { KUCHNIA_OSWIETLENIE_WYSPA,   "Kuchnia oswietlenie wyspa",      2, false },
  { JADALNIA_OSWIETLENIE,        "Jadalnia oswietlenie",           3, false },
  { SALON_ZYRANDOL,              "Salon zyrandol poziom 1",        4, false },
  { BIURO_OSWIETLENIE_L1,        "Biuro oswietlenie poziom 1",     5, false },
  { BIURO_OSWIETLENIE_L2,        "Biuro oswietlenie poziom 2",     6, false },
  { PRZEDPOKOJ_OSWIETLENIE,      "Przedpokoj oswietlenie",         7, false },
  { BALKON_OSWIETLENIE,          "Balkon oswietlenie",             8, false },
  { PODDASZE_OSWIETLENIE,        "Poddasze oswietlenie",           9, false },
  { SYPIALNIA_OSWIETLENIE,       "Sypialnia oswietlenie",          10, false },
  { STASIU_OSWIETLENIE_L1,       "Stasiu oswietlenie poziom 1",    11, false },
  { STASIU_OSWIETLENIE_L2,       "Stasiu oswietlenie poziom 2",    12, false }

};
const uint8_t maxSensors = sizeof(Sensors) / sizeof(SensorsStruct);
MyMessage msgs[maxSensors];

uint8_t getIdx(uint8_t sensorId) {
  for (uint8_t i = 0; i < maxSensors; i++) {
    if (Sensors[i].id == sensorId) return(i);
  }
  return(-1);
}

// Pushbuttons declaration
// Remember that names should be consistent with main loop in gateway.ino
OneButton kuchnia(A1, true);
OneButton jadalnia(A2, true);
OneButton salon1(A3, true);
OneButton salon2(A4, true);
OneButton salon3(A5, true);
OneButton biuro(A6, true);
OneButton przedpokoj1(A7, true);
OneButton przedpokoj2(A8, true);
OneButton balkon(A9, true);
OneButton poddasze(A10, true);
OneButton sypialnia(A11, true);
OneButton stasiu(A12, true);

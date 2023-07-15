#ifndef logger_H
#define logger_H

#include "Arduino.h"
#include <SPI.h>
#include <SD.h>
#include <EEPROM.h>
#include "uart_comm_ovidius.h"
#include <C:\Users\Nikos\Documents\Arduino\libraries\uart_comm_ovidius\utility\sync_codes.h>
#include <C:\Users\Nikos\Documents\Arduino\libraries\uart_comm_ovidius\utility\packets.h>
#include <C:\Users\Nikos\Documents\Arduino\libraries\uart_comm_ovidius\utility\ports.h>
#include <utility/ee_address.h>
#include <C:\Users\Nikos\Documents\Arduino\libraries\ActiveStepperActuator\config\eeprom_stepper.h>

namespace logger_ns {
    
class Logger: public uart_comm_ns::uart_comm_ovidius
{
private:
    EEPROMClass access2eeprom;

    uint8_t _req_received;
    float _in_buffer_float;
    float _out_buffer_float; // assigned float value to be sent back to the system that asked

    void _read_var_eeprom(int var_address);
    void _write_var_eeprom(int var_address);

public:
    Logger(/* args */);
    ~Logger();

    void execute_request(Stream &uart_bus);
};

}

#endif //logger_H

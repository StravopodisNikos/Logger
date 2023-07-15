#include <Logger.h>

using namespace logger_ns;

Logger::Logger(/* args */)
{
}

Logger::~Logger()
{
}

void Logger::execute_request(Stream &uart_bus) {
    // These if-cases will expand as long as the project expands
    _req_received = uart_bus.read();
    if (_req_received == CMD_SINGLE_READ_ABSQRAD)
    {
        _read_var_eeprom(EEPROM_ADDR_CP);
        sendBack4bytes_num<float>(_out_buffer_float, uart_bus);
    } else if (_req_received == CMD_SINGLE_WRITE_ABSQRAD)
    {
        getBack4bytes_num<float&>(_in_buffer_float, uart_bus);
        _write_var_eeprom(EEPROM_ADDR_CP);
    }  
}

void Logger::_read_var_eeprom(int var_address) {
    access2eeprom.get(var_address, _out_buffer_float);
}

void Logger::_write_var_eeprom(int var_address) {
    access2eeprom.put(var_address, _in_buffer_float);
}

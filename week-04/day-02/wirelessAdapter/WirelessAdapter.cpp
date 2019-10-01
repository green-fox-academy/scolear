
#include <iostream>
#include "WirelessAdapter.h"

WirelessAdapter::WirelessAdapter(int id, int type, int bw) : Device(id), USBDevice(id, type), NetworkDevice(id, bw) {}

void WirelessAdapter::info() {
    std::cout << getID() << _USBType << _bandwidth << std::endl;
}

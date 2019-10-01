
#ifndef WIRELESSADAPTER_WIRELESSADAPTER_H
#define WIRELESSADAPTER_WIRELESSADAPTER_H


#include "USBDevice.h"
#include "NetworkDevice.h"

class WirelessAdapter : public USBDevice, public NetworkDevice {
public:
    WirelessAdapter(int id, int type, int bw);
    void info();
};


#endif //WIRELESSADAPTER_WIRELESSADAPTER_H


#ifndef WIRELESSADAPTER_USBDEVICE_H
#define WIRELESSADAPTER_USBDEVICE_H


#include "Device.h"

class USBDevice : public virtual Device {
public:
    USBDevice(int, int);
protected:
    int _USBType;
};


#endif //WIRELESSADAPTER_USBDEVICE_H

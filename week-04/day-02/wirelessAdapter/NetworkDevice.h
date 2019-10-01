
#ifndef WIRELESSADAPTER_NETWORKDEVICE_H
#define WIRELESSADAPTER_NETWORKDEVICE_H


#include "Device.h"

class NetworkDevice : public virtual Device {
public:
    NetworkDevice(int, int);
protected:
    int _bandwidth;
};


#endif //WIRELESSADAPTER_NETWORKDEVICE_H

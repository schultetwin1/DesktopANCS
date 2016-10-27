# DesktopANCS
By Matt Schulte
schultetwin1@gmail.com

_WARNING_: This is still very much in alpha phase. Don't expect anything to
work properly the first time. Open up any issues you have on github.

## Intro
DesktopANCS is a way to get text and call notifications from your iPhone to
your linux box without any app on the phone.  It uses the ANCS Bluetooth Low
Energy service on your iPhone and libnotify on your linux machine. 

## Requirements
1. Linux machine with ble host
2. Qt 5.7
3. My modifications to the QtConnectivity library
   [found here](https://github.com/schultetwin1/qtconnectivity/)
   in the roleswitch branch. You will need to compile and install this library

## Usage
After cloning and compiling DesktopANCS please allow the binary to change the
advertising status of your bluetooth adapter using

```bash
sudo setcap cap_net_raw+eip DesktopANCS
```

Then run
```bash
./DesktopANCS
```

On your iPhone go to Settings -> Bluetooth. DesktopANCS should tell you in its
output what your computer's name is. When the name appears click to pair with
it. Once its connected any call or text notifications should appear on your
computer.

Things to do:
* Let the user configure which apps they want to come through
* Deal with modified / read notifications
* Show missed calls vs current calls
* Enable actions
* The list goes on and on...

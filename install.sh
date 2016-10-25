#!/bin/bash

systemctl --user stop DesktopANCS
sudo cp DesktopANCS /usr/bin
sudo setcap cap_net_raw+eip /usr/bin/DesktopANCS
cp DesktopANCS.service ~/.config/systemd/user/
systemctl --user daemon-reload
systemctl --user enable DesktopANCS
systemctl --user start DesktopANCS

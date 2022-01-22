#!/bin/bash
sudo mkdir -p /opt/
cd /opt/
sudo git clone https://github.com/thecountrox/dotfiles.git
cd /opt/dotfiles/
sudo mv * /opt/
sudo rm -r /opt/dotfiles
cd /opt/dwm/
sudo make clean install
cd /opt/dwmblocks
sudo make clean install
cd /opt/dmenu 
sudo make clean install
cd /opt/st
sudo make clean install
echo "Please look at the github for the required Dependencies that need to be installed for the functioning of certian things in the configs"

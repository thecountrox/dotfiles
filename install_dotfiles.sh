#!/bin/bash
install ="sudo make clean install"
sudo mkdir -p /opt/
cd /opt/
sudo git clone https://github.com/thecountrox/dotfiles.git
cd /opt/dotfiles/
sudo mv * /opt/
sudo rm -r /opt/dotfiles
cd /opt/dwm/
$install
cd /opt/dwmblocks
$install
cd /opt/dmenu 
$install
cd /opt/st
$install
echo "Please look at the github for the required Dependencies that need to be installed for the functioning of certian things in the configs"

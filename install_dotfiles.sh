#!/bin/bash
install="sudo make clean install"
sudo mkdir -p /opt/
cd /opt/
sudo git clone https://github.com/thecountrox/dotfiles.git
cd /opt/dotfiles/
# picom and dunst config install and cleanup
mkdir -p ~/.config/picom/
sudo mv /opt/dotfiles/.config/picom/picom.conf ~/.config/picom/picom.conf
sudo mv /opt/dotfiles/.config/dunst ~/.config/dunst 
sudo rm -r /opt/dofiles/.config/
# install dwm dwmblocks dmenu st
cd /opt/dotfiles/dwm/
$install
cd /opt/dotfiles/dwmblocks
$install
cd /opt/dotfiles/dmenu 
$install
cd /opt/dotfiles/st
$install
cd /opt/dotfiles/scripts
chmod +x *
sudo mv * /usr/bin/
cd /opt/dotfiles
sudo mv * /opt/
echo "Please look at the github for the required Dependencies that need to be installed for the functioning of certian things in the configs"

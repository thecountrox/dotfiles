#!/bin/bash
read -p "Enter your AUR Helper : (eg : yay paru etc.) (no pamac , fuck pamac)" aur
sudo pacman -R libxft
$aur -S libxft-bgra ttf-joypixels ttf-iosevka-nerd nitrogen maim flameshot dunst pamixer

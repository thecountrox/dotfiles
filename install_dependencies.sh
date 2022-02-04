#!/bin/bash
read -p "Enter your AUR Helper : (eg : yay paru etc.) (no pamac , fuck pamac)" aur
sudo pacman -Rdd libxft
$aur -S libxft-bgra-git ttf-joypixels ttf-iosevka-nerd nitrogen maim flameshot dunst pamixer

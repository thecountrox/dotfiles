sudo pacman -Rdd libxft
sudo pacman -Syu git sudo base-devel flameshot dunst nitrogen xclip ttf-joypixels ttf-iosevka-nerd maim pamixer
cd /tmp
mkdir dotfile
cd dotfile
git clone aur.archlinux.org/libxft-bgra-git.git
cd libxft-bgra-git
makepkg -si
cd ..
git clone aur.archlinux.org/picom-jonaburg-fix.git
cd picom-jonaburg-fix
makepkg -si
cd ../..
sudo rm -rf /tmp/dotfile

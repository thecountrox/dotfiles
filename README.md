# dotfiles
My dotfiles for anyone to use


This dotfiles contains my dwm , dwmblock , dmenu and st configs.

My dwm config is heavily based on the dracula color scheme which I adore 

all of the dwm related things are patched on TOP of distrotube's dwm build
so features from his build will be seen here

link to his dwm build : https://gitlab.com/dwt1/dwm-distrotube

![my dwm build showcase](https://cdn.discordapp.com/attachments/809664984187404288/932270436480348250/unknown.png)

# Dependencies

1) libxft-bgra (from aur)
2) ttf-joypixels (from arch community repo)
3) picom-jonaburg-fix (or picom-jonaburg-git both are from the aur)

# Installation
If u wanna use em the lazy way ,
1) copy em to /opt/ 
2) then cd into each one of em and run "sudo make clean install".
3) Swag

This is now done by the install_dotfiles.sh script in this repo (requires git installed)
The script will not install the Dependencies for you (for now...)

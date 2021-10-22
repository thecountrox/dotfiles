#! /bin/bash 
nitrogen --restore &
dwmblocks &
xfsettingsd &
start-pulseaudio-x11 &
sudo rmmod pcspkr &
/usr/lib/xfce4/notifyd/xfce4-notifyd &
/usr/bin/pipewire &
/usr/bin/pipewire-pulse &
/usr/bin/pipewire-media-session &
export XDG_SESSION_TYPE=x11 &

#!/bin/bash

# source directory
SOURCE="${BASH_SOURCE[0]}"
while [ -h "$SOURCE" ]; do # resolve $SOURCE until the file is no longer a symlink
  SRC_DIR="$( cd -P "$( dirname "$SOURCE" )" >/dev/null 2>&1 && pwd )"
  SOURCE="$(readlink "$SOURCE")"
  [[ $SOURCE != /* ]] && SOURCE="$SRC_DIR/$SOURCE" # if $SOURCE was a relative symlink, we need to resolve it relative to the path where the symlink file was located
done
SRC_DIR="$( cd -P "$( dirname "$SOURCE" )" >/dev/null 2>&1 && pwd )"

# Compositor
pidof picom || picom &

# Notification manager
pidof dunst || dunst &

# Start kdeconnect deamon
pidof kdeconnectd || kdeconnect-cli -l &

# Set wallpaper
feh $SRC_DIR/wallpaper --bg-fill &

# dwmblocks
pkill dwmblocks; $SRC_DIR/dwmblocks/dwmblocks &


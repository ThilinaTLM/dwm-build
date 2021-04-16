#!/bin/sh

case $DWM_ACTION in 
    1)
        pamixer --allow-boost -d 5
        pkill -RTMIN+10 dwmblocks
        ;;
    2)
        pamixer --allow-boost -i 5
        pkill -RTMIN+10 dwmblocks
        ;;
    3)
        pamixer -t
        pkill -RTMIN+10 dwmblocks
        ;;
esac

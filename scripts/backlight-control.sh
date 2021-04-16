#!/bin/sh

case $DWM_ACTION in 
    1)
        xbacklight -dec 5
        pkill -RTMIN+20 dwmblocks
        ;;
    2)
        xbacklight -inc 5
        pkill -RTMIN+20 dwmblocks
        ;;
esac

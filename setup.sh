#!/bin/bash

SOURCE="${BASH_SOURCE[0]}"
while [ -h "$SOURCE" ]; do # resolve $SOURCE until the file is no longer a symlink
  DIR="$( cd -P "$( dirname "$SOURCE" )" >/dev/null 2>&1 && pwd )"
  SOURCE="$(readlink "$SOURCE")"
  [[ $SOURCE != /* ]] && SOURCE="$DIR/$SOURCE" # if $SOURCE was a relative symlink, we need to resolve it relative to the path where the symlink file was located
done
DIR="$( cd -P "$( dirname "$SOURCE" )" >/dev/null 2>&1 && pwd )"

CWD=$(pwd)

case $1 in
    d|dwm)
        echo "Compiling & Installing dwm"
        cd $DIR/src
        sudo cp config.def.h config.h
        sudo make clean install
        ;;
    db|dwmblocks)
        echo "Compiling dwmblocks"
        cd $DIR/dwmblocks
        make
        ;;
    s|script|scripts)
        chmod +x $DIR/autostart.sh
        chmod +x $DIR/scripts/*.sh
        chmod +x $DIR/dwmblocks/blocks/*
        ;;
    c|clean)
        echo "Cleaning"
        cd $DIR/src
        sudo cp config.def.h config.h
        make clean
        cd $DIR/dwmblocks
        make clean
        ;;
    *)
        echo "[USAGE]:"
        echo "  d, dwm              - Compile & Install dwm"
        echo "  db, dwmblocks       - Compiling dwmblocks"
        echo "  s,script,scripts    - Make all scripts executable"
        echo "  c,clean             - Remove all build files"
        ;;
esac

cd $CWD

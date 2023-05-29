export ZCCCFG=/usr/local/z88dk/lib/config
DIRNAME=`dirname "$0"`
cd "$DIRNAME"
echo "Starting build..."
zcc +z80 -mz80 -startup 0 -zorg 0x140D --no-crt -O3 --opt-code-speed -I/usr/local/z88dk/include/ -lm main.c -o "000001.nabu"

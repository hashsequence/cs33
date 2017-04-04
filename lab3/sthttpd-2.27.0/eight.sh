#/bin/sh

make clean
make CFLAGS='-S -O2 -fno-inline -fstack-protector-strong'
mv src/thttpd.o src/thttpd-sp.s

make clean
make CFLAGS='-S -O2 -fno-inline -static-libasan -fsanitize=address'
mv src/thttpd.o src/thttpd-as.s

make clean
make CFLAGS='-S -O2 -fno-inline -fno-stack-protector -zexecstack'
mv src/thttpd.o src/thttpd-no.s

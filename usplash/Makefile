CC=gcc
CFLAGS=-g -Wall -fPIC
LDFLAGS=
INCLUDES=

COMPILE = $(CC) $(INCLUDES) $(CFLAGS)
LINK = $(CC) $(CFLAGS) $(LDFLAGS)

INSTALL = /usr/bin/install -c
INSTALL_DATA = $(INSTALL) -m 644
INSTALL_PROGRAM = $(INSTALL) -m 755

usplash-theme-albatross.so: throbber_back.png.c.o throbber_back_16.png.c.o throbber_fore.png.c.o throbber_fore_16.png.c.o \
		 throbber_back_32.png.c.o throbber_fore_32.png.c.o \
		 logo_xsmall.png.c.o logo_small.png.c.o logo_med.png.c.o logo_large.png.c.o logo_xlarge.png.c.o \
		 usplash-theme-albatross.c.o
	$(COMPILE) -shared -o $@ $^

%.png.c: %.png
	pngtousplash $< > $@

%.bdf.c: %.bdf
	bdftousplash $< > $@

%.c.o: %.c
	$(COMPILE) -o $@ -c $<

install:
	$(INSTALL) -d $(DESTDIR)/usr/lib/usplash
	$(INSTALL_PROGRAM) usplash-theme-albatross.so $(DESTDIR)/usr/lib/usplash/usplash-theme-albatross.so
clean:
	rm -f *.png.c *.bdf.c *.c.o *.so

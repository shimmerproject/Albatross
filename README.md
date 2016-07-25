Albatross
=========
Desktop Suite for Xfce
----------------------
URL: http://shimmerproject.org/projects/albatross/

Copyright 2009–2012 James Schriver, Steve Dodier, Pasi Lallinaho, Mads Rosendahl Hansen

Albatross is dual-licensed as GPLv2 or later and CC-BY-SA 3.0 or later.

Contributors:
 * Satyajit Sahoo
 * Simon Steinbeiß

Albatross was the default theme in Xubuntu 9.10 and 10.04.

The Albatross desktop suite includes:
- GTK+2/3 theme
- Xfwm4 theme
- Metacity/Mutter theme
- Unity support

### Install without admin privileges

```
./autogen.sh --prefix=$HOME/.local
make install
```

### Install for all users

```
./autogen.sh
sudo make install

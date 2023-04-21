AC_PREREQ(2.64)
AC_INIT([ditl-fix-pcap-header-len-caplen], [0.1.0])
AM_INIT_AUTOMAKE([-Wall -Werror foreign subdir-objects])
AC_CONFIG_SRCDIR([src/main.c])
AC_CONFIG_HEADER([src/config.h])

# Checks for programs.
AC_PROG_CC
AM_PROG_CC_C_O
m4_ifdef([AM_PROG_AR], [AM_PROG_AR])
LT_INIT([disable-static])

AC_CHECK_LIB([pcap], [pcap_open_live], [], [AC_MSG_ERROR([libpcap not found])])
AC_CHECK_HEADER([pcap/pcap.h], [], [AC_MSG_ERROR([libpcap header not found])])

AC_CONFIG_FILES([
  Makefile
  src/Makefile
])
AC_OUTPUT

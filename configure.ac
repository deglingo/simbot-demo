AC_INIT([simbot-demo], [0.0.0])
AM_INIT_AUTOMAKE

: ${CFLAGS:=-g -O0 -Wall}

AC_PROG_CC
AM_PROG_CC_C_O
LT_INIT

PKG_CHECK_MODULES([SIMBOT], [simbot])
PKG_CHECK_MODULES([LIBISO], [libiso])
PKG_CHECK_MODULES([ALTK], [altk])

AC_CONFIG_FILES([ \
  Makefile \
  src/Makefile \
])
AC_OUTPUT

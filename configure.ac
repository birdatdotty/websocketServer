#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([server], [0.9], [bird@dotty.su])
AC_CONFIG_SRCDIR([main.cc])
AC_CONFIG_HEADERS([config.h])


if test "x$prefix" != xNONE; then
  PREFIX="$prefix"
else
  PREFIX="/usr/local/bin"
fi

if test "x$site" != x; then
  SITE="$site"
else
  SITE="/var/www/html"
fi


if test "x$localstatedir" != "x${prefix}/var"; then
  VAR="/usr/local/var"
else
  VAR="$localstatedir"
fi

test "$localstatedir" = '${prefix}/var' && localstatedir='/usr/local/var'
test "$sysconfdir" = '${prefix}/etc' && sysconfdir='/usr/local/etc'

AC_DEFINE_UNQUOTED(PREFIX, ["$PREFIX"], [Installation prefix])
AC_DEFINE_UNQUOTED(VAR, ["$VAR"], [Installation prefix])
AC_DEFINE_UNQUOTED(SITE, ["$SITE"], [path to site])

# Checks for programs.
AC_PROG_AWK
AC_PROG_CXX
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET
LT_INIT

#LDFLAGS="$LDFLAGS "-Wl,-Bstatic -lfoo -Wl,-Bdynamic

CXXFLAGS="-std=c++11"

# Checks for libraries.
# FIXME: Replace `main' with a function in `-lboost_filesystem':
AC_CHECK_LIB([boost_filesystem], [main])
# FIXME: Replace `main' with a function in `-lboost_system':
AC_CHECK_LIB([boost_system], [main])
# FIXME: Replace `main' with a function in `-lboost_locale':
AC_CHECK_LIB([boost_locale], [main])
# FIXME: Replace `main' with a function in `-ljsoncpp':
AC_CHECK_LIB([jsoncpp], [main], [], [AC_MSG_ERROR(
             [Please install libjsoncpp-dev])])
# FIXME: Replace `main' with a function in `-lsqlite3':
AC_CHECK_LIB([sqlite3], [main])
# FIXME: Replace `main' with a function in `-luuid':
AC_CHECK_LIB([uuid], [main])
# "-lpq -lpqxx"
AC_CHECK_LIB([pq], [main])
AC_CHECK_LIB([pqxx], [main])
# "-lb64"
#AC_CHECK_LIB([b64], [main])

# Checks for header files.
AC_CHECK_HEADERS([netinet/in.h string.h sys/ioctl.h sys/socket.h sys/time.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_SIZE_T
AC_TYPE_UINT16_T
AC_TYPE_UINT64_T

# Checks for library functions.
AC_FUNC_MALLOC
AC_CHECK_FUNCS([gettimeofday memset select strchr strdup strrchr])

AC_CONFIG_FILES([ Makefile
                  CServer/Makefile
                  log/Makefile
                  proxy/Makefile
                  proxy/auth/Makefile
                  proxy/b64/Makefile
                  proxy/postgres/Makefile
                  proxy/actions/Makefile])

AM_INIT_AUTOMAKE
AC_OUTPUT

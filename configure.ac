dnl Process this file with autoconf to produce a configure script
dnl
dnl Author: Niklas Karlsson <nkarlsson@physics.umn.edu>
dnl

AC_INIT(root/ROOTObject.h)
AC_CONFIG_AUX_DIR(config)
dnl Do not forget to update library interface versions
AM_INIT_AUTOMAKE(ROOTobject, 0.1.0)
AM_CONFIG_HEADER(config.h)

AC_CONFIG_MACRO_DIR([m4])

dnl Do compilation tests with C++
AC_LANG_CPLUSPLUS

dnl Check for programs
AC_PROG_CXX

dnl Disable build of static libraries
AM_DISABLE_STATIC

dnl Setup install program
AM_PROG_INSTALL

dnl Setup libtool
AM_PROG_LIBTOOL

dnl Check for gmake and use it
AC_CHECK_PROG(GMAKE, gmake, gmake, make)
AC_SUBST(GMAKE)

dnl Check for C++ header files
AC_CHECK_HEADERS([cerrno cfloat cstdio cstdlib ctime])

dnl Turn on -Wall if compiling with gcc
#AC_COMPILE_WARNINGS

dnl
dnl Check for ROOT installation (required)
dnl
AC_ARG_WITH([root-dir],
  [AS_HELP_STRING([--with-root-dir], [ROOT directory])],
  [root_dir=$with_root_dir],
  [])

if test -n $root_dir; then
  old_PATH=$PATH
  PATH="$root_dir/bin:$PATH"
  AC_PATH_PROG([ROOT_CONFIG],[root-config],[no])
  PATH=$old_PATH
else
  AC_PATH_PROG([ROOT_CONFIG],[root-config],[no])
fi

if test -z $ROOT_CONFIG; then
  AC_MSG_WARN([cannot find the 'root-config' executable; use --root-dir])
else
  # we use --glibs and not --libs to include the libGui.so library
  root_libs=`$ROOT_CONFIG --glibs`
  root_include=`$ROOT_CONFIG --cflags`
  root_dir=`$ROOT_CONFIG --bindir`
  AC_SUBST([ROOT_LIBS],[$root_libs])
  AC_SUBST([ROOT_INCLUDE],[$root_include])
  AC_MSG_NOTICE([ROOT library: $root_libs])
  AC_MSG_NOTICE([ROOT includes: $root_include])
  
  AC_SUBST([ROOTCINT_BIN],[$root_dir/rootcint])
fi

AM_SANITY_CHECK

dnl
dnl Files to be generated
dnl
AC_OUTPUT(Makefile \
          root/Makefile \
          src/Makefile
)

dnl
dnl Output config status message
dnl
AC_MSG_RESULT([
ROOTlib successfully configured!])

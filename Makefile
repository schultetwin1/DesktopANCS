#############################################################################
# Makefile for building: DesktopANCS
# Generated by qmake (3.0) (Qt 5.7.0)
# Project:  DesktopANCS.pro
# Template: app
# Command: /usr/bin/qmake -o Makefile DesktopANCS.pro
#############################################################################

MAKEFILE      = Makefile

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_BLUETOOTH_LIB -DQT_CORE_LIB
CFLAGS        = -pipe -O2 -march=x86-64 -mtune=generic -O2 -pipe -fstack-protector-strong -Wall -W -D_REENTRANT -fPIC $(DEFINES)
CXXFLAGS      = -pipe -O2 -march=x86-64 -mtune=generic -O2 -pipe -fstack-protector-strong -std=gnu++11 -Wall -W -D_REENTRANT -fPIC $(DEFINES)
INCPATH       = -I. -I. -isystem /usr/include/qt -isystem /usr/include/qt/QtBluetooth -isystem /usr/include/qt/QtCore -I. -I/usr/lib/qt/mkspecs/linux-g++
QMAKE         = /usr/bin/qmake
DEL_FILE      = rm -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
COPY          = cp -f
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
INSTALL_FILE  = install -m 644 -p
INSTALL_PROGRAM = install -m 755 -p
INSTALL_DIR   = cp -f -R
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
TAR           = tar -cf
COMPRESS      = gzip -9f
DISTNAME      = DesktopANCS1.0.0
DISTDIR = /home/matt/dev/DesktopANCS/.tmp/DesktopANCS1.0.0
LINK          = g++
LFLAGS        = -Wl,-O1 -Wl,-O1,--sort-common,--as-needed,-z,relro -Wl,-rpath-link,/usr/lib
LIBS          = $(SUBLIBS) -lQt5Bluetooth -lQt5DBus -lQt5Core -lpthread 
AR            = ar cqs
RANLIB        = 
SED           = sed
STRIP         = strip

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		ancs.cpp \
		ancsnotification.cpp moc_ancs.cpp
OBJECTS       = main.o \
		ancs.o \
		ancsnotification.o \
		moc_ancs.o
DIST          = /usr/lib/qt/mkspecs/features/spec_pre.prf \
		/usr/lib/qt/mkspecs/common/unix.conf \
		/usr/lib/qt/mkspecs/common/linux.conf \
		/usr/lib/qt/mkspecs/common/sanitize.conf \
		/usr/lib/qt/mkspecs/common/gcc-base.conf \
		/usr/lib/qt/mkspecs/common/gcc-base-unix.conf \
		/usr/lib/qt/mkspecs/common/g++-base.conf \
		/usr/lib/qt/mkspecs/common/g++-unix.conf \
		/usr/lib/qt/mkspecs/qconfig.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_bluetooth.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_bluetooth_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_bootstrap_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_clucene_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_concurrent_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_core.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_core_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_dbus.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_dbus_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_declarative.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_declarative_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_designer.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_designer_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_designercomponents_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_eglfs_device_lib_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_eglfs_kms_support_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_gui.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_gui_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_help.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_help_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_location.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_location_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_multimedia.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_multimedia_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_multimediawidgets.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_multimediawidgets_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_network.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_network_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_nfc.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_nfc_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_opengl.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_opengl_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_openglextensions.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_openglextensions_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_packetprotocol_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_platformsupport_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_positioning.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_positioning_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_printsupport_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_qml.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_qml_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_qmldebug_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_qmldevtools_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_qmltest.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_qmltest_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_quick.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_quick_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_quickcontrols2.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_quickcontrols2_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_quickparticles_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_quicktemplates2_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_quickwidgets.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_quickwidgets_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_script.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_script_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_scripttools.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_scripttools_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_sensors.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_sensors_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_sql.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_sql_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_svg.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_svg_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_testlib.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_testlib_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_uiplugin.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_uitools.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_uitools_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_webchannel.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_webchannel_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_webkit.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_webkit_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_webkitwidgets.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_webkitwidgets_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_widgets.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_widgets_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_xml.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_xml_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_xmlpatterns.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_xmlpatterns_private.pri \
		/usr/lib/qt/mkspecs/features/qt_functions.prf \
		/usr/lib/qt/mkspecs/features/qt_config.prf \
		/usr/lib/qt/mkspecs/linux-g++/qmake.conf \
		/usr/lib/qt/mkspecs/features/spec_post.prf \
		.qmake.stash \
		/usr/lib/qt/mkspecs/features/exclusive_builds.prf \
		/usr/lib/qt/mkspecs/features/default_pre.prf \
		/usr/lib/qt/mkspecs/features/resolve_config.prf \
		/usr/lib/qt/mkspecs/features/default_post.prf \
		/usr/lib/qt/mkspecs/features/warn_on.prf \
		/usr/lib/qt/mkspecs/features/qt.prf \
		/usr/lib/qt/mkspecs/features/resources.prf \
		/usr/lib/qt/mkspecs/features/moc.prf \
		/usr/lib/qt/mkspecs/features/unix/thread.prf \
		/usr/lib/qt/mkspecs/features/file_copies.prf \
		/usr/lib/qt/mkspecs/features/testcase_targets.prf \
		/usr/lib/qt/mkspecs/features/exceptions.prf \
		/usr/lib/qt/mkspecs/features/yacc.prf \
		/usr/lib/qt/mkspecs/features/lex.prf \
		DesktopANCS.pro ancs.h \
		ancsnotification.h main.cpp \
		ancs.cpp \
		ancsnotification.cpp
QMAKE_TARGET  = DesktopANCS
DESTDIR       = 
TARGET        = DesktopANCS


first: all
####### Build rules

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: DesktopANCS.pro /usr/lib/qt/mkspecs/linux-g++/qmake.conf /usr/lib/qt/mkspecs/features/spec_pre.prf \
		/usr/lib/qt/mkspecs/common/unix.conf \
		/usr/lib/qt/mkspecs/common/linux.conf \
		/usr/lib/qt/mkspecs/common/sanitize.conf \
		/usr/lib/qt/mkspecs/common/gcc-base.conf \
		/usr/lib/qt/mkspecs/common/gcc-base-unix.conf \
		/usr/lib/qt/mkspecs/common/g++-base.conf \
		/usr/lib/qt/mkspecs/common/g++-unix.conf \
		/usr/lib/qt/mkspecs/qconfig.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_bluetooth.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_bluetooth_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_bootstrap_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_clucene_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_concurrent_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_core.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_core_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_dbus.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_dbus_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_declarative.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_declarative_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_designer.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_designer_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_designercomponents_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_eglfs_device_lib_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_eglfs_kms_support_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_gui.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_gui_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_help.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_help_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_location.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_location_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_multimedia.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_multimedia_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_multimediawidgets.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_multimediawidgets_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_network.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_network_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_nfc.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_nfc_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_opengl.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_opengl_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_openglextensions.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_openglextensions_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_packetprotocol_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_platformsupport_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_positioning.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_positioning_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_printsupport_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_qml.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_qml_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_qmldebug_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_qmldevtools_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_qmltest.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_qmltest_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_quick.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_quick_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_quickcontrols2.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_quickcontrols2_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_quickparticles_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_quicktemplates2_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_quickwidgets.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_quickwidgets_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_script.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_script_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_scripttools.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_scripttools_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_sensors.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_sensors_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_sql.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_sql_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_svg.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_svg_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_testlib.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_testlib_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_uiplugin.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_uitools.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_uitools_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_webchannel.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_webchannel_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_webkit.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_webkit_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_webkitwidgets.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_webkitwidgets_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_widgets.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_widgets_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_xml.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_xml_private.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_xmlpatterns.pri \
		/usr/lib/qt/mkspecs/modules/qt_lib_xmlpatterns_private.pri \
		/usr/lib/qt/mkspecs/features/qt_functions.prf \
		/usr/lib/qt/mkspecs/features/qt_config.prf \
		/usr/lib/qt/mkspecs/linux-g++/qmake.conf \
		/usr/lib/qt/mkspecs/features/spec_post.prf \
		.qmake.stash \
		/usr/lib/qt/mkspecs/features/exclusive_builds.prf \
		/usr/lib/qt/mkspecs/features/default_pre.prf \
		/usr/lib/qt/mkspecs/features/resolve_config.prf \
		/usr/lib/qt/mkspecs/features/default_post.prf \
		/usr/lib/qt/mkspecs/features/warn_on.prf \
		/usr/lib/qt/mkspecs/features/qt.prf \
		/usr/lib/qt/mkspecs/features/resources.prf \
		/usr/lib/qt/mkspecs/features/moc.prf \
		/usr/lib/qt/mkspecs/features/unix/thread.prf \
		/usr/lib/qt/mkspecs/features/file_copies.prf \
		/usr/lib/qt/mkspecs/features/testcase_targets.prf \
		/usr/lib/qt/mkspecs/features/exceptions.prf \
		/usr/lib/qt/mkspecs/features/yacc.prf \
		/usr/lib/qt/mkspecs/features/lex.prf \
		DesktopANCS.pro \
		/usr/lib/libQt5Bluetooth.prl \
		/usr/lib/libQt5Core.prl
	$(QMAKE) -o Makefile DesktopANCS.pro
/usr/lib/qt/mkspecs/features/spec_pre.prf:
/usr/lib/qt/mkspecs/common/unix.conf:
/usr/lib/qt/mkspecs/common/linux.conf:
/usr/lib/qt/mkspecs/common/sanitize.conf:
/usr/lib/qt/mkspecs/common/gcc-base.conf:
/usr/lib/qt/mkspecs/common/gcc-base-unix.conf:
/usr/lib/qt/mkspecs/common/g++-base.conf:
/usr/lib/qt/mkspecs/common/g++-unix.conf:
/usr/lib/qt/mkspecs/qconfig.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_bluetooth.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_bluetooth_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_bootstrap_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_clucene_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_concurrent.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_concurrent_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_core.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_core_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_dbus.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_dbus_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_declarative.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_declarative_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_designer.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_designer_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_designercomponents_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_eglfs_device_lib_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_eglfs_kms_support_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_gui.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_gui_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_help.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_help_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_location.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_location_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_multimedia.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_multimedia_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_multimediawidgets.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_multimediawidgets_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_network.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_network_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_nfc.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_nfc_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_opengl.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_opengl_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_openglextensions.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_openglextensions_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_packetprotocol_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_platformsupport_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_positioning.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_positioning_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_printsupport.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_printsupport_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_qml.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_qml_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_qmldebug_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_qmldevtools_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_qmltest.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_qmltest_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_quick.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_quick_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_quickcontrols2.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_quickcontrols2_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_quickparticles_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_quicktemplates2_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_quickwidgets.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_quickwidgets_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_script.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_script_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_scripttools.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_scripttools_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_sensors.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_sensors_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_sql.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_sql_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_svg.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_svg_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_testlib.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_testlib_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_uiplugin.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_uitools.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_uitools_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_webchannel.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_webchannel_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_webkit.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_webkit_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_webkitwidgets.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_webkitwidgets_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_widgets.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_widgets_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_xml.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_xml_private.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_xmlpatterns.pri:
/usr/lib/qt/mkspecs/modules/qt_lib_xmlpatterns_private.pri:
/usr/lib/qt/mkspecs/features/qt_functions.prf:
/usr/lib/qt/mkspecs/features/qt_config.prf:
/usr/lib/qt/mkspecs/linux-g++/qmake.conf:
/usr/lib/qt/mkspecs/features/spec_post.prf:
.qmake.stash:
/usr/lib/qt/mkspecs/features/exclusive_builds.prf:
/usr/lib/qt/mkspecs/features/default_pre.prf:
/usr/lib/qt/mkspecs/features/resolve_config.prf:
/usr/lib/qt/mkspecs/features/default_post.prf:
/usr/lib/qt/mkspecs/features/warn_on.prf:
/usr/lib/qt/mkspecs/features/qt.prf:
/usr/lib/qt/mkspecs/features/resources.prf:
/usr/lib/qt/mkspecs/features/moc.prf:
/usr/lib/qt/mkspecs/features/unix/thread.prf:
/usr/lib/qt/mkspecs/features/file_copies.prf:
/usr/lib/qt/mkspecs/features/testcase_targets.prf:
/usr/lib/qt/mkspecs/features/exceptions.prf:
/usr/lib/qt/mkspecs/features/yacc.prf:
/usr/lib/qt/mkspecs/features/lex.prf:
DesktopANCS.pro:
/usr/lib/libQt5Bluetooth.prl:
/usr/lib/libQt5Core.prl:
qmake: FORCE
	@$(QMAKE) -o Makefile DesktopANCS.pro

qmake_all: FORCE


all: Makefile $(TARGET)

dist: distdir FORCE
	(cd `dirname $(DISTDIR)` && $(TAR) $(DISTNAME).tar $(DISTNAME) && $(COMPRESS) $(DISTNAME).tar) && $(MOVE) `dirname $(DISTDIR)`/$(DISTNAME).tar.gz . && $(DEL_FILE) -r $(DISTDIR)

distdir: FORCE
	@test -d $(DISTDIR) || mkdir -p $(DISTDIR)
	$(COPY_FILE) --parents $(DIST) $(DISTDIR)/
	$(COPY_FILE) --parents ancs.h ancsnotification.h $(DISTDIR)/
	$(COPY_FILE) --parents main.cpp ancs.cpp ancsnotification.cpp $(DISTDIR)/


clean: compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


distclean: clean 
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) .qmake.stash
	-$(DEL_FILE) Makefile


####### Sub-libraries

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

check: first

benchmark: first

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_moc_header_make_all: moc_ancs.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_ancs.cpp
moc_ancs.cpp: ancs.h \
		/usr/bin/moc
	/usr/bin/moc $(DEFINES) -I/usr/lib/qt/mkspecs/linux-g++ -I/home/matt/dev/DesktopANCS -I/home/matt/dev/DesktopANCS -I/usr/include/qt -I/usr/include/qt/QtBluetooth -I/usr/include/qt/QtCore -I/usr/include/c++/6.2.1 -I/usr/include/c++/6.2.1/x86_64-pc-linux-gnu -I/usr/include/c++/6.2.1/backward -I/usr/lib/gcc/x86_64-pc-linux-gnu/6.2.1/include -I/usr/local/include -I/usr/lib/gcc/x86_64-pc-linux-gnu/6.2.1/include-fixed -I/usr/include ancs.h -o moc_ancs.cpp

compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean 

####### Compile

main.o: main.cpp ancs.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

ancs.o: ancs.cpp ancs.h \
		ancsnotification.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ancs.o ancs.cpp

ancsnotification.o: ancsnotification.cpp ancsnotification.h \
		ancs.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ancsnotification.o ancsnotification.cpp

moc_ancs.o: moc_ancs.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_ancs.o moc_ancs.cpp

####### Install

install:  FORCE

uninstall:  FORCE

FORCE:


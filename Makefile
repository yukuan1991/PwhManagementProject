#############################################################################
# Makefile for building: PwhManagementProject
# Generated by qmake (3.1) (Qt 5.9.0)
# Project:  PwhManagementProject.pro
# Template: app
# Command: D:/qt-build/qt/bin/qmake.exe -o Makefile PwhManagementProject.pro -spec win32-g++ CONFIG+=qml_debug
#############################################################################

MAKEFILE      = Makefile

first: debug
install: debug-install
uninstall: debug-uninstall
QMAKE         = D:/qt-build/qt/bin/qmake.exe
DEL_FILE      = rm -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
COPY          = cp -f
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
INSTALL_FILE  = cp -f
INSTALL_PROGRAM = cp -f
INSTALL_DIR   = cp -f -R
QINSTALL_FILE = D:/qt-build/qt/bin/qmake.exe -install qinstall file
QINSTALL_PROGRAM = D:/qt-build/qt/bin/qmake.exe -install qinstall program
DEL_FILE      = rm -f
SYMLINK       = $(QMAKE) -install ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
SUBTARGETS    =  \
		debug \
		release


debug: FORCE
	$(MAKE) -f $(MAKEFILE).Debug
debug-make_first: FORCE
	$(MAKE) -f $(MAKEFILE).Debug 
debug-all: FORCE
	$(MAKE) -f $(MAKEFILE).Debug all
debug-clean: FORCE
	$(MAKE) -f $(MAKEFILE).Debug clean
debug-distclean: FORCE
	$(MAKE) -f $(MAKEFILE).Debug distclean
debug-install: FORCE
	$(MAKE) -f $(MAKEFILE).Debug install
debug-uninstall: FORCE
	$(MAKE) -f $(MAKEFILE).Debug uninstall
release: FORCE
	$(MAKE) -f $(MAKEFILE).Release
release-make_first: FORCE
	$(MAKE) -f $(MAKEFILE).Release 
release-all: FORCE
	$(MAKE) -f $(MAKEFILE).Release all
release-clean: FORCE
	$(MAKE) -f $(MAKEFILE).Release clean
release-distclean: FORCE
	$(MAKE) -f $(MAKEFILE).Release distclean
release-install: FORCE
	$(MAKE) -f $(MAKEFILE).Release install
release-uninstall: FORCE
	$(MAKE) -f $(MAKEFILE).Release uninstall

Makefile: PwhManagementProject.pro ../../qt-build/qt/mkspecs/win32-g++/qmake.conf ../../qt-build/qt/mkspecs/features/spec_pre.prf \
		../../qt-build/qt/mkspecs/qdevice.pri \
		../../qt-build/qt/mkspecs/features/device_config.prf \
		../../qt-build/qt/mkspecs/common/g++-base.conf \
		../../qt-build/qt/mkspecs/common/windows-gles.conf \
		../../qt-build/qt/mkspecs/common/sanitize.conf \
		../../qt-build/qt/mkspecs/common/gcc-base.conf \
		../../qt-build/qt/mkspecs/qconfig.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_accessibility_support_private.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_av.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_av_private.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_avwidgets.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_avwidgets_private.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_axbase.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_axbase_private.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_axcontainer.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_axcontainer_private.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_axserver.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_axserver_private.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_bluetooth.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_bluetooth_private.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_bootstrap_private.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_charts.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_charts_private.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_concurrent.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_concurrent_private.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_contacts.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_contacts_private.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_core.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_core_private.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_dbus.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_dbus_private.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_devicediscovery_support_private.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_docgallery.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_docgallery_private.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_fb_support_private.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_fontdatabase_support_private.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_gamepad.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_gamepad_private.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_gui.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_gui_private.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_network.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_network_private.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_nfc.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_nfc_private.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_opengl.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_opengl_private.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_openglextensions.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_openglextensions_private.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_organizer.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_organizer_private.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_packetprotocol_private.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_platformcompositor_support_private.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_printsupport.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_printsupport_private.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_publishsubscribe.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_publishsubscribe_private.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_purchasing.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_purchasing_private.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_qml.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_qml_private.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_qmldebug_private.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_qmldevtools_private.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_qmltest.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_qmltest_private.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_quick.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_quick_private.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_quickparticles_private.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_quickwidgets.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_quickwidgets_private.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_remoteobjects.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_remoteobjects_private.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_repparser.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_repparser_private.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_scxml.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_scxml_private.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_serialbus.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_serialbus_private.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_serialport.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_serialport_private.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_serviceframework.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_serviceframework_private.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_sql.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_sql_private.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_svg.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_svg_private.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_testlib.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_testlib_private.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_theme_support_private.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_versit.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_versit_private.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_versitorganizer.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_versitorganizer_private.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_websockets.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_websockets_private.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_widgets.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_widgets_private.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_xlsx.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_xlsx_private.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_xml.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_xml_private.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_xmlpatterns.pri \
		../../qt-build/qt/mkspecs/modules/qt_lib_xmlpatterns_private.pri \
		../../qt-build/qt/mkspecs/features/qt_functions.prf \
		../../qt-build/qt/mkspecs/features/qt_config.prf \
		../../qt-build/qt/mkspecs/win32-g++/qmake.conf \
		../../qt-build/qt/mkspecs/features/spec_post.prf \
		.qmake.stash \
		../../qt-build/qt/mkspecs/features/exclusive_builds.prf \
		../../qt-build/qt/mkspecs/features/toolchain.prf \
		../../qt-build/qt/mkspecs/features/default_pre.prf \
		../../qt-build/qt/mkspecs/features/win32/default_pre.prf \
		../../qt-build/qt/mkspecs/features/resolve_config.prf \
		../../qt-build/qt/mkspecs/features/exclusive_builds_post.prf \
		../../qt-build/qt/mkspecs/features/default_post.prf \
		../../qt-build/qt/mkspecs/features/qml_debug.prf \
		../../qt-build/qt/mkspecs/features/precompile_header.prf \
		../../qt-build/qt/mkspecs/features/warn_on.prf \
		../../qt-build/qt/mkspecs/features/qt.prf \
		../../qt-build/qt/mkspecs/features/resources.prf \
		../../qt-build/qt/mkspecs/features/moc.prf \
		../../qt-build/qt/mkspecs/features/win32/opengl.prf \
		../../qt-build/qt/mkspecs/features/uic.prf \
		../../qt-build/qt/mkspecs/features/qmake_use.prf \
		../../qt-build/qt/mkspecs/features/file_copies.prf \
		../../qt-build/qt/mkspecs/features/win32/windows.prf \
		../../qt-build/qt/mkspecs/features/testcase_targets.prf \
		../../qt-build/qt/mkspecs/features/exceptions.prf \
		../../qt-build/qt/mkspecs/features/yacc.prf \
		../../qt-build/qt/mkspecs/features/lex.prf \
		PwhManagementProject.pro \
		../../qt-build/qt/lib/qtmaind.prl \
		../../qt-build/qt/lib/Qt5Widgets.prl \
		../../qt-build/qt/lib/Qt5Gui.prl \
		../../qt-build/qt/lib/Qt5Core.prl
	$(QMAKE) -o Makefile PwhManagementProject.pro -spec win32-g++ CONFIG+=qml_debug
../../qt-build/qt/mkspecs/features/spec_pre.prf:
../../qt-build/qt/mkspecs/qdevice.pri:
../../qt-build/qt/mkspecs/features/device_config.prf:
../../qt-build/qt/mkspecs/common/g++-base.conf:
../../qt-build/qt/mkspecs/common/windows-gles.conf:
../../qt-build/qt/mkspecs/common/sanitize.conf:
../../qt-build/qt/mkspecs/common/gcc-base.conf:
../../qt-build/qt/mkspecs/qconfig.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_accessibility_support_private.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_av.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_av_private.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_avwidgets.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_avwidgets_private.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_axbase.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_axbase_private.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_axcontainer.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_axcontainer_private.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_axserver.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_axserver_private.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_bluetooth.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_bluetooth_private.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_bootstrap_private.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_charts.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_charts_private.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_concurrent.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_concurrent_private.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_contacts.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_contacts_private.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_core.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_core_private.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_dbus.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_dbus_private.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_devicediscovery_support_private.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_docgallery.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_docgallery_private.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_fb_support_private.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_fontdatabase_support_private.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_gamepad.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_gamepad_private.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_gui.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_gui_private.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_network.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_network_private.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_nfc.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_nfc_private.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_opengl.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_opengl_private.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_openglextensions.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_openglextensions_private.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_organizer.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_organizer_private.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_packetprotocol_private.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_platformcompositor_support_private.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_printsupport.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_printsupport_private.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_publishsubscribe.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_publishsubscribe_private.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_purchasing.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_purchasing_private.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_qml.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_qml_private.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_qmldebug_private.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_qmldevtools_private.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_qmltest.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_qmltest_private.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_quick.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_quick_private.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_quickparticles_private.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_quickwidgets.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_quickwidgets_private.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_remoteobjects.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_remoteobjects_private.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_repparser.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_repparser_private.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_scxml.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_scxml_private.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_serialbus.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_serialbus_private.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_serialport.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_serialport_private.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_serviceframework.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_serviceframework_private.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_sql.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_sql_private.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_svg.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_svg_private.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_testlib.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_testlib_private.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_theme_support_private.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_versit.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_versit_private.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_versitorganizer.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_versitorganizer_private.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_websockets.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_websockets_private.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_widgets.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_widgets_private.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_xlsx.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_xlsx_private.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_xml.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_xml_private.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_xmlpatterns.pri:
../../qt-build/qt/mkspecs/modules/qt_lib_xmlpatterns_private.pri:
../../qt-build/qt/mkspecs/features/qt_functions.prf:
../../qt-build/qt/mkspecs/features/qt_config.prf:
../../qt-build/qt/mkspecs/win32-g++/qmake.conf:
../../qt-build/qt/mkspecs/features/spec_post.prf:
.qmake.stash:
../../qt-build/qt/mkspecs/features/exclusive_builds.prf:
../../qt-build/qt/mkspecs/features/toolchain.prf:
../../qt-build/qt/mkspecs/features/default_pre.prf:
../../qt-build/qt/mkspecs/features/win32/default_pre.prf:
../../qt-build/qt/mkspecs/features/resolve_config.prf:
../../qt-build/qt/mkspecs/features/exclusive_builds_post.prf:
../../qt-build/qt/mkspecs/features/default_post.prf:
../../qt-build/qt/mkspecs/features/qml_debug.prf:
../../qt-build/qt/mkspecs/features/precompile_header.prf:
../../qt-build/qt/mkspecs/features/warn_on.prf:
../../qt-build/qt/mkspecs/features/qt.prf:
../../qt-build/qt/mkspecs/features/resources.prf:
../../qt-build/qt/mkspecs/features/moc.prf:
../../qt-build/qt/mkspecs/features/win32/opengl.prf:
../../qt-build/qt/mkspecs/features/uic.prf:
../../qt-build/qt/mkspecs/features/qmake_use.prf:
../../qt-build/qt/mkspecs/features/file_copies.prf:
../../qt-build/qt/mkspecs/features/win32/windows.prf:
../../qt-build/qt/mkspecs/features/testcase_targets.prf:
../../qt-build/qt/mkspecs/features/exceptions.prf:
../../qt-build/qt/mkspecs/features/yacc.prf:
../../qt-build/qt/mkspecs/features/lex.prf:
PwhManagementProject.pro:
../../qt-build/qt/lib/qtmaind.prl:
../../qt-build/qt/lib/Qt5Widgets.prl:
../../qt-build/qt/lib/Qt5Gui.prl:
../../qt-build/qt/lib/Qt5Core.prl:
qmake: FORCE
	@$(QMAKE) -o Makefile PwhManagementProject.pro -spec win32-g++ CONFIG+=qml_debug

qmake_all: FORCE

make_first: debug-make_first release-make_first  FORCE
all: debug-all release-all  FORCE
clean: debug-clean release-clean  FORCE
distclean: debug-distclean release-distclean  FORCE
	-$(DEL_FILE) Makefile
	-$(DEL_FILE) .qmake.stash

debug-mocclean:
	$(MAKE) -f $(MAKEFILE).Debug mocclean
release-mocclean:
	$(MAKE) -f $(MAKEFILE).Release mocclean
mocclean: debug-mocclean release-mocclean

debug-mocables:
	$(MAKE) -f $(MAKEFILE).Debug mocables
release-mocables:
	$(MAKE) -f $(MAKEFILE).Release mocables
mocables: debug-mocables release-mocables

check: first

benchmark: first
FORCE:

$(MAKEFILE).Debug: Makefile
$(MAKEFILE).Release: Makefile

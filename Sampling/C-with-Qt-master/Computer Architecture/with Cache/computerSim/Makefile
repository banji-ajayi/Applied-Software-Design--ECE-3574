#############################################################################
# Makefile for building: computerSim
# Generated by qmake (2.01a) (Qt 4.8.1) on: Sun Apr 7 23:50:31 2013
# Project:  computerSim.pro
# Template: app
# Command: /usr/bin/qmake -spec /usr/share/qt4/mkspecs/linux-g++ CONFIG+=debug CONFIG+=declarative_debug -o Makefile computerSim.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_WEBKIT -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I. -I. -I.
LINK          = g++
LFLAGS        = 
LIBS          = $(SUBLIBS)  -L/usr/lib/i386-linux-gnu -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = computer.cpp \
		datamemorycachegui.cpp \
		main.cpp \
		simulatorgui.cpp \
		controller.cpp moc_computer.cpp \
		moc_datamemorycachegui.cpp \
		moc_simulatorgui.cpp \
		moc_controller.cpp
OBJECTS       = computer.o \
		datamemorycachegui.o \
		main.o \
		simulatorgui.o \
		controller.o \
		moc_computer.o \
		moc_datamemorycachegui.o \
		moc_simulatorgui.o \
		moc_controller.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/declarative_debug.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		computerSim.pro
QMAKE_TARGET  = computerSim
DESTDIR       = 
TARGET        = computerSim

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_datamemorycachegui.h ui_simulatorgui.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)
	{ test -n "$(DESTDIR)" && DESTDIR="$(DESTDIR)" || DESTDIR=.; } && test $$(gdb --version | sed -e 's,[^0-9]\+\([0-9]\)\.\([0-9]\).*,\1\2,;q') -gt 72 && gdb --nx --batch --quiet -ex 'set confirm off' -ex "save gdb-index $$DESTDIR" -ex quit '$(TARGET)' && test -f $(TARGET).gdb-index && objcopy --add-section '.gdb_index=$(TARGET).gdb-index' --set-section-flags '.gdb_index=readonly' '$(TARGET)' '$(TARGET)' && rm -f $(TARGET).gdb-index || true

Makefile: computerSim.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/declarative_debug.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/i386-linux-gnu/libQtGui.prl \
		/usr/lib/i386-linux-gnu/libQtCore.prl
	$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ CONFIG+=debug CONFIG+=declarative_debug -o Makefile computerSim.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/debug.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/declarative_debug.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/i386-linux-gnu/libQtGui.prl:
/usr/lib/i386-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ CONFIG+=debug CONFIG+=declarative_debug -o Makefile computerSim.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/computerSim1.0.0 || $(MKDIR) .tmp/computerSim1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/computerSim1.0.0/ && $(COPY_FILE) --parents computer.h datamemorycachegui.h simulatorgui.h controller.h .tmp/computerSim1.0.0/ && $(COPY_FILE) --parents computer.cpp datamemorycachegui.cpp main.cpp simulatorgui.cpp controller.cpp .tmp/computerSim1.0.0/ && $(COPY_FILE) --parents datamemorycachegui.ui simulatorgui.ui .tmp/computerSim1.0.0/ && (cd `dirname .tmp/computerSim1.0.0` && $(TAR) computerSim1.0.0.tar computerSim1.0.0 && $(COMPRESS) computerSim1.0.0.tar) && $(MOVE) `dirname .tmp/computerSim1.0.0`/computerSim1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/computerSim1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_computer.cpp moc_datamemorycachegui.cpp moc_simulatorgui.cpp moc_controller.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_computer.cpp moc_datamemorycachegui.cpp moc_simulatorgui.cpp moc_controller.cpp
moc_computer.cpp: computer.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) computer.h -o moc_computer.cpp

moc_datamemorycachegui.cpp: computer.h \
		datamemorycachegui.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) datamemorycachegui.h -o moc_datamemorycachegui.cpp

moc_simulatorgui.cpp: computer.h \
		simulatorgui.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) simulatorgui.h -o moc_simulatorgui.cpp

moc_controller.cpp: computer.h \
		datamemorycachegui.h \
		simulatorgui.h \
		controller.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) controller.h -o moc_controller.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_datamemorycachegui.h ui_simulatorgui.h
compiler_uic_clean:
	-$(DEL_FILE) ui_datamemorycachegui.h ui_simulatorgui.h
ui_datamemorycachegui.h: datamemorycachegui.ui
	/usr/bin/uic-qt4 datamemorycachegui.ui -o ui_datamemorycachegui.h

ui_simulatorgui.h: simulatorgui.ui
	/usr/bin/uic-qt4 simulatorgui.ui -o ui_simulatorgui.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

computer.o: computer.cpp computer.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o computer.o computer.cpp

datamemorycachegui.o: datamemorycachegui.cpp datamemorycachegui.h \
		computer.h \
		ui_datamemorycachegui.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o datamemorycachegui.o datamemorycachegui.cpp

main.o: main.cpp controller.h \
		computer.h \
		datamemorycachegui.h \
		simulatorgui.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

simulatorgui.o: simulatorgui.cpp simulatorgui.h \
		computer.h \
		ui_simulatorgui.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o simulatorgui.o simulatorgui.cpp

controller.o: controller.cpp controller.h \
		computer.h \
		datamemorycachegui.h \
		simulatorgui.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o controller.o controller.cpp

moc_computer.o: moc_computer.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_computer.o moc_computer.cpp

moc_datamemorycachegui.o: moc_datamemorycachegui.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_datamemorycachegui.o moc_datamemorycachegui.cpp

moc_simulatorgui.o: moc_simulatorgui.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_simulatorgui.o moc_simulatorgui.cpp

moc_controller.o: moc_controller.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_controller.o moc_controller.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:


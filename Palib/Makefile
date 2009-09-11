
TEXT1 := Game Title
TEXT2 := Subtitle 1
TEXT3 := Subtitle 2

#---------------------------------------------------------------------------------
# Setting default settings:
# Maxmod and EFS
#---------------------------------------------------------------------------------

ARM7_SELECTED = ARM7_MAXMOD_DSWIFI

PATH     := $(DEVKITARM)/bin:$(PATH)
PROGNAME  = PAlib
OFILES   +=
ADD_LIBS +=

ICON := -b $(CURDIR)/../logo.bmp

#---------------------------------------------------------------------------------
# TARGET is the name of the file to output
# BUILD is the directory where object files and intermediate files will be placed
# SOURCES is a list of directories containing source code
# INCLUDES is a list of directories containing extra header files
# MUSIC is a list of directories containing music files
#---------------------------------------------------------------------------------

TARGET   := $(shell basename $(CURDIR))
BUILD    := build
SOURCES  := source data gfx/bin
INCLUDES := include build data gfx
MUSIC    := music

#---------------------------------------------------------------------------------
# If you need to change other parts of the make process, see the PA_Makefile:
#---------------------------------------------------------------------------------

include $(DEVKITPRO)/PAlib/lib/PA_Makefile

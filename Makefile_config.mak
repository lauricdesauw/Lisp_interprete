
PLATFORM := Unknown

SYSTEM := $(shell uname -s)
ifeq ($(SYSTEM), Darwin)
	PLATFORM := Darwin
else
	ifeq ($(SYSTEM), Linux)
		PLATFORM := $(shell lsb_release -si)
	endif
endif

ifeq ($(PLATFORM), Unknown)
$(error Unknown platform: Please check Makefile configuration)
endif

$(info Platform: $(PLATFORM))

###########################################################

ifeq ($(PLATFORM), Ubuntu)
# Ubuntu
CC := g++
OPEN := xdg-open
endif

###########################################################

ifeq ($(PLATFORM), Arch)
# Ubuntu
# pacman -S lsb-release sfml
CC := g++
OPEN := xdg-open
endif

###########################################################

ifeq ($(PLATFORM), Darwin)
# MacOS 10.13
CC := g++
OPEN := open
endif

###########################################################

ifeq ($(PLATFORM), CentOS)
# CentOS
CC := g++
OPEN := xdg-open
endif

###########################################################

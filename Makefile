########################################################################
#                                                                      #
# Copyright(C) 2015 - Belle II Collaboration                           #
# Thu Sep 28 15:32:39 CEST 2017                                        #
# Autor: Leonid Burmistrov                                             #
#                                                                      #
# Script description:                                                  #
#                     This script perform compilation ot the           #
#                     arich support scripts.                           #
#                                                                      #
# Input paramete: NON                                                  #
#                                                                      #
#                                                                      #
# This software is provided "as is" without any warranty.              #
#                                                                      #
########################################################################

ROOTCFLAGS    = $(shell $(ROOTSYS)/bin/root-config --cflags)
ROOTLIBS      = $(shell $(ROOTSYS)/bin/root-config --libs)
ROOTGLIBS     = $(shell $(ROOTSYS)/bin/root-config --glibs)

OUTLIB = ./obj/
CXX  = g++
CXX += -I./     
CXX += -I$(OUTLIB)

CXXFLAGS  = -g -Wall -fPIC -Wno-deprecated
CXXFLAGS += $(ROOTCFLAGS)

#----------------------------------------------------#

all: makeHistFromFile readAerogelInfoMap	

makeHistFromFile: makeHistFromFile.C
	$(CXX) -o makeHistFromFile makeHistFromFile.C  $(ROOTCFLAGS) $(ROOTLIBS) $(ROOTGLIBS) 

readAerogelInfoMap: readAerogelInfoMap.C
	$(CXX) -o readAerogelInfoMap readAerogelInfoMap.C  $(ROOTCFLAGS) $(ROOTLIBS) $(ROOTGLIBS) 

clean:
	rm -rf *~
	rm -rf ../*~
	rm -f makeHistFromFile
	rm -f readAerogelInfoMap

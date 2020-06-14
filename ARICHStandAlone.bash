#!/bin/bash

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

#basf2 ARICHImportGeometryToDB.py

basf2 ARICHStandAlone.py -n 100000

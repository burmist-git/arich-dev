#!/bin/bash

#KEKCC

setupBasf2KEKCC () {

    #releaseName="head_01.07.2017"
    releaseName="head_19.09.2017"
    
    #https
    #git ls-remote https://burmist@stash.desy.de/scm/b2/tools.git master
    git ls-remote ssh://git@stash.desy.de:7999/b2/tools.git master
    source /sw/belle2/tools/setup_belle2
    cd /home/belle2/burmist/basf2/$releaseName/
    setuprel
    cd /home/belle2/burmist/basf2/
    
    eval $(ssh-agent)
    ssh-add
    
    return 0
}

setupBasf2NBburmist () {
    #unset ROOTSYS
    #export BELLE2_USER=burmist
    #echo "BELLE2_USER = $BELLE2_USER"
    
    #basf2ReleasesName="release-00-08-00"
    
    basf2ReleasesName="head_26.09.2017"
    
    echo "basf2ReleasesName = $basf2ReleasesName"

    unset ROOTSYS
    
    export BELLE2_USER=burmist
    
    echo "BELLE2_USER = $BELLE2_USER"
    
    source ./tools/setup_belle2.sh
    
    echo "---------------Before setuprel---------------"
    echo "PATH = $PATH"
    echo "LD_LIBRARY_PATH = $LD_LIBRARY_PATH"
    echo "---------------------------------------------"
    
    cd ./releases/$basf2ReleasesName/
    
    setuprel
    
    echo "---------------After setuprel---------------"
    echo "PATH = $PATH"
    echo "LD_LIBRARY_PATH = $LD_LIBRARY_PATH"
    echo "---------------------------------------------"
    
    cd ../../
    
    eval $(ssh-agent)
    ssh-add

    return 0
}

computername=$(uname -n)

if [ $computername = "nb-gred02" ]; then
    echo $computername
    setupBasf2NBburmist
else
    echo $computername
    setupBasf2KEKCC
fi

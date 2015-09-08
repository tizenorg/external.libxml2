#!/bin/sh
. ./config
#export TET_INSTALL_PATH=/mnt/nfs/dts_tool/TETware # path to path
export TET_INSTALL_PATH=/mnt/nfs/TETware # path to path
export TET_TARGET_PATH=$TET_INSTALL_PATH/tetware-target
#export TET_TARGET_PATH=$TET_INSTALL_PATH/tetware-simulator # tetware simulator path
export PATH=$TET_TARGET_PATH/bin:$PATH
export LD_LIBRARY_PATH=$TET_TARGET_PATH/lib/tet3:$LD_LIBRARY_PATH
export TET_ROOT=$TET_TARGET_PATH

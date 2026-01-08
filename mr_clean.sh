#!/usr/bin/env bash

find ./ -name "*~" -delete
find ./ -name "#*" -delete
find ./ -name "a.*" -delete
echo $PATH
export PATH=~/bin:$PATH
PATH=$PATH:/

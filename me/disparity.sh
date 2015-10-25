#!/bin/bash

NUMBER=00000
PATH=./calib_images
EXT=png
NUMBERS=(00000 00001 00002 00003)	

#	Created from code located at
#		http://tldp.org/LDP/Bash-Beginners-Guide/html/sect_10_02.html
#		http://tldp.org/LDP/abs/html/othertypesv.html
#		http://www.tldp.org/LDP/abs/html/arrays.html
#		http://stackoverflow.com/questions/4181703/how-can-i-concatenate-string-variables-in-bash
#		http://stackoverflow.com/questions/192249/how-do-i-parse-command-line-arguments-in-bash
#		http://stackoverflow.com/questions/12036445/bash-command-line-arguments


#Usage: stereo_match <left_image> <right_image> [--algorithm=bm|sgbm|hh|var] [--blocksize=<block_size>]
#[--max-disparity=<max_disparity>] [--scale=scale_factor>] [-i <intrinsic_filename>] [-e <extrinsic_filename>]
#[--no-display] [-o <disparity_image>] [-p <point_cloud_file>]
for NUMBER in $@
#for NUMBER in ${NUMBERS[@]}
#for NUMBER in $@ 
do
	LEFT="$PATH/left_$NUMBER.$EXT"
	RIGHT="$PATH/right_$NUMBER.$EXT"


	CMD="./stereo_match.out $PATH/left_$NUMBER.$EXT $PATH/right_$NUMBER.$EXT"
	echo $CMD
	$CMD
done
 

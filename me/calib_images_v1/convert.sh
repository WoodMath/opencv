#!/bin/bash

#	Based on articles from 
#		http://stackoverflow.com/questions/192249/how-do-i-parse-command-line-arguments-in-bash
#		http://how-to.wikia.com/wiki/How_to_read_command_line_arguments_in_a_bash_script
#		http://www.linuxjournal.com/content/bash-arrays
#		http://mywiki.wooledge.org/BashGuide/Arrays
#		http://www.thegeekstuff.com/2010/06/bash-array-tutorial/
#		http://www.gnu.org/software/bash/manual/html_node/Arrays.html
#		http://tldp.org/LDP/abs/html/arrays.html
#		http://tldp.org/LDP/Bash-Beginners-Guide/html/sect_10_02.html
#		http://tldp.org/LDP/abs/html/othertypesv.html
#		http://stackoverflow.com/questions/18460123/bash-for-loop-echo-leading-zeroi
#		http://jonathanwagner.net/2007/04/zero-padding-in-bash/
#		http://www.cyberciti.biz/tips/how-to-generating-print-range-sequence-of-numbers.html
#		http://www.imagemagick.org/script/convert.php

LIST=$(seq -f "%03g" 1 26)
EXT_OLD="png"
EXT_NEW="bmp"
SIDE="right"
for NUMBER in $LIST
do
	OLD="${SIDE}_${NUMBER}.${EXT_OLD}"
	NEW="${SIDE}_${NUMBER}.${EXT_NEW}"
	convert $OLD $NEW
done

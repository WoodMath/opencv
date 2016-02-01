#!/bin/bash

#	Based on articles from
#		http://droptips.com/using-grep-and-ignoring-case-case-insensitive-grep
#		http://www.gnu.org/software/grep/manual/grep.html
#		http://linux.die.net/man/1/grep
#		http://www.cyberciti.biz/faq/howto-use-grep-command-in-linux-unix/
#		http://tldp.org/LDP/Bash-Beginners-Guide/html/sect_04_02.html
#		http://tldp.org/LDP/GNU-Linux-Tools-Summary/html/x11655.htm
#		http://linuxcommand.org/man_pages/grep1.html
#		http://ss64.com/bash/grep.html
#		http://www.panix.com/~elflord/unix/grep.html
#		http://www.openbsd.org/cgi-bin/man.cgi/OpenBSD-current/man1/egrep.1?query=grep
#		https://www.digitalocean.com/community/tutorials/using-grep-regular-expressions-to-search-for-text-patterns-in-linux
#		http://www.linuxnix.com/regular-expressions-linux-i/
#		http://tldp.org/LDP/Bash-Beginners-Guide/html/sect_10_02.html
#		http://tldp.org/LDP/abs/html/loops1.html
#		http://www.cyberciti.biz/faq/finding-bash-shell-array-length-elements/
#		http://www.cyberciti.biz/faq/bash-for-loop/
#		http://stackoverflow.com/questions/7174354/bash-array-indexing-minus-the-last-array
#		http://tldp.org/HOWTO/Bash-Prog-Intro-HOWTO-6.html
#		http://tldp.org/LDP/Bash-Beginners-Guide/html/sect_07_01.html
#		http://tldp.org/LDP/Bash-Beginners-Guide/html/sect_07_02.html
#		http://www.thegeekstuff.com/2010/06/bash-if-statement-examples/
EXT_TYPES=(png bmp pnm)
#echo ${EXT_TYPES[*]}
REGEXP="^.*\\.\\("
for NUM in $(seq 1 ${#EXT_TYPES[@]})
do
	LESS_ONE=$(($NUM-1))
	if [ $LESS_ONE -eq 0 ]
	then
		REGEXP="${REGEXP}${EXT_TYPES[${LESS_ONE}]}"
	else
		REGEXP="${REGEXP}\|${EXT_TYPES[${LESS_ONE}]}"
	fi
	rm *.${EXT_TYPES[${LESS_ONE}]}
#	echo "${REGEXP}"
#ls | grep -i '.*\.\(png\|bmp\\)'
done

REGEXP="${REGEXP}\)\$"
#echo $REGEXP
FILES="ls | grep -i ${REGEXP}"
#${FILES}
ls | grep -i "${REGEXP}"





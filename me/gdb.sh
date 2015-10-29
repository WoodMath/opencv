#!/bin/bash


#Code below based on following webpages
#	http://www.unknownroad.com/rtfm/gdbtut/gdbtoc.html
#	http://www.delorie.com/gnu/docs/gdb/gdb_toc.html
#	https://www.gnu.org/software/gdb/
#	http://web.eecs.umich.edu/~sugih/pointers/summary.html
#	https://www.cs.cmu.edu/~gilpin/tutorial/
#	https://sourceware.org/gdb/onlinedocs/gdb/Invoking-GDB.html
#	http://stackoverflow.com/questions/6121094/how-do-i-run-a-program-with-commandline-args-using-gdb-within-a-bash-script
#	http://cs.baylor.edu/~donahoo/tools/gdb/tutorial.html

#Usage:
#	g++ -g broken.cpp -o broken
#	gdb broken
#	(gdb) (b)reak linenumber
#	(gdb) (b)reak file.c:linenumber
#	(gdb) (r)un
#	(gdb) (s)tep (into)
#	(gdb) (n)ext
#	(gdb) (bt) backtrace
#	(gdb) (p)rint variable
#	(gdb) (q)uit
#	(gdb) (c)ontinue
#	(gdb) (D)elete breakpointnumber
#	(gdb) (i)nfo (b)read
#	(gdb) (i)nfo frame
#	(gdb) (i)nfo args
#	(gdb) (i)nfo locals
#
#	g++ broken.cpp -g -o broken
#	gdb broken core
#
#	(gdb) x /s argv[0]
#	(gdb) p /s (char*)(argv[0])
#	(gdb) (w)here



gdb --args stereo_calib.out -w 7 -h 7 imagelist.yml
#gdb --args stereo_calibrate imagelist.txt 12 16 3.0


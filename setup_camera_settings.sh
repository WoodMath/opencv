#!/bin/bash

echo "**********************************************************************************************"
v4l2-ctl --device=0 --list-ctrls
echo "**********************************************************************************************"
v4l2-ctl --device=1 --list-ctrls
echo "**********************************************************************************************"

#                     brightness (int)    : min=-128 max=127 step=1 default=0 value=0
#                       contrast (int)    : min=60 max=255 step=1 default=136 value=158
#                     saturation (int)    : min=0 max=255 step=1 default=150 value=128
#                            hue (int)    : min=-128 max=127 step=1 default=0 value=0
# white_balance_temperature_auto (bool)   : default=1 value=1
#                          gamma (int)    : min=72 max=500 step=1 default=100 value=286
#           power_line_frequency (menu)   : min=0 max=2 default=2 value=2
#      white_balance_temperature (int)    : min=2800 max=6500 step=1 default=4600 value=4600 flags=inactive
#                      sharpness (int)    : min=0 max=255 step=1 default=50 value=50
#         backlight_compensation (int)    : min=0 max=4 step=1 default=1 value=1
#                  exposure_auto (menu)   : min=0 max=3 default=1 value=3
#              exposure_absolute (int)    : min=2 max=20000 step=1 default=156 value=156 flags=inactive
#                 focus_absolute (int)    : min=0 max=200 step=1 default=0 value=0 flags=inactive
#                     focus_auto (bool)   : default=0 value=1


#	Based on code from
#		http://www.cyberciti.biz/faq/bash-for-loop/
#		http://tldp.org/LDP/abs/html/string-manipulation.html

BRIGHTNESS=0
CONTRAST=158
SATURATION=128
HUE=0
WHITE_BALANCE_TEMPERATURE_AUTO=0
GAMMA=286
POWER_LINE_FREQUENCY=2
WHITE_BALANCE_TEMPERATURE=4600
SHARPNESS=50
BACKLIGHT_COMPENSATION=0
EXPOSURE_AUTO=0
EXPOSURE_ABSOLUTE=156
FOCUS_ABSOLUTE=0
FOCUS_AUTO=0
for DEV in 0 1
do

echo "**********************************************************************************************"
	STR="v4l2-ctl --device=$DEV --set-ctrl brightness=$BRIGHTNESS"
	echo $STR
	$STR
echo "**********************************************************************************************"
	STR="v4l2-ctl --device=$DEV --set-ctrl contrast=$CONTRAST"
	echo $STR
	$STR
echo "**********************************************************************************************"
	STR="v4l2-ctl --device=$DEV --set-ctrl saturation=$SATURATION"
	echo $STR
	$STR
echo "**********************************************************************************************"
	STR="v4l2-ctl --device=$DEV --set-ctrl hue=$HUE"
	echo $STR
	$STR
echo "**********************************************************************************************"
	STR="v4l2-ctl --device=$DEV --set-ctrl white_balance_temperature_auto=$WHITE_BALANCE_TEMPERATURE_AUTO"
	echo $STR
	$STR
echo "**********************************************************************************************"
	STR="v4l2-ctl --device=$DEV --set-ctrl gamma=$GAMMA"
	echo $STR
	$STR
echo "**********************************************************************************************"	
	STR="v4l2-ctl --device=$DEV --set-ctrl power_line_frequency=$POWER_LINE_FREQUENCY"
	echo $STR
	$STR
echo "**********************************************************************************************"
	STR="v4l2-ctl --device=$DEV --set-ctrl white_balance_temperature=$WHITE_BALANCE_TEMPERATURE"
#	echo $STR
#	$STR
echo "**********************************************************************************************"
	STR="v4l2-ctl --device=$DEV --set-ctrl sharpness=$SHARPNESS"
	echo $STR
	$STR
echo "**********************************************************************************************"
	STR="v4l2-ctl --device=$DEV --set-ctrl backlight_compensation=$BACKLIGHT_COMPENSATION"
	echo $STR
	$STR
echo "**********************************************************************************************"
	STR="v4l2-ctl --device=$DEV --set-ctrl exposure_auto=$EXPOSURE_AUTO"
	echo $STR
	$STR
echo "**********************************************************************************************"
	STR="v4l2-ctl --device=$DEV --set-ctrl exposure_absolute=$EXPOSURE_ABSOLUTE"
#	echo $STR
#	$STR
echo "**********************************************************************************************"
	STR="v4l2-ctl --device=$DEV --set-ctrl focus_absolute=$FOCUS_ABSOLUTE"
#	echo $STR
#	$STR
echo "**********************************************************************************************"	
	STR="v4l2-ctl --device=$DEV --set-ctrl focus_auto=$FOCUS_AUTO"
	echo $STR
	$STR
echo "**********************************************************************************************"




	
done



echo "**********************************************************************************************"
v4l2-ctl --device=0 --list-ctrls
echo "**********************************************************************************************"
v4l2-ctl --device=1 --list-ctrls
echo "**********************************************************************************************"



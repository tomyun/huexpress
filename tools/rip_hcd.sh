#!/bin/bash
# Backup a PCEngine CDROM Game into a hcd archive.
# Copyright 2012-2013, Alexander von Gluck IV for HuExpress
# Released under the terms of the MIT license

function checkTools() {
	echo -n "Checking for required tools... "
	for var in "$@"; do
		echo -n "$var "
		which $var > /dev/null
		if [ $? -ne 0 ]; then
			echo "Error!"
			echo "$var isn't available! Please install first"
			exit 1
		fi
	done
	echo "OK!"
}

echo "======================================"
echo "HuExpress PCengine CD archival utility"
echo "Revision 0.2"
echo "======================================"
echo ""

if [ $# -ne 2 ]; then
	echo "Usage: $0 <cdrom> <destination>"
	exit 1
fi

if [ ! -b $1 ]; then
	echo "warning: $1 is not a block device!"
else
	echo "Using block device $1"
fi

if [ ! -e $2 ]; then
	# Doesn't exist? Make directory
	mkdir -p $2
else
	if [ ! -d $2 ]; then
		# Exists, but not a directory. error
		echo "$2 isn't a directory!"
		exit 1
	fi
	echo "Using destination directory $2"
fi

# Check for required tools...
checkTools cdrdao toc2cue bchunk oggenc

#read -p "What is the name of this game? " -e gameName
read -p "What is the ID of this game? " -e  gameID
#read -p "Who was the publisher of this game? " -e gamePublisher
#read -p "Is this game from Japan or USA? " -e gameCountry

cd $2
# Rip CD
echo "Examining CDROM2 game information..."
lastTrack=$(cdrdao disk-info --device /dev/sr0 2>/dev/null | grep "Last Track" | cut -d":" -f2 | tr -d ' ')
echo "Ripping CDROM2 image..."
cdrdao read-cd -v 0 --read-raw --device ${1} --datafile ${gameID}.bin ${gameID}.toc &> /dev/null
echo "Converting TOC to CUE..."
toc2cue ${gameID}.toc ${gameID}.cue &> /dev/null
# Break out tracks
echo "Breaking apart CD tracks..."
bchunk -w -s ${gameID}.bin ${gameID}.cue Track &> /dev/null
rm ${gameID}.bin ${gameID}.toc

hcdFile=${gameID}.hcd

# Generate a basic hcd

echo "Generating hcd metadata and encoding wav tracks..."
# TODO: Find information for this CD somehow and auto-populate
echo "[main]" > ${hcdFile}
echo "id=${gameID}" >> ${hcdFile}
echo "media=unknown" >> ${hcdFile}
echo "country=unknown" >> ${hcdFile}
echo "title=unknown" >> ${hcdFile}
echo "developer=unknown" >> ${hcdFile}
echo "release=unknown" >> ${hcdFile}
echo "price=unknown" >> ${hcdFile}
echo "genere=unknown" >> ${hcdFile}
echo "first_track=1" >> ${hcdFile}
echo "last_track=${lastTrack}" >> ${hcdFile}
echo "minimum_bios=1" >> ${hcdFile}
echo "" >> ${hcdFile}

track=1
for i in $(find . -name "*.wav" -or -name "*.ugh" -or -name "*.iso" | sort); do
        filename=$(echo $i | cut -d \/ -f 2)
        extension=$(echo $filename | cut -d . -f 2)
        basename=$(echo $filename | cut -d . -f 1)
        echo "[track${track}]" >> ${hcdFile}
        case $extension in
		"wav")
			echo "Track ${track}: Converting wav to ogg..."
			echo "type=AUDIO" >> ${hcdFile}
			oggenc -l "${gameID}" -N ${track} ${filename} &> /dev/null
			rm ${filename}
			filename="${basename}.ogg"
			extension="ogg"
			;;
		"ogg" | "mp3")
			echo "Track ${track}: $extension track."
			echo "type=AUDIO" >> ${hcdFile}
			;;
		"ugh")
			echo "Track ${track}: Code track."
			echo "type=CODE" >> ${hcdFile}
			mv "${filename}" "${basename}.iso"
			filename="${basename}.iso"
			extension="iso"
			;;
		"iso")
			echo "Track ${track}: Code track."
			echo "type=CODE" >> ${hcdFile}
			;;
		*)
			echo "Track ${track}: Warning: Unknown track!"
			echo "type=UNKNOWN" >> ${hcdFile}
			;;
        esac
        echo "filename=${filename}" >> ${hcdFile}
        track=$[track+1];
done;

#zip -c "PCEngine CD ${gameID}" -9 "${gameID}.zip" *
cd -
echo "Complete!"
echo "*Please* remember to edit ${hcdFile} to add additional metadata!"

echo 
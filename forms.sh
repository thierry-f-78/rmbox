#!/bin/sh
TMP=/tmp/g_$$
H=forms.h

# test du fichier
> $TMP
RET=$?
[ "x$RET" != "x0" ] && exit $RET

> $H
RET=$?
[ "x$RET" != "x0" ] && exit $RET

echo -n "#define NB_TILES " >> $H

export newline=1
export nb_tiles=0
export line=0
cat forms.dat | while read; do

	# jump if blank line
	blk=${REPLY// /}
	blk=${blk//	/}
	if [ "x${blk}" = "x" ]; then
		if [ "x$newline" = "x2" ]; then
			while [ $line -le 3 ]; do
				echo -n "			0, 0, 0, 0" 1>&2
				line=$[ $line + 1 ]
				if [ "x${line}" != "x4" ]; then
					echo "," 1>&2
				else
					echo 1>&2
				fi
			done
			echo "		}" 1>&2
			echo "	}," 1>&2
		fi
		newline=1
		line=0
		continue
	fi

	# get level
	lvl="${REPLY#level}"
	if [ "$lvl" -eq "$lvl" ] 2>/dev/null; then
		level=$lvl
		continue
	fi
	
	# get line
	if [ "x$newline" = "x1" ]; then
		newline=2
		nb_tiles=$[ $nb_tiles + 1 ]
		echo $nb_tiles
		echo "	{" 1>&2
		echo "		${level}," 1>&2
		echo "		{" 1>&2
	fi
	l="${REPLY}    "
	a="${l:0:1}"; [ "x${a}" = "xo" ] && a=1 || a=0
	b="${l:1:1}"; [ "x${b}" = "xo" ] && b=1 || b=0
	c="${l:2:1}"; [ "x${c}" = "xo" ] && c=1 || c=0
	d="${l:3:1}"; [ "x${d}" = "xo" ] && d=1 || d=0
	echo -n "			$a, $b, $c, $d" 1>&2
	line=$[ $line + 1 ]
	if [ "x${line}" != "x4" ]; then
		echo "," 1>&2
	else
		echo 1>&2
	fi

done 2>> $TMP | tail -1 >> $H

# ecriture des entetes
cat << EOF >> $H
const struct {
	int level;
	char desc[ 4 * 4 ];
} forms[NB_TILES] = {
EOF
cat $TMP >> $H
echo "};" >> $H

rm $TMP

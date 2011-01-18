#!/bin/bash
# prend les images en c et genere les headers

# var
H=images.h

# efface et cré le fichier destination
> $H
RET=$?
[ "x$RET" != "x0" ] && exit $RET

cat << EOF >> $H
#ifndef __IMAGES_H__
#define __IMAGES_H__

// images
EOF

# traite les images
for i in images/*.c
do
	# recupere le nom
	NAME=${i##*/}
	NAME=${NAME%%.c}

	# genere l'entree dans le .h
	echo "struct vimg ${NAME};" >> $H
done

cat << EOF >> $H

#endif
EOF

exit 0

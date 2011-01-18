#!/bin/bash
# prend le code C fournit par gimp
# et le convertit en code c qui va bien

# traite les images
# recupere le nom
NAME=${2##*/}
NAME=${NAME%%.c}

C1=/tmp/conv1_$$.c
C2=/tmp/conv2_$$.c
B1=/tmp/conv1_$$

# modifie le format des images
cat << EOF > $C1
#include <stdio.h>
#include "${PWD}/$NAME.c"
	
int main(void){
	int i, size;
	
	printf("//#include \"${PWD}/../structs.h\"\n"
          "struct vimg {\n"
          "   unsigned int width;\n"
          "   unsigned int height;\n"
          "   struct pixel_img * pixel_data;\n"
          "};\n"
          "struct pixel_img {\n"
          "   unsigned char b;\n"
          "   unsigned char g;\n"
          "   unsigned char r;\n"
          "   unsigned char a;\n"
          "};\n"
	       "struct pixel_img data_${NAME}[%d * %d] = {\n\t",
	       gimp_image.width,
	       gimp_image.height
	);
	
	size = gimp_image.width *
	gimp_image.height *
	gimp_image.bytes_per_pixel;
	
	for(i=0; i<size; i+=4){
		printf("0x%02x,0x%02x,0x%02x,0x%02x",
		       gimp_image.pixel_data[i+2],
		       gimp_image.pixel_data[i+1],
		       gimp_image.pixel_data[i],
		       gimp_image.pixel_data[i+3]);
		if(i+4!=size)printf(",");
		if(i%12==8)printf("\n\t");
	}
	printf("\n};\n");

	printf(
	       "struct vimg ${NAME} = {\n"
	       "	.width = %d,\n"
	       "	.height = %d,\n" 
	       "	.pixel_data = data_${NAME}\n"
	       "};\n",
	       gimp_image.width,
	       gimp_image.height
	);
}
EOF
${CC} -o $B1 $C1
$B1 > $C2
${CC} -p -g -c -o $1 $C2

rm $C1 $C2 $B1 >/dev/null 2>&1
exit 0

#!/bin/bash

frames=$(identify -format "%n\n" $1.gif | head -1)
frames=$(($frames - 1))
gm convert $1.gif -coalesce +adjoin $1-%d.png

i=0
for i in $(eval echo {0..$frames})
do
	xxd -i $1-$i.png > tmp$i
done

echo ""
echo "unsigned char* gif"$1"["$(($frames + 1))"] = {"
for i in $(eval echo {0..$frames})
do
	echo "__"$1"_"$i"_png,"
done
echo "};"

echo "unsigned int gif"$1"_len["$(($frames + 1))"] = {"
for i in $(eval echo {0..$frames})
do
	echo "__"$1"_"$i"_png_len,"
done
echo "};"

cat tmp* temp > $2/gif$1.h
rm *.png tmp* temp

for i in $(eval echo {0..$frames})
do
	sed -i -e "s/unsigned int __"$1"_"$i"_png_len/const unsigned int __"$1"_"$i"_png_len/" $2/gif$1.h
done
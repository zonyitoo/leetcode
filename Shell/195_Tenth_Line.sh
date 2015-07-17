# Read from the file file.txt and output the tenth line to stdout.

COUNT=`head -n 10 file.txt | wc -l`

if [[ $COUNT -ne "10" ]]; then
    echo "";
else
    head -n 10 file.txt | tail -n 1
fi


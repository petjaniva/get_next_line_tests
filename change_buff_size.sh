cd ..
sed -i 's/.*BUFF_SIZE.*/# define BUFF_SIZE = '"$1"'/' get_next_line.h

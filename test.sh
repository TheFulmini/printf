printf "this is a test \n"
make all 
gcc -Wall -Wextra -Werror ./main.c ./libftprintf.a && ./a.out
printf "\n"


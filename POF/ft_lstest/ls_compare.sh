./ft_ls $1 $2 $3 $4 |cat -e >& /tmp/myout001001;
ls $1 $2 $3 $4 $5 |cat -e >& /tmp/lsout001001;
echo "\n\x1B[44m                                                          \x1B[0m"
echo "\x1B[44m--------- \x1B[0m\x1B[96m TEST DES OUTPUTS DE VOTRE FT_LS SUR LS \x1B[0m\x1B[44m--------\x1B[40m"
echo "\x1B[44m                                                          \x1B[0m\n"
./checker.exe 1;

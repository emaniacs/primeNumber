app=./prime
loop=1

# comparing output number from generate with nth
for prime in $(${app} -g 20); do
    echo -n "${prime} == "; ${app} -n ${loop}
    loop=$(expr ${loop} + 1)
done

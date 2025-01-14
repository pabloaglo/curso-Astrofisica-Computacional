reset

set terminal png
set output "Bessel.png"
set title "Funciones de Bessel"
set xlabel "X"
set xrange [0:20]
set yrange [-0.4:1]
set grid

plot "Bessel.dat" u 1:2 w l lw 2 dt 1 lc rgb "red" t "J_0(x)",\
     "Bessel.dat" u 1:3 w l lw 2 dt 2 lc rgb "green" t "J_1(x)",\
     "Bessel.dat" u 1:4 w l lw 2 dt 4 lc rgb "blue" t "J_2(x)"

reset
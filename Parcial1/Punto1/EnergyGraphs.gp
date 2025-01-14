reset

set terminal png size 500,500 font 14
set output "grafica_error_energia_1000.png"

set size square

set title "Error en la energía"
set xlabel "t[s]"
set ylabel "Error %"

set grid

plot "Eulergia.dat" u 1:(100*$3) w l lw 2 lc rgb "red" t "Eulergy con 1000 puntos",\
     "DKD_energia_1.dat" u 1:(100*$3) w l lw 2 lc rgb "blue" t "DKD con 1000 puntos",\

reset

reset

set terminal png size 500,500 font 14
set output "grafica_error_energia_20.png"

set size square

set title "Error en la energía"
set xlabel "t[s]"
set ylabel "Error %"

set grid

plot "Eulergia20.dat" u 1:(100*$3) w l lw 2 lc rgb "red" t "Eulergy con 20 puntos",\
     "DKD_energia_2.dat" u 1:(100*$3) w l lw 2 lc rgb "blue" t "DKD con 20 puntos",\

reset

reset 

set terminal png size 500,500 font 14
set output "parabolico.png"

set size square

set title "Tiro parabólico"
set xlabel "x [m]"
set ylabel "y [m]"

set grid

plot "parabolicoEuler20.dat" u 2:3 w l lw 2 lc rgb "red" t "Eulergy con 20 puntos",\
     "parabolicoEuler1000.dat" u 2:3 w l lw 2 lc rgb "blue" t "Eulergy con 1000 puntos",\
	 "parabolicoDKD2.dat" u 2:3 w l lw 2 lc rgb "green" t "DKD con 20 puntos",\
	 "parabolicoDKD1.dat" u 2:3 w l lw 2 lc rgb "yellow" t "DKD con 1000 puntos"
	 
reset
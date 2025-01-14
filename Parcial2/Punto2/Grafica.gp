reset

set terminal pngcairo size 800,800 enhanced font "Verdana,12"
set output "Particulas.png"
set title "Distribución de partículas al azar"
set xlabel "X"
set xrange [0:100]
set ylabel "Y"
set yrange [0:100]

plot "particuloides.dat" u 2:3 w p pt 7 ps 1.5 lc rgb '0x7438ff' t "Particulas",\
	 "particulas_vecinas.dat" u 1:2 w p pt 7 ps 1 lc rgb '0x38ff7e' t "Vecinas",\
	 "particulas_vecinas.dat" every ::0::0 u 1:2 w p pt 7 ps 1 lc '0xffaa4f' t "Interes"
	 
reset
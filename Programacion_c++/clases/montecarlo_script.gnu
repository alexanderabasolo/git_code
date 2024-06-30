set size ratio -1
set xrange [0:1]
set yrange [0:1]
set key outside right
plot 'montecarlo_data.dat' using 1:2:($3 == 1 ? 1 : 0) with points pointtype 7 lc variable title 'Dentro del Círculo'

set terminal png
set output 'montecarlo_plot.png'
plot 'montecarlo_data.dat' using 1:2:(($3 == 1) ? 7 : 5) with points palette pointsize 1.5 pointtype 7 title 'Dentro del círculo', '' using 1:2:(($3 == 2) ? 3 : 1) with points palette pointsize 1.5 pointtype 3 title 'Fuera del círculo'

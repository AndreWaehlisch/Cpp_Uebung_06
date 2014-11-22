set terminal png
set output 'handlungsreisender.png'
set style data linespoints
set title 'Weg des Handlungsreisenden'
set xlabel 'x'
set ylabel 'y'
set xrange [0:6]
set yrange [-1:4]
plot 'handlungsreisender.txt'

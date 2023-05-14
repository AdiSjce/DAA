set xlabel "min{m,n}"
set ylabel "t"
plot 'GCDC.txt' u 3 : 4 w l ti"Ecuclid's",'GCDC.txt' u 3 : 5 w l ti"Subtraction",'GCDC.txt' u 3 : 6 w l ti"Consecutive Interger" 
set term png
set output "GCD.png"
replot
set term x11
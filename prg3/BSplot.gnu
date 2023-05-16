set xlabel "n"
set ylabel "t"
plot "BSBest.txt" w l ti "Best Case", "BSWorst.txt" w l smooth bezier ti "Worst Case", "BSAvg.txt" w l ti "Average Case"
set term png
set output "BSG.png"
replot
set term x11
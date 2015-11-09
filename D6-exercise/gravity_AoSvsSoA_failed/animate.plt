set term gif animate
set output "animate.gif"
stats 'output.dat' nooutput
set style line 2 lc rgb 'red' pt 7
set xrange[STATS_min_x: STATS_max_x]
set yrange[STATS_min_y: STATS_max_y]
do for [i=1:int(STATS_blocks)] {
  plot 'output.dat' index (i-1)  using 1:2 with points ls 2 
}

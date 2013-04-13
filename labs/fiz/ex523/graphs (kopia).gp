set terminal postscript eps enhanced 22        # old epsf2
set key right center
set output "r-ang1.eps"
set title "Radius of first circle depending on measured angle." 
set xlabel "Angle [{/Symbol \260}]" font "Helvetica,24"
set ylabel "Radius [10^{-3} m]" 
f(x) = m*x + b
fit f(x) 'data.tab' using 1:2 via m,b
plot [10:][10:] 'data.tab' using 1:2 w points pt 1 ps 2 lc 7 title 'measured points', 'data.tab' using 1:2:(1) w xerrorbars lc 7 ps 0 title 'uncertainty', f(x) title 'linear approximation'
set output "r-ang2.eps"
set title "Radius of second circle depending on measured angle." 
set xlabel "Angle [{/Symbol \260}]" font "Helvetica,24"
set ylabel "Radius [10^{-3} m]" 
fit f(x) 'data.tab' using 3:4 via m,b
plot [20:][20:] 'data.tab' using 3:4 w points pt 1 ps 2 lc 7 title 'measured points', 'data.tab' using 3:4:(1) w xerrorbars lc 7 ps 0 title 'uncertainty', f(x) title 'linear approximation'

        sum = 0
        PI = 3.1415
        write (*, *) 'Angle'
        read (*, *) x
        x = x * PI / 180
        term = x
        sum = term
        i = 1
   10   if ( abs(term) .gt. 0.001 ) then
           i = i + 1
           term = term * (-1) * x * x / ((2*i - 1) * (2*i-2))
           sum = sum + term
           goto 10
        end if
        write(*, *) 'Sum of series', sum
        pause
        stop
        end

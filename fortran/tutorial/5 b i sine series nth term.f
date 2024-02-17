        sum = 0
        PI = 3.1415
        write (*, *) 'Angle and Term'
        read (*, *) x, it
        x = x * PI / 180
        term = x
        sum = term
        do 10 i = 2, it
           term = term * (-1) * x * x / ((2*i - 1) * (2*i-2))
           sum = sum + term
  10    continue
        write(*, *) 'Sum of series', sum
        pause
        stop
        end

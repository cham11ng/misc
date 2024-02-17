        !integer n
        i=1
        write (*, *) 'N'
        read (*, *) n
   1    r = i * n
        write (*, *) n, 'x ', i, '=', r
        i = i + 1
        if(i - 10) 1, 1, 2
   2    pause
        stop
        end


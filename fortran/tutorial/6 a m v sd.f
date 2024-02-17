        integer x(20)
        write (*, *) 'Number of Number'
        read (*, *) in
        write (*, *) 'Data''s of X'
        read (*, *) (x(i), i = 1, in)
        sum = 0
        sum2 = 0
        do 20 i = 1, in
           sum = sum + x(i)
           sum2 = sum2 + x(i)**2
   20   continue
        zmean = sum / in
        vari = sum2 / in - zmean**2
        sd = sqrt(vari)
        write (*, *) 'Mean =', zmean, ' Variance =', vari, ' S.D. =', sd
        pause
        stop
        end


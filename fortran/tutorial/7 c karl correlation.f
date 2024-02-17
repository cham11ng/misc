        integer x(20), y(20)
        write (*, *) 'How many Values of X and Y'
        read (*, *) in
        write (*, *) 'Data''s of X'
        read (*, *) (x(i), i=1, in)
        write (*, *) 'Data''s of Y'
        read (*, *) (y(i), i=1, in)
        
        xsum = 0
        ysum = 0

        do 20 i = 1, in
           xsum = xsum + x(i)
           ysum = ysum + y(i)
 20     continue
 
        xm = xsum / in
        ym = ysum / in
        
        sum = 0
        sum2 = 0
        sum3 = 0

        do 30 i = 1, in
           sum = sum + (x(i)-xm) * (y(i)-ym)
           sum2 = sum2 + (x(i)-xm)**2
           sum3 = sum3 + (y(i)-ym)**2
 30     continue
 
        write (*, *) 'Correlation', sum/sqrt(sum2*sum3)
        pause
        stop
        end
        

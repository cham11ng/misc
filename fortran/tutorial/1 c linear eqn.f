        REAL a1, a2, b1, b2, c1, c2, x, y, d
        write (*, *) ' Solve Linear Equation '
        
        write (*, *) 'Enter coefficients of 1st equation'
        read (*, *) a1, b1, c1
        write (*, *) 'Enter coefficients of 2nd equation'
        read (*, *) a2, b2, c2
        d = a2*b1 - a1*b2
        if ( d .eq. 0) stop
        x = (c2*b1 - c1*b2) / d
        y = (a2*c1 - a1*c2) / d
        write (*, *) 'Required values are x =', x, ' y =', y
        pause
        stop
        end
        
        

        PI = 3.1415926
        write (*, *) 'Two Sides of Triangle and Angle Between Them '
        read (*, *) a, b, alpha
        c = sqrt( a**2 + b**2 - 2 * a * b * cos(alpha*PI/180))
        write (*, *) 'Third Side of Triangle =', c
        pause
        stop
        end
        
        

        real a, b, c, det, r, i
        write (*, *) 'Coefficients of Quadratic Equation'
        read (*, *) a, b, c
        det = b**2 - 4*a*c
        r = - b / (2 * a)
        i = sqrt(abs(det)) / (2 * a)
        if(det) 1, 2, 3

    3   write(*, *) ' Root''s are Real and Unequal '
        write(*, *) ' x1 =', r+i, ' x2 =', r-i
        pause
        stop
        
    2   write(*, *) ' Root''s are Real and Equal '
        write(*, *) ' X =', r
        pause
        stop

    1   write(*, *) ' Root''s are Imaginary '
        write(*, *) ' x1 =', r, ' +', i, 'i'
        write(*, *) ' x2 =', r, ' -', i, 'i'
        pause
        stop
        
        end


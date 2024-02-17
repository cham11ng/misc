        REAL A, B, C, S, area

        write(*, *) 'Enter Side of Triangle'
        read (*, *) A, B, C
        
        if((A+B .le. C) .or. (B+C .le. A) .or. (C+A .le. B)) goto 1

        S = (A + B + C) / 2.0
        area = sqrt(s * (s - a) * (s - b) * (s - c))
        
        write(*, *) 'Area : ', area
        PAUSE
        STOP
        
  1     write (*, *) ' Can''t Solve '
        PAUSE
        STOP
        END

        write (*, *) 'Range'
        read ( *, *) lwr, upr
        do 7 i = lwr, upr
           do 5 j = 2, upr
             if(mod(i, j) .eq. 0) goto 6
  5        continue
  6        if( i .eq. j ) write(*, *) j
  7     continue
        pause
        stop
        end


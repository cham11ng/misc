        integer year
        write( *, *) 'Enter Year'
        read(*, *) year
        if(mod(year, 400) .eq. 0) then
            write(*, *) 'Leap Year'
        else if (mod(year, 4) .eq. 0 .and. mod(year, 100) .ne. 0) then
            write(*, *) 'Leap Year'
        else
            write(*, *) 'Not Leap Year'
        endif
        
        stop
        end
        

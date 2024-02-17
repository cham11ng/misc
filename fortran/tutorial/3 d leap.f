        integer year
        write (*, *) ' Year '
        read (*, *) year
        if ( mod(year, 4) .eq. 0 .and. mod(year, 100) .ne. 0 ) then
           write (*, *) year, ' is Leap Year'
        else if ( mod(year, 400) .eq. 0 ) then
           write (*, *) year, ' is Leap Year'
        else
           write (*, *) year, ' is not Leap Year'
        end if
        pause
        stop
        end

           


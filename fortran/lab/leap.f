        write( *, *) 'Enter Year'
        read(*, *) i

        if( MOD(i, 4) .eq. 0 ) then
            if( MOD(i,100) .eq. 0 ) then
                if( MOD(i, 400) .eq. 0 ) then
                    write(*, *) 'Leap Year'
                else
                    write(*, *) 'Not Leap Year'
                endif
            else
                 write(*, *) 'Leap Year'
            endif
        else
            write(*, *) 'Not Leap Year'
        endif
        
        stop
        end


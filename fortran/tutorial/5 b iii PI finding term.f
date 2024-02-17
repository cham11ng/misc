        sum = 0
        write (*, *) ' PI series '
        sum = 1
        i=2
 20     if (4*sum .ne. 3.1415) then
           sum = sum + (-1.0)**(i+1) / (i*2 - 1)
           i = i + 1
           goto 20
        end if

        write(*, *) 'i ', i-1
        pause
        stop
        end


        write (*, *) 'Total UNIT '
        read (*, *) iunit
        charge = 80
        if(iunit .gt. 20) then
            if(iunit .gt. 250) then
               charge = charge + (250-20) * 7.50
               if(iunit .gt. 300) then
                   charge = charge + (300-250) * 10.30
                   charge = charge + (iunit-300) * 15.50
               else
                   charge = charge + (iunit-250) * 10.30
               end if
            else
               charge = charge + (iunit-20) * 7.5
            end if
        end if
        write(*, *) 'Total Charge : ', charge
        pause
        stop
        end
               


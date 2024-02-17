        isum = 0
        write (*, *) 'Number'
        read (*, *) inum
        
        do 20 i = 1, inum-1
           if(mod(inum, i) .eq. 0) isum=isum+i
  20    continue
        if(isum .eq. inum) then
            write(*, *) inum, ' is perfect number'
        else
            write(*, *) inum, ' is not perfect number'
        endif
        pause
        stop
        end


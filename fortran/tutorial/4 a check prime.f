        icount=0
        write (*, *) 'Number'
        read ( *, *) inum
        do 5 i = 2, inum
           if(mod(inum, i) .eq. 0) goto 6
  5     continue
  6     if( inum .eq. i ) then
            write(*, *) 'Prime'
        else
            write(*, *) 'Not Prime'
        end if
        stop
        end
        

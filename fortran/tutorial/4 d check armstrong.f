        isum = 0
        write (*, *) 'Number'
        read (*, *) inum
        itemp = inum
  10    if(inum .ne. 0) then
             irem = mod(inum, 10)
             isum = isum + irem**3
             inum = inum / 10
             goto 10
        end if
        
        if (itemp .eq. isum) then
             write (*, *) itemp, ' is ArmStrong'
        else
             write (*, *) itemp, ' is Not Armstrong'
        end if
        
        pause
        stop
        end
              
             


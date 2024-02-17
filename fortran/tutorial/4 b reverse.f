        isum = 0
        write (*, *) 'Number'
        read (*, *) inum
        
   30   if(inum .ne. 0) then
                irem = mod(inum, 10)
                isum = isum * 10 + irem
                inum = inum / 10
                goto 30
        end if

        write(*, *) 'Reversed Number :', isum
        stop
        end

                

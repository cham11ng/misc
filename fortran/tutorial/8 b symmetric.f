        integer a(10, 10)
        flag = 1
        write (*, *) 'Check symmetric or not'
  5     write (*, *) ' Order of Matrix '
        read (*, *) m, n
        if(m .ne. n) then
             write(*, *) 'Matrix must be Square Matrix'
             goto 5
        end if
        write (*, *) 'Values'
        read (*, *) ((a(i,j), i = 1, m), j = 1, n)
        do 20 i = 1, m
           do 20 j = 1, n
           if(a(i, j) .ne. a(j, i)) flag = 0
 20     continue
        if(flag .eq. 1) then
           write (*, *) 'is Symmetric'
        else
           write (*, *) 'is not Symmetric'
        end if
        pause
        stop
        end

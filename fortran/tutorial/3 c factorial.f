        ifact = 1
        write (*, *) 'Number'
        read (*, *) inum
        
        do 10 i = 1, inum
           ifact = ifact * i
   10   continue

        write(*, *) 'Factorial is', ifact
        pause
        stop
        end

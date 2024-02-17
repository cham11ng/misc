        sum = 0
        write (*, *) ' e series '
        write (*, *) ' Value of x and term '
        read (*, *) x, it
        term = 1
        sum = term
        do 20 i = 2, it
           term = term * x / (i - 1)
           sum = sum + term
 20     continue
        write(*, *) 'sum of e series ', sum
        pause
        stop
        end
        

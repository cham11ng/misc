        sum = 0
        write (*, *) ' PI series '
        write (*, *) ' term '
        read (*, *) it
        sum = 1
        do 20 i = 2, it
           sum = sum + (-1.0)**(i+1) / (i*2 - 1)
 20     continue
        write(*, *) 'sum of PI series ', sum*4
        pause
        stop
        end

        !try 10200

        integer a(20), b(20)
        sum=0
        write (*, *) 'Number of Number'
        read (*, *) in
        write (*, *) 'Data''s of A'
        read (*, *) (a(i), i = 1, in)
        write (*, *) 'Data''s of B'
        read (*, *) (b(i), i = 1, in)
        do 20 i = 1, in
           sum = sum + a(i) * b(i)
   20   continue
        write (*, *) 'Inner Product', sum
        pause
        stop
        end
        

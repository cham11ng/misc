        integer i, flag, lower, upper
        write( *, *) 'Lower Limit & Upper Limit'
        read ( *, *)  lower, upper
        

        do 50 n = lower, upper, 1
           flag=1
           do 100 i = 2, n-1, 1
              if(mod(n, i) .eq. 0) then
                   flag=0
                   goto 10
               end if
  100          continue
  10       if (flag .eq. 1) write(*, *) n
  50    continue
        stop
        end
               
        
                   
        
        

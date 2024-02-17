        integer sum
        do 50 n = 1, 100, 1
           sum=0
           do 100 i = 1, n-1, 1
              if(mod(n, i) .eq. 0) then
                   sum = sum + i
               end if
  100          continue
           if (n .eq. sum) write(*, *) i
  50    continue
        stop
        end





